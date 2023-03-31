#include <bitset>
#include <iostream>
#include <string>

#include <vector>

#include <fstream>
#include <string>

#include "./variadic_table/include/VariadicTable.h"

#include "CPU.h"
// #include "./cpp/Calculus.h"

using namespace std;

vector<string> split(string str, string delim) {
  vector<string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

int main(int argc, char *argv[]) {

  CPU cpu;

  cpu.ro_memory.push_back({"0001", "0000", "00000111"});
  cpu.ro_memory.push_back({"0010", "0000", "0001", "0000"});
  cpu.ro_memory.push_back({"0101", "0001", "0001", "0000"});
  cpu.ro_memory.push_back({"0110", "0000", "0001", "0000"});
  cpu.ro_memory.push_back({"0011", "0001", "0000", "0000"});
  // cpu.ro_memory.push_back({"0100", "0001", "0001", "0000"});
  cpu.ro_memory.push_back({"1000", "0001", "0000", "0000"});
  cpu.ro_memory.push_back({"0000", "000000000000"});

  cpu.run();

  cpu.crom();

  cpu.cmem();

  /* calculus */
  /*
  cout << (float) derivative(&quadratic, 3) << endl;

  cout << (float) riemann(&quadratic, 0, 3, 20) << endl;

  cout << (float)limit(&quadratic, 4) << endl;
  */

  return 0;
}

/*
Binary Strings:
  string binary = bitset<8>(a).to_string(); //to binary
  cout<<binary<<"\n";

  unsigned long decimal = bitset<8>(binary).to_ulong();
  cout<<decimal<<"\n";

Pointers and References:

  int a = 4;
  int* b = &a;

  cout << b << endl;
  cout << *b << endl;
  cout << &a << endl;
*/