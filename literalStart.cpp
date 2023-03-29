#include <iostream>
#include <string>
#include <bitset>

 
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

class CPU {
  public:
  void runLine(string line) {
    // vector<string> tokens = split(line, " ");
cout << "C++..." << endl;
  };

};
 
// This program prints out “Hello World!”
int main(int argc, char* argv[]) {
  string message = "Hello World!\n";
  cout << message;
  int a = 4;
  int* b = &a;
  // cout << b << endl;
  // cout << *b << endl;
  // cout << &a << endl;
  string binary = bitset<8>(a).to_string(); //to binary
  cout<<binary<<"\n";

  unsigned long decimal = bitset<8>(binary).to_ulong();
  cout<<decimal<<"\n";

  string line = "0001 hi";

  CPU cpu;

  cpu.runLine(line);
    
  return 0;
}