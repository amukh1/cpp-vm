#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "./variadic_table/include/VariadicTable.h"

using namespace std;

class CPU {
public:
  vector<vector<string>> ro_memory;
  vector<string> ca_memory;
  vector<string> ra_memory = {"00000000", "00000000"};
  vector<string> registers = {"00000000", "00000000"};
  int line = 0;

  int run();

  void run_line(vector<string> mem);

  void crom();

  void cmem();

};

/*
void runLine(string opcode, vector<string> operand) {
if(opcode == halt) {
cout << "Halt" << endl;
}
else {
unsigned long decimal = bitset<4>(operand[0]).to_ulong();
  cout<<decimal<<"\n";
}
};

*/