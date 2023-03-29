#include <iostream>
#include <string>
#include <bitset>
#include <vector>

#include "CPU.h"
#include "Calculus.h"

 
using namespace std;

float quadratic(float x) {
  return x * x;
}
 
// This program prints out “Hello World!”
int main(int argc, char* argv[]) {

  CPU cpu;

  cpu.ro_memory.push_back({"0001", "0011"});
  cpu.ro_memory.push_back({"0001", "0111"});

  cpu.run();

  cout << cpu.cmemory() << endl;

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