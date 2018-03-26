#include "StaticHuffman.h"

StaticHuffman::StaticHuffman()
{
//	m_str_data = NULL;
	m_root = NULL;
}

StaticHuffman::~StaticHuffman()
{
	this->releaseAll();
}

void StaticHuffman::releaseAll()
{
	if (m_root != NULL)
	{
		delete m_root;
		m_root = NULL;
	}
	m_amount_char = 0;
	m_bit_table.clear();
	m_freq_table.clear();
	//if (m_str_data != NULL)
	//{
	//	delete m_str_data;
	//	m_str_data = NULL;
	//}
}

//Hàm đọc văn bản cần nén vào bộ nhớ
//Input: đường dẫn file chứa văn bản
//Output: true, false(đường dẫn sai)
//bool StaticHuffman::loadData(const string _path)
//{
//	bool flag = true;
//	unsigned long length;
//	wifstream fi(_path, ios::binary);
//	
//	//encode utf-8 mode
//	fi.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
//
//	if (fi.is_open())
//	{
//		wstring str = L"";
//		wchar_t c;
//		while (!fi.eof())
//		{
//			//filein.read(&c, 1);
//			fi >> noskipws >> c;
//			str += c;
//			//wcout << c;
//		}
//		str.resize(str.size() - 1);
//		
//		m_str_data = wcsdup(str.c_str());
//
//	}
//	else
//		flag = false;
//	fi.close();
//	return flag;
//}
//
//bool StaticHuffman::buildFrequencyTable()
//{
//	if (m_str_data == NULL)
//	{
//		return false;
//		m_amount_char = 0;
//	}
//	int n = wcslen(m_str_data);
//
//	int i, j;
//
//	//tạo bảng tần số luu vào vector m_freq_table
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m_freq_table.size(); j++)
//		{
//			if (m_str_data[i] == m_freq_table[j]->c)
//			{
//				m_freq_table[j]->freq++;
//				break;
//			}
//		}
//
//		if (j == m_freq_table.size())
//		{
//			m_freq_table.push_back(new Node(m_str_data[i]));
//		}
//	}
//	//Sắp xếp lại bảng tần số (tăng dần)
//	for (i = 0; i < m_freq_table.size() - 1; i++)
//	{
//		for (int j = i + 1; j < m_freq_table.size(); j++)
//		{
//			//ưu tiên so sánh tần số trước, nếu 2 tần số bằng nhau thì sắp theo thứ tự chữ cái
//			if (
//				(m_freq_table[i]->freq > m_freq_table[j]->freq) || 
//				(m_freq_table[i]->freq == m_freq_table[j]->freq && ((m_freq_table[i]->c > m_freq_table[j]->c)))
//				)
//			{
//				Node* temp = m_freq_table[i];
//				m_freq_table[i] = m_freq_table[j];
//				m_freq_table[j] = temp;
//			}
//		}
//	}
//	m_amount_char = m_freq_table.size();
//	return true;
//}

bool StaticHuffman::loadFrequencyTable(const string _freq_path)
{
	ifstream fi(_freq_path, ios::in | ios::binary);
	if (fi.is_open())
	{
		string str;
		stringstream sstream;
		wchar_t c;
		int t;
		unsigned long freq;
		while (!fi.eof())
		{
			getline(fi, str);
			sstream = stringstream(str);
			sstream >> hex >> t;
			sstream >> hex >> freq;
			c = wchar_t(t);
			//wcout << c << " " << freq<<endl;
			m_freq_table.push_back(new Node(c,freq));
		}
		m_amount_char = m_freq_table.size();
		fi.close();
		return true;
	}
	else
	{
		fi.close();
		return false;
	}
}
//Hàm tạo cây huffman từ bảng tần số
//Input: 
//Output: true nếu thành công, false thất bại (dữ liệu rỗng)
bool StaticHuffman::buildHuffmanTree()
{
	if (m_amount_char == 0)
		return false;

	Node *x,*y,*z = NULL;
	
	while (m_freq_table.size() > 1)//den khi bang chi con 1 node thi dung
	{
		z = new Node(-1);//node z ko chua chuoi
		//chon 2 node co trong so thap nhat (bang sap xep tang dan)
		x = m_freq_table[0];
		y = m_freq_table[1];
		
		z->left = x;//quy uuoc not co trong so nho hon nam ben trai
		z->right = y;
		z->freq = x->freq + y->freq;
		
		//Xoa x, y khoi bang tan so
		m_freq_table.erase(m_freq_table.begin(), m_freq_table.begin() + 2);//xoas 2 node dau ra khoi bang
		

		//Them z vao bang (đúng thứ tự->tư tưởng insertion)
		m_freq_table.resize(m_freq_table.size()+1);
		int i = 0;
		while ((i < m_freq_table.size() - 1) && (m_freq_table[i]->freq < z->freq))
			i++;

		for (int j = m_freq_table.size() - 1; j >= i + 1; j--)
			m_freq_table[j] = m_freq_table[j - 1];
		m_freq_table[i] = z;
	}
	m_root = m_freq_table[0];
	return true;
}


void StaticHuffman::buildBitTable()
{
	if (m_root==NULL || m_amount_char == 0)
		return;

	m_bit_table.resize(1);
	while(!m_root->used)
	{
		printCode(m_root);
	}
	m_bit_table.resize(m_bit_table.size() - 1); // xoas node cuoi cung bi du ra
	
	//Sắp xếp lại bảng bit(tăng dần)
	for (int i = 0; i < m_bit_table.size() - 1; i++)
	{
		for (int j = i + 1; j < m_bit_table.size(); j++)
		{
			//ưu tiên so sánh tần số trước, nếu 2 tần số bằng nhau thì sắp theo thứ tự chữ cái
			if (m_bit_table[i].c > m_bit_table[j].c)
			{
				Bit temp = m_bit_table[i];
				m_bit_table[i] = m_bit_table[j];
				m_bit_table[j] = temp;
			}
		}
	}
}

void StaticHuffman::printCode(Node*&p)
{
	if (p == NULL)
		return;
	
	if (!p->left && !p->right)//node la
	{
		m_bit_table[m_bit_table.size() - 1].c = p->c;
		p->used = true;
		m_bit_table.resize(m_bit_table.size() + 1);
		return;
	}
	else// if (!p->right->used || !p->left->used)
	{
		if (p->right && !p->right->used)
		{
			m_bit_table[m_bit_table.size()-1].bit += '1';
			printCode(p->right);
		}
		else if (p->left && !p->left->used)
		{
			m_bit_table[m_bit_table.size() - 1].bit += '0';
			printCode(p->left);
		}
		else
		{
			p->used = true;
			//huyr dudwong di hien tai
			m_bit_table[m_bit_table.size() - 1].bit = "";
		}
	}
}

//chuyển bảng bit thành string để dùng lúc giải nén, ví dụ: Â =001, Đ = 101 -> ÂĐĐ = 001Â101Đ101Đ (lưu dạng bit<16>)
/*string StaticHuffman::convertBitTableToString()
{
	string str = "";
	encryptTree(m_root,str);
	return str;
}*/

//void StaticHuffman::encryptTree(Node* curr, string &bitTree)
//{
//	if (curr != NULL)
//	{
//		// Nếu node là lá
//		if (curr->left == NULL && curr->right == NULL)
//		{
//			bitTree += '1';
//			bitset<16> bitSq(curr->c);
//			bitTree += bitSq.to_string();
//		}
//		// Ngược lại
//		else
//		{
//			bitTree += '0';
//			encryptTree(curr->left,bitTree);
//			encryptTree(curr->right,bitTree);
//		}
//	}
//}

string StaticHuffman::convertWStringToEncryptCode(const wchar_t* text)
{
	string str = "";
	unsigned long n = wcslen(text);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_amount_char;j++)
		if (text[i] == m_bit_table[j].c)
		{
			str += m_bit_table[j].bit;
			break;
		}
	}
	return str;
}

string convertBitStringToCharString(string _source)
{
	char c;
	string output = "";
	while (_source.size() > 8)
	{
		bitset<8> bits(_source);
		c = char(bits.to_ulong());
		output += c;
		_source.erase(0, 8);
	}
	int addBit = 8 - _source.size();
	//for (int i = 0; i < addBit; i++)
		_source.insert(_source.end(),addBit,'0');
	bitset<8> bs(_source);
	c = char(bs.to_ulong());
	output += c;
	return output;
}

void StaticHuffman::Compress(const string _input_path, const string _freq_table_path, const string _output_path,bool utf8_mode)
{
	this->releaseAll();
	this->loadFrequencyTable(_freq_table_path);
	this->buildHuffmanTree();
	this->buildBitTable();

	ofstream fo(_output_path, ios::out | ios::binary);
	wifstream fi(_input_path, ios::in | ios::binary);
	if (utf8_mode==true)
		fi.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (fo.is_open() && fi.is_open())
	{
		int size_byte = 2048;
		wchar_t*text = new wchar_t[size_byte+1];
		string bit_str="";
		string bit_odd="";//lưu phần thừa của bit_str (bộ 8 bit)
		string encrypt = "";
		wchar_t c;
		int addBit = 0;
		fo<< (char)addBit;
		while (fi.good())
		{
			for (int i = 0; i < size_byte; i++)
				text[i] = '\0';

			fi.read(text, size_byte);
			text[size_byte] = 0;
			bit_str = bit_odd + convertWStringToEncryptCode(text);
			addBit = bit_str.size() % 8;
			bit_odd = bit_str.substr(bit_str.size() - addBit, addBit);
			bit_str.erase(bit_str.size() - addBit, addBit);//
			encrypt = convertBitStringToCharString(bit_str);
			//phải ghi đủ str_encrypt.size() ki tu trong chuoi, có thể là \0 giữa chuỗi nên không dùng f << str_en
			for (int i = 0; i < encrypt.size(); i++)
				fo << (char)encrypt[i];
		}
		delete[]text;
		encrypt = convertBitStringToCharString(bit_odd);
		for (int i = 0; i < encrypt.size(); i++)
			fo << (char)encrypt[i];
		
		addBit = encrypt.size()*8 - bit_odd.size();
		fo.seekp(0, 0);
		fo<< (char)addBit;
	}
	fi.close();
	fo.close();
	this->releaseAll();
}

//================================EXTRACTION====================================
string StaticHuffman::readEncryptFile(const string _input_path)
{
	ifstream fi(_input_path, ios::binary);
	char c;
	string str_bit_data = "";
	//đọc tất cả các kí tự trong file, ko chỉ dừng ở kí tự \0
	while (fi >> noskipws >> c)
	{
		bitset<8> bit(c);
		str_bit_data += bit.to_string();
	}
	fi.close();

	return str_bit_data;

}

//xây dựng lại cây huffman và chỉnh string encrypted để tiến hành giải nén
void StaticHuffman::rebuildHuffmanTree(Node*curr, string &bitTree)
{
	while (bitTree.length() > 0)
	{
		
		// Nếu là node lá
		if (curr->left != NULL && curr->right != NULL)
		{
			return;
		}
		Node* node = new Node(-1);
		
		if (bitTree[0] == '0')
		{
			bitTree.erase(0, 1);
			// Ta cần phải xác định xem mình nên gọi đệ quy đến node trái hay phải
			if (curr->left == NULL)
			{
				curr->left = node;
				rebuildHuffmanTree(curr->left, bitTree);
			}
			else
			{
				curr->right = node;
				rebuildHuffmanTree(curr->right, bitTree);
			}
		}

		// Nếu gặp bit '1', ta get 16 bit kế tiếp
		else
		{
			string temp = bitTree.substr(1, 16);
			bitTree.erase(0, 17);

			// Hàm char convertBitToChar(string temp) dùng để xuất ra ký tự tương ứng với chuỗi bit
			bitset<16> bs(temp);
			int h = bs.to_ulong();
			node->c = wchar_t(h);
			if (curr->left == NULL) 
				curr->left = node;
			else 
				curr->right = node;
		}
	}

}

void StaticHuffman::Extract(const string _encrypted_path, const string _freq_table_path, const string _output_path)
{
	this->releaseAll();
	this->loadFrequencyTable(_freq_table_path);
	this->buildHuffmanTree();
	
	ifstream fi(_encrypted_path, ios::in | ios::binary);
	wofstream fo(_output_path, ios::out | ios::binary);
	fo.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (fi.is_open() && fo.is_open())
	{
		int size_byte = 4096;
		char addBit;
		char c;
		fi.read(&addBit, 1);//đọc 1 byte đầu
		char* str = new char[size_byte+1];
		string bit_str="";
		string bit_odd="";
		Node*node = m_root;
		while (!fi.eof())
		{
			for (int i = 0; i <= size_byte; i++)
				str[i] = '\0';
			
			fi.read(str, size_byte);
			/*for (int i = 0; i < size_byte && !fi.eof(); i++)
			{
				fi >> noskipws >> c;
				str[i] = c;
			}*/
			bit_str = bit_odd;
			for(int i = 0;i<strlen(str);i++)
			{
				bitset<8> bit(str[i]);
				bit_str += bit.to_string();
			}
			if (fi.eof())
			{
				int a;
				bit_str.erase(bit_str.size() - addBit, addBit);
			}
			//Extract
			
			//wstring text = L"";
			while (bit_str.size()>0)
			{
				c = bit_str[0];
				bit_str.erase(0, 1);
				if (c == '0')
					node = node->left;
				else
					node = node->right;
				if (node->left == NULL && node->right == NULL)
				{
					fo << node->c;
					node = m_root;
				}
			}

		}
		delete[]str;
	}
	fi.close();
	fo.close();
}

void StaticHuffman::makeFrequencyTable(const string _input_path, const string _freq_out, bool utf8_mode)
{
	bool flag = true;
	//unsigned long length;
	wifstream fi(_input_path, ios::in|ios::binary);
	
	//encode utf-8 mode
	if (utf8_mode)
		fi.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	if (fi.is_open() )
	{
		int j;
		wchar_t c;
		//tạo bảng tần số luu vào vector m_freq_table
		while (!fi.eof())
		{
			//filein.read(&c, 1);
			fi >> noskipws >> c;
			//wcout << c;
			for (j = 0; j < m_freq_table.size(); j++)
			{
				if (c == m_freq_table[j]->c)
				{
					m_freq_table[j]->freq++;
					break;
				}
			}

			if (j == m_freq_table.size())
			{
				m_freq_table.push_back(new Node(c));
				cout << m_freq_table.size() << endl;
			}
		}
		//Sắp xếp lại bảng tần số (tăng dần)
	}
	for (int i = 0; i < m_freq_table.size() - 1; i++)
	{
		for (int j = i + 1; j < m_freq_table.size(); j++)
		{
			//ưu tiên so sánh tần số trước, nếu 2 tần số bằng nhau thì sắp theo thứ tự chữ cái
			if (
				(m_freq_table[i]->freq > m_freq_table[j]->freq) ||
				(m_freq_table[i]->freq == m_freq_table[j]->freq && ((m_freq_table[i]->c > m_freq_table[j]->c)))
				)
			{
				Node* temp = m_freq_table[i];
				m_freq_table[i] = m_freq_table[j];
				m_freq_table[j] = temp;
			}
		}
	}
	wofstream fo(_freq_out, ios::out | ios::binary);
	//encode utf-8 mode
	fo.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (fo.is_open())
	{
		int n = m_freq_table.size();
		for (int i = 0; i < n; i++)
		{
			fo << hex << (int)m_freq_table[i]->c << "\t" << hex << m_freq_table[i]->freq << endl;
			//wcout << (int)m_freq_table[i]->c << "\t" << m_freq_table[i]->freq << endl;
		}
	}

}