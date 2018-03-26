#include "StaticHuffman.h"
using namespace std;

#include <conio.h>

int main(){
	
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);

	StaticHuffman huff;
	huff.Compress("TextFile.txt", "Encrypt.txt");
	huff.Extract("Encrypt.txt", "ExtractedFile.txt");

	//string data = huff.readEncryptFile("Encrypt.txt");
	//_getch();
	return 0;
}
