#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <cwchar>
#include <fstream>
#include <iostream>
#include <io.h>
#include <codecvt>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

void initEncodeMode();
void makeResource(const wstring _dict_path, const wstring _index_path);
void showContents(const string pos1, const string pos2, const wstring _dict_path);

#endif