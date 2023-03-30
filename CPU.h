#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class CPU {
public:
vector<vector<string>> ro_memory;
vector<string> ra_memory = {"00000000", "00000000"};
vector<string> registers = {"00000000", "00000000"};

int run() {
  for(int i = 0; i < ro_memory.size(); i++) {
    if(ro_memory[i][0] == "0000") {
      cout << "Halt" << endl;
      return 0;
    }
    run_line(ro_memory[i]);
  }

  return 0;
}

void run_line(vector<string> mem) {
  if(mem[0] == "0001") {
    // load immediate
    unsigned long decimal = bitset<8>(mem[2]).to_ulong();
    cout<<decimal<< " in reg $" << bitset<4>(mem[1]).to_ulong() << endl;
    registers.insert(registers.begin() + bitset<4>(mem[1]).to_ulong(), mem[2]);
  }else if(mem[0] == "0010") {
    // move
    unsigned long reg1 = bitset<4>(mem[1]).to_ulong();
    unsigned long reg2 = bitset<4>(mem[2]).to_ulong();
    cout << "Move reg $" << reg1 << " to reg $" << reg2 << endl;
  }else if(mem[0] == "0011") {
    // allocate (to ram)
    unsigned long decimal = bitset<8>(mem[2]).to_ulong();
    cout<<decimal<< " in ram slot %" << bitset<4>(mem[1]).to_ulong() << endl;
    ra_memory.insert(ra_memory.begin() + bitset<4>(mem[1]).to_ulong(), mem[2]);
  }
}

string crom() {
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

string cmem() {
  // put ra_memory and registers into a table-like string
  string output = "ram: ";
  for(int i = 0; i < ra_memory.size(); i++) {
    output += ra_memory[i] + ";";
  }
  output += "\nrom: ";
  for(int i = 0; i < registers.size(); i++) {
    output += registers[i] + ";";
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