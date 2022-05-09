#pragma once

#ifndef _PRINT_TXT_
#define _PRINT_TXT_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintTXT(char* fname)
{
  ifstream fin(fname); 
  string s;

  for (; getline(fin, s); cout << s << endl);

  fin.close();
}

#endif