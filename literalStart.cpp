#include <iostream>
#include <string>
#include <bitset>
#include <vector>

#include "CPU.h"
#include "Calculus.h"

 
using namespace std;

// vector<string> split(const string& str, const string& delim)
// {
//     vector<string> tokens;
//     size_t prev = 0, pos = 0;
//     do
//     {
//         pos = str.find(delim, prev);
//         if (pos == string::npos) pos = str.length();
//         string token = str.substr(prev, pos-prev);
//         if (!token.empty()) tokens.push_back(token);
//         prev = pos + delim.length();
//     }
//     while (pos < str.length() && prev < str.length());
//     return tokens;
// }

// class CPU {
//   public:
//   void runLine(string line) {
//     // vector<string> tokens = split(line, " ");
// cout << "C++..." << endl;
//   };

// };

float quadratic(float x) {
  return x * x;
}
 
// This program prints out “Hello World!”
int main(int argc, char* argv[]) {
  string message = "Hello World!\n";
  cout << message;

  CPU cpu;

  cpu.runLine("0001", {"0011"});

  cout << (float) derivative(&quadratic, 3) << endl; 

  cout << (float) riemann(&quadratic, 0, 3, 20) << endl;
    
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