#include "Function.h"


void initEncodeMode()
{
	
}
void makeResource(const wstring _dict_path, const wstring _index_path)
{
	
	wifstream f_dict(_dict_path, ios::in | ios::binary);
	ofstream f_index(_index_path, ios::out | ios::binary);

	/*
	Example read and write hex
	string s = "BA";
	stringstream f(s);
	int n;
	f >> hex >> n; //then n = hex_to_decimal("BA") = 186
	f << hex << 186; //write decimal_to_hex(186) = "BA"
	*/

	f_dict.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	//f_index.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	if (f_dict.is_open() && f_index.is_open())
	{
		unsigned long int pos1, pos2;
		string tmp;		//temp to skip
		wstring convert;
		wchar_t signal;	//store a character
		wchar_t* word = new wchar_t[1024];
		
		//int count = 0;
		while (!f_index.eof() && !f_dict.eof() && f_dict.good())
		{
			signal = 0;
			do
			{
				f_dict >> noskipws >> signal;
			} while (signal != '@' && !f_dict.eof());
			pos1 = f_dict.tellg();
			
			
			f_dict.getline(word, 1024,L'\n');
			pos2 = wcslen(word);
			
			//chuẩn hóa từ
			for (int i = 0; i < wcslen(word) - 1;i++)
			if (word[i] == L' '&& word[i + 1] == L'/')
			{
				word[i] = 0;
				break;
			}

			signal = 0;
			
			do
			{
				f_dict >> noskipws >> signal;
				pos2++;
			} while (signal != '@' && !f_dict.eof());
			
			f_dict.seekg(-1, ios::cur);
			
			//convert wchar_t* to string
			convert = wstring(word);
			tmp = string(convert.begin(), convert.end());

			f_index << tmp << "\t" << hex << pos1 << "\t" << hex << pos2 << endl;
			
			wcout << word<<"\t" << hex << pos1 << "\t";
			wcout << hex << pos2 << endl;

		}
	}
	f_index.close();
	f_dict.close();
}

void showContents(const string pos1, const string pos2, const wstring _dict_path)
{

	wifstream f_dict(_dict_path, ios::in | ios::binary);

	f_dict.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	if (f_dict.is_open())
	{
		unsigned long int p1, p2;
		stringstream sstream(pos1);
		sstream >> hex >> p1;
		sstream = stringstream(pos2);
		sstream >> hex >> p2;
		f_dict.seekg(p1, ios::beg);
		wstring mean=L"";
		wchar_t c;
		for (int i = 0; i < p2; i++)
		{
			f_dict >> noskipws >> c;
			mean += c;
		}
		wcout << mean;
		wofstream fo("test.txt", ios::out | ios::binary);
		fo.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
		for (int i = 0; i < p2; i++)
		{
			fo << wchar_t(mean[i]) << L"\t" << int(mean[i]) << endl;
		}
		fo.close();
	}
	f_dict.close();
}
