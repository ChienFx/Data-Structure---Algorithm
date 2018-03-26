#include "Function.h"
#include <fcntl.h> //_O_U16TEXT

int main()
{
	std::string str("Test string");
	std::cout << "size: " << str.size() << "\n";
	std::cout << "length: " << str.length() << "\n";
	std::cout << "capacity: " << str.capacity() << "\n";
	std::cout << "max_size: " << str.max_size() << "\n";
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);

	//makeResource(L"EV_dict.txt", L"my_index.txt");
	//showContents("2352", "6b", L"EV_dict.txt");
	//showContents("e25434",	"aa", L"EV_dict.txt");
	return 0;
}