#include "Dictionary.h"
#include <conio.h>
int main()
{
	StaticHuffman huff;
//	huff.makeFrequencyTable(PATH_INDEX_TEX_FILE, PATH_HUFF_FREQ_INDEX_TABLE);
	//huff.loadFrequencyTable(PATH_HUFF_FREQ_TABLE);
	//huff.Compress(PATH_DICTIONARY_TEXT_FILE, PATH_HUFF_FREQ_TABLE, PATH_DICTIONARY_ENCRYPTED_FILE,1);

	huff.Compress("Data/in.txt", PATH_HUFF_FREQ_TABLE, "Data/out.txt",1);

	huff.Extract("Data/out.txt", PATH_HUFF_FREQ_TABLE, "Data/output.txt");
	//huff.Compress(PATH_DICTIONARY_TEXT_FILE, PATH_DICTIONARY_ENCRYPTED_FILE);
	//
	//Dictionary dict;
	//wstring word = L"";
	//wchar_t* wch = new wchar_t[1024];
	//while (true)
	//{
	//	wcout << L"Nhập từ cần tìm:";
	//	wcin.getline(wch, 1024);
	//	//wcin >> word;
	//	fflush(stdin);
	//	wcout << L"----------------------------------"<<endl;
	//	if (word.compare(L"-1") == 0)
	//		break;

	//	word = wstring(wch);
	//	string str = string(word.begin(), word.end());
	//	dict.search(str);
	//	system("pause");
	//	system("cls");
	//} 
	//delete[]wch;
	return 0;
}