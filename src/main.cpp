#include <iostream>

using namespace std;

#include "extends/createTXT.cpp"
#include "extends/processLines.cpp"
#include "extends/printTXT.cpp"
#include "extends/writeResultToFile.cpp"

#include "extends/typesCount.hpp"

int main()
{
  char fname[100] = "test";
  char resName[100] = "test_res";

  cout << "enter file name: "; cin >> fname;
  cout << "enter result file name: "; cin >> resName;

  CreateTXT(fname);
  PrintTXT(fname);

  cout << endl << endl;

  writeResultToFile(resName, processLines(fname));

  PrintTXT(resName);

  return 0;
}
