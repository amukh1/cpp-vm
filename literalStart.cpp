#include <iostream>
#include <string>
#include <bitset>
 
using namespace std;
 
// This program prints out “Hello World!”
int main(int argc, char* argv[]) {
  string message = "Hello World!\n";
  cout << message;
  int a = 4;
  int* b = &a;
  cout << b << endl;
  cout << *b << endl;
  cout << &a << endl;
  cout << bitset<8>(2).to_string() << endl;
    
  return 0;
}