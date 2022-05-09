#pragma once

#ifndef _CREATE_TXT_
#define _CREATE_TXT_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(
  char* fname,
  istream &std_input = cin,
  ostream &std_output = cout
) {
  ofstream fout(fname);
  char ch;
  string s;

  do {
    std_input.get();
    std_input.sync();
    std_output << "enter line: "; getline(std_input, s);
    fout << s << endl;
    std_output << "continue? (y/n): "; std_input >> ch;
  } while (ch == 'y' || ch == 'Y');

  std_output << endl;

  fout.close();
}
#endif
