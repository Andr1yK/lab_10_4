#include <gtest/gtest.h>

#include "../src/extends/processLines.cpp" //+
#include "../src/extends/writeResultToFile.cpp"

#include "../src/extends/typesCount.hpp"

struct WorkWithFile : public testing::Test
{
  char input_fname[30] = "unittests.temp.txt";
  char result_fname[30] = "unittests_result.temp.txt";

  ofstream fout;
  TypesCount CountInFile;

  string rawData = "\
6 tz XDBk -8 V7 RcVXK\n\
\n\
A0 CW7 W5C -80 oz -6C1\n\
N 0 lO 6 Ao 8 Nm S4 Aet\n\
5 htT 0 K -8 IQF v8oi2\n\
";

  string resultLines[4] = {
    "negative: 3",
    "positive: 4",
    "zero: 2",
    "symbols(words): 19"
  };

  static void SetUpTestSuite() {
    
  }

  void SetUp() override {
    CountInFile.negativeNums = 3;
    CountInFile.positiveNums = 4;
    CountInFile.zeroNums = 2;
    CountInFile.symbols = 19;

    fout.open(input_fname);

    fout << rawData;

    fout.close();
  }

  void TearDown() override {
    remove(input_fname);
    remove(result_fname);
  }
};

TEST_F(WorkWithFile, ProcessLinesNegative) {
  TypesCount result = processLines(input_fname);

  EXPECT_EQ(result.negativeNums, CountInFile.negativeNums);
}

TEST_F(WorkWithFile, ProcessLinesPositive) {
  TypesCount result = processLines(input_fname);

  EXPECT_EQ(result.positiveNums, CountInFile.positiveNums);
}

TEST_F(WorkWithFile, ProcessLinesZero) {
  TypesCount result = processLines(input_fname);

  EXPECT_EQ(result.zeroNums, CountInFile.zeroNums);
}


TEST_F(WorkWithFile, ProcessLinesSymbols) {
  TypesCount result = processLines(input_fname);

  EXPECT_EQ(result.symbols, CountInFile.symbols);
}

TEST_F(WorkWithFile, ProcessLinesAll) {
  TypesCount result = processLines(input_fname);

  EXPECT_EQ(result.negativeNums, CountInFile.negativeNums);

  EXPECT_EQ(result.positiveNums, CountInFile.positiveNums);

  EXPECT_EQ(result.zeroNums, CountInFile.zeroNums);

  EXPECT_EQ(result.symbols, CountInFile.symbols);
}

TEST_F(WorkWithFile, WriteResult) {
  ifstream fin;
  string s;
  TypesCount result = processLines(input_fname);

  writeResultToFile(result_fname, result);

  fin.open(result_fname);

  for (int i = 0; getline(fin, s); i++) {
    EXPECT_EQ(s, resultLines[i]);
  }
}
