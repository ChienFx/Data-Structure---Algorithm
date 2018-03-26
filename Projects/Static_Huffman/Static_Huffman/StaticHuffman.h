/* STATIC-HUFFMAN
-	Đây chỉ là class mô phỏng lý thuyết về static huffman, nên sẽ thực hiện giống 100% ý tưởng theo lý thuyết:
	+ Đọc văn bản đầu vào -> lập bảng tần số
	+ Từ bảng tần số -> tạo cây Huffman
	+ Từ cây Huffman -> tạo bảng mã bit
	+ Thay thế các kí tự trong chuỗi đầu vào bằng mã bit
	+ Lưu bảng tần số/ bảng mã bit + chuỗi được mã hóa ra file mã hóa
	+ Khi giải nén sẽ đọc fie nén và xây dựng lại cây huffman từ thông tin bảng tần số/ bảng mã bit	
	+ Giải nén từ cây huffman
- Trên đây là cơ bản thuật Toán Huffman tĩnh, tuy nhiên trong xây dựng phần mềm thì có đôi chút khác đi:
	+ Không lập bảng tần số từ văn bản đầu vào mà sẽ tự thống kê một bảng mã theo các nguồn tài liệu khác
	  làm bản tần số/ bảng mã bit chuẩn cho phần mềm của mình
	+ Không lưu thông tin bảng tần số/ mã bít vào chung với file nén mà lưu riêng ra file khác của phần mềm
	(Tham khảo solution EV - Dictionary with B-Tree using Huffman Static)
*/
#ifndef _STATICHUFFMAN_H
#define _STATICHUFFMAN_H
#include "Node.h"
#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <codecvt>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;
struct Bit
{
	wchar_t c;
	string	bit;
};
class StaticHuffman
{
private:
	Node*			m_root;				//gốc của cây huffman
	wchar_t*		m_str_data;			//nội dung gốc cần nén
	vector<Node*>	m_freq_table;		//array lưu bảng tần số:
	vector<Bit>		m_bit_table;		//array lưu mã bit
	int				m_amount_char;		//số lượng kí số xuất hiện (sizeof freq table)

	//void loadFrequencyTable(const wchar_t* _path);//sau này đưa và private hết
	
	//Hàm đọc văn bản cần nén vào bộ nhớ
	//Input: đường dẫn file chứa văn bản
	//Output: true, false(đường dẫn sai)
	bool loadData(const string _path);

	//Hàm tạo bảng tần số từ file _path, bảng tần số lưu dạng mảng Node* freq_table cấp phát động
	//Input: 
	//Output: true nếu thành công, false thất bại (str_data rong)
	bool buildFrequencyTable();

	//Hàm tạo cây huffman từ bảng tần số
	//Input: 
	//Output: true nếu thành công, false thất bại (dữ liệu rỗng)
	bool buildHuffmanTree();

	//Hàm tạo bảng tần số từ cây Huffman
	//Input: 
	//Output: true nếu thành công, false thất bại (str_data rong)
	void buildBitTable();

	void printCode(Node*&p);
	
	//chuyển bảng bit thành string để dùng lúc giải nén, ví dụ: Â =001, Đ = 101 -> ÂĐĐ = 001Â101Đ101Đ (lưu dạng bit<16>)
	string	convertBitTableToString();
	void	encryptTree(Node* curr, string &bitTree);
	
	//Thay thế chuỗi ban đầu theo bit mã hóa
	string	convertDataToStringCompress();

	//Giải nén
	//Hàm load file giải nén vào string và chuyển thành bit string
	string readEncryptFile(const string _path);

	void rebuildHuffmanTree(Node*curr, string &bitTree);

	//release, hủy dữ liệu trong RAM
	void releaseAll();
public:

	StaticHuffman();
	virtual ~StaticHuffman();

	void Compress(const string _input_path, const string _output_path);

	void Extract(const string _encrypt_path, const string _output_path);
	/*
	- 1 hàm chuyển từ bảng bit sang string
	- 1 hàm compress nừa là xong phần nén 
	- tìm hàm convert string to bit
	*/
	
	
	friend string convertBitStringToCharString(string _source);

};

#endif