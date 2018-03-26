/*
-	Từ điển Anh-Việt English - Vietnames Dictionary) 
-	Sử dụng thuật toán:
	+	Nén dữ liệu Huffman tĩnh (Static Huffman).
	+	Cấu trúc dữ liệu B-Tree
	
-	Lưu ý:
	+	Thuật toán nén Huffman tĩnh áp dụng trong dự án này không hoàn toàn giống lí thuyết vài chỗ như sau:
		-> Không tạo bảng tần số/ bảng mã bit từ file cần nén.
		-> Sử dụng bảng tần số/ bảng mã bit chuẩn được thống kê từ nhiều trang báo.
		-> Không ghi thông tin cây Huffman lên file nén.
*	Copyright: Phạm Minh Chiến - HCMUS
*/
#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include "B-Tree\BTree.h"
#include "Static_Huffman\StaticHuffman.h"
#include <sstream>

#define		B_TREE_DEGREE			5
#define		PATH_INDEX_TEX_FILE			"Data/EV_index.txt"
#define		PATH_DICTIONARY_TEXT_FILE	"Data/EV_dict.txt"

#define		PATH_HUFF_FREQ_TABLE		"Data/huff_freq_table.txt"

#define		PATH_DICTIONARY_ENCRYPTED_FILE	"Data/dict_ecpypted.txt"

class Dictionary
{
private:
	StaticHuffman m_huff;
	BTree *m_btree;
	wifstream	f_dict;
public:
	Dictionary();
	virtual~Dictionary();
	bool loadData();
	void show();
	void search(const string);

	//friend string wstring_to_string(const wstring wc);
};

//string wstring_to_string(wstring wc)
//{
//	//wstring convert = wstring(word);
//	//string tmp = string(convert.begin(), convert.end());
//	string kq = string(wc.begin(), wc.end());
//	return kq;
//}
#endif