#include "StaticHuffman.h"

StaticHuffman::StaticHuffman()
{
	m_str_data = NULL;
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
	if (m_str_data != NULL)
	{
		delete m_str_data;
		m_str_data = NULL;
	}
}

//Hàm đọc văn bản cần nén vào bộ nhớ
//Input: đường dẫn file chứa văn bản
//Output: true, false(đường dẫn sai)
bool StaticHuffman::loadData(const string _path)
{
	bool flag = true;
	unsigned long length;
	wifstream filein(_path, ios::binary);
	
	//encode utf-8 mode
	filein.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	if (filein.is_open())
	{
		wstring str = L"";
		wchar_t c;
		while (!filein.eof())
		{
			filein.read(&c, 1);
			str += c;
		}
		str.resize(str.size() - 1);
		
		m_str_data = wcsdup(str.c_str());

	}
	else
		flag = false;
	filein.close();
	return flag;
}

bool StaticHuffman::buildFrequencyTable()
{
	if (m_str_data == NULL)
	{
		return false;
		m_amount_char = 0;
	}
	int n = wcslen(m_str_data);

	int i, j;

	//tạo bảng tần số luu vào vector m_freq_table
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m_freq_table.size(); j++)
		{
			if (m_str_data[i] == m_freq_table[j]->c)
			{
				m_freq_table[j]->freq++;
				break;
			}
		}

		if (j == m_freq_table.size())
		{
			m_freq_table.push_back(new Node(m_str_data[i]));
		}
	}
	//Sắp xếp lại bảng tần số (tăng dần)
	for (i = 0; i < m_freq_table.size() - 1; i++)
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
	m_amount_char = m_freq_table.size();
	return true;
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
string StaticHuffman::convertBitTableToString()
{
	string str = "";
	encryptTree(m_root,str);
	return str;
}

void StaticHuffman::encryptTree(Node* curr, string &bitTree)
{
	if (curr != NULL)
	{
		// Nếu node là lá
		if (curr->left == NULL && curr->right == NULL)
		{
			bitTree += '1';
			bitset<16> bitSq(curr->c);
			bitTree += bitSq.to_string();
		}
		// Ngược lại
		else
		{
			bitTree += '0';
			encryptTree(curr->left,bitTree);
			encryptTree(curr->right,bitTree);
		}
	}
}

string StaticHuffman::convertDataToStringCompress()
{
	string str = "";
	unsigned long n = wcslen(m_str_data);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_amount_char;j++)
		if (m_str_data[i] == m_bit_table[j].c)
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

void StaticHuffman::Compress(const string _input_path, const string _output_path)
{
	this->releaseAll();
	this->loadData(_input_path);
	this->buildFrequencyTable();
	this->buildHuffmanTree();
	this->buildBitTable();
	string str_bit_table = this->convertBitTableToString();
	string str_bit_data = this->convertDataToStringCompress();

	string str_encrypt = convertBitStringToCharString(str_bit_table + str_bit_data);
	
	int addBits = str_encrypt.size() * 8 - (str_bit_table + str_bit_data).length();

	ofstream f(_output_path, ios::out|ios::binary);
	if (f.is_open())
	{
		f << (char)m_amount_char;
		f<< (char)addBits;
		//phải ghi đủ str_encrypt.size() ki tu trong chuoi, có thể là \0 giữa chuỗi nên không dùng f << str_en
		for (int i = 0; i < str_encrypt.size(); i++)
			f << (char)str_encrypt[i];
	}
	f.close();
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

void StaticHuffman::Extract(const string _encrypt_path, const string _output_path)
{
	string encrypted_bit_data = readEncryptFile(_encrypt_path);

	//Lấy 2 byte đầu ra và cắt bỏ luôn
	string tmp = encrypted_bit_data.substr(0, 8);//lấy 8 bit đầu

	bitset<8> bs(tmp);
	m_amount_char = bs.to_ulong();
	encrypted_bit_data.erase(0, 8);

	tmp = encrypted_bit_data.substr(0, 8);//lấy 8 bit tiếp theo
	bs = bitset<8>(tmp);
	int addBits = bs.to_ulong();
	encrypted_bit_data.erase(0, 8);

	//bỏ bit 0 thừa
	encrypted_bit_data.erase(encrypted_bit_data.size() - addBits, addBits);

	//Số tổng số bit của cây huffman đã lưu: n node * 16bit = 16*n + 2*n - 1 bit bieu diễn đường đi của cây = số node của cấu trúc heap 2n-1 
	int bit_tree_len = m_amount_char * 16 + 2 * m_amount_char - 1;

	//BitTree là chuỗi bit_tree_len đầu
	string bitTree = encrypted_bit_data.substr(0, bit_tree_len);
	encrypted_bit_data.erase(0, bit_tree_len);

	//xay duwngj laij cay huffman
	Node* node = new Node(-1);
	rebuildHuffmanTree(node, bitTree);
	m_root = node->left;
	node->left = NULL;
	delete node;

	char c;
	node = m_root;
	//Extract
	wstring text = L"";
	while (encrypted_bit_data.size()>0)
	{
		c = encrypted_bit_data[0];
		encrypted_bit_data.erase(0, 1);
		if (c == '0')
			node = node->left;
		else
			node = node->right;
		if (node->left == NULL && node->right == NULL)
		{
			text += node->c;
			node = m_root;
		}
	}
	
	wofstream fo(_output_path, ios::out | ios::binary);
	//encode utf-8 mode
	fo.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	if (fo.is_open())
	{
		fo << text;
	}
	fo.close();
}