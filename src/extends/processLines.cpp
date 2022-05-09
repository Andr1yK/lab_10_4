#pragma once
 
#ifndef _PROCESSLINES_
#define _PROCESSLINES_

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "typesCount.hpp"
#include <regex>

using namespace std;

void processLine(string line, TypesCount& count) {
  string str = "";
  int pos = 0;

  do {
    str.assign(line, pos, line.find(' ', pos + 1) - pos);

    if (regex_match(str, regex("^[0]+"))) {
      count.zeroNums += 1;
    } else if (regex_match(str, regex("^-[0-9]+"))) {
      count.negativeNums += 1;
    } else if (regex_match (str, regex("^[0-9]+"))) {
      count.positiveNums += 1;
    } else {
      count.symbols += 1;
    }  

    pos = line.find(' ', pos + 1) + 1;
  } while (pos - 1 != -1);
}


TypesCount processLines(char* fname) {
  ifstream fin(fname);
  string str;
  TypesCount count;

  string word = "";

  while ( getline(fin, str) ) {
    if (str == "")
      continue;

    processLine(str, count);
  }

  fin.close();

  return count;
}

#endif
