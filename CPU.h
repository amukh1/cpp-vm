#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class CPU {
public:
vector<vector<string>> ro_memory;
vector<string> ra_memory;

int run() {
  // for(int i = 0; i < ro_memory.size(); i++) {
  //   runLine(ro_memory[i][0], ro_memory[i][1]);
  // }
  // return 0;

  cout << "WIP" << endl;
  return 0;
}

string cmemory() {
  // ro_memory is a vector containing vectors, turn ro_memory and its children into a string-table thing
  string output = "";
  for(int i = 0; i < ro_memory.size(); i++) {
    string out2 = "|";
    for(int j = 0; j < ro_memory[i].size(); j++) {
      out2 += ro_memory[i][j] + " ";
    }
    output += (out2 + "|" + "\n");
  }
  return output;
}

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