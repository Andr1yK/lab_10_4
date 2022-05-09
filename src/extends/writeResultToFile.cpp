#pragma once
 
#ifndef _WRITERESULTTOFILE_
#define _WRITERESULTTOFILE_

#include "typesCount.hpp"
#include <fstream>

void writeResultToFile(char* fname, TypesCount count) {
  ofstream fout(fname);

  fout << "negative: " << count.negativeNums << endl
    << "positive: " << count.positiveNums << endl
    << "zero: " << count.zeroNums << endl
    << "symbols(words): " << count.symbols << endl;
}

#endif
