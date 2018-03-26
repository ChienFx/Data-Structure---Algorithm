#include "Dictionary.h"


Dictionary::Dictionary()
{
	m_btree = NULL;
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);

	m_huff.Extract(PATH_DICTIONARY_ENCRYPTED_FILE, PATH_HUFF_FREQ_TABLE, PATH_DICTIONARY_TEXT_FILE);

	if (this->loadData() == false)
	{ 
		cout << "- Missing file resourece!";
		exit(0);
	}
	f_dict.open(PATH_DICTIONARY_TEXT_FILE, ios::in | ios::binary);
	f_dict.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	
}


Dictionary::~Dictionary()
{
	f_dict.close();
	_setmode(_fileno(stdout), _O_TEXT);
	_setmode(_fileno(stdin), _O_TEXT);
	remove(PATH_DICTIONARY_TEXT_FILE);
	if (m_btree)
		delete m_btree;
}


bool Dictionary::loadData()
{
	m_btree = new BTree(B_TREE_DEGREE);
	ifstream fo(PATH_INDEX_TEX_FILE, ios::in | ios::binary);
	if (fo.is_open())
	{
		int pos1, pos2;
		string str, word, offset, length;
		while (!fo.eof())
		{
			getline(fo, str);
			pos1 = str.find_first_of('\t');
			pos2 = str.find_last_of('\t');
			word = str.substr(0, pos1);
			offset = str.substr(pos1 + 1, pos2-pos1-1);
			length = str.substr(pos2 + 1, str.size());
			Data k = Data(word, offset, length);
			m_btree->insert(k);
			wcout << wstring(str.begin(),str.end()) << endl;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Dictionary::show()
{
	m_btree->traverse();
}
void Dictionary::search(const string word)
{
	Data key = Data(word, "", "");
	Data result = m_btree->search(key);
	
	if (result.word.empty())
	{

		wcout << L"Không tìm thấy nghĩa."<<endl;
	}
	else if (f_dict.is_open())
	{
		unsigned long int p1, p2;
		stringstream sstream(result.offset);
		sstream >> hex >> p1;
		sstream = stringstream(result.length);
		sstream >> hex >> p2;
		f_dict.seekg(p1, ios::beg);
		wstring mean = L"";
		wchar_t c;
		for (int i = 0; i < p2; i++)
		{
			f_dict >> noskipws >> c;
			mean += c;
		}
		wcout << mean;
		/*wofstream fo("test.txt", ios::out | ios::binary);
		fo.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
		for (int i = 0; i < p2; i++)
		{
			fo << wchar_t(mean[i]) << L"\t" << int(mean[i]) << endl;
		}
		fo.close();*/
	}
	//f_dict.close();
	
}