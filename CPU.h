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

  int run() {
    for (int i = line; i < ro_memory.size(); i++) {
      if (ro_memory[i][0] == "0000") {
        // cout << "Halt" << endl;
        ca_memory.push_back("Halt");
        return 0;
      }
      run_line(ro_memory[i]);
    }

    return 0;
  }

  void run_line(vector<string> mem) {
    if (mem[0] == "0001") {
      // load immediate
      unsigned long decimal = bitset<8>(mem[2]).to_ulong();
      // cout << decimal << " in reg $" << bitset<4>(mem[1]).to_ulong() << endl;

      ca_memory.push_back(to_string(decimal) + " in reg $" +
                          to_string(bitset<4>(mem[1]).to_ulong()));

      // registers.insert(registers.begin() + bitset<4>(mem[1]).to_ulong(), mem[2]);
      registers.at(bitset<4>(mem[1]).to_ulong()) = mem[2];
    } else if (mem[0] == "0010") {
      // move
      unsigned long reg1 = bitset<4>(mem[1]).to_ulong();
      unsigned long reg2 = bitset<4>(mem[2]).to_ulong();

      // cout << "Move reg $" << reg1 << " to reg $" << reg2 << endl;

      ca_memory.push_back("Move reg $" + to_string(reg1) + " to reg $" +
                          to_string(reg2));

      // registers.insert(registers.begin() + reg2, registers[reg1]);
      registers.at(reg2) = registers[reg1];
    } else if (mem[0] == "0011") {
      // allocate (to ram)
      unsigned long port = bitset<4>(mem[1]).to_ulong();
      string reg = registers[bitset<4>(mem[2]).to_ulong()];

      // cout << bitset<8>(reg).to_ulong() << " in ram slot %" << port << endl;

      ca_memory.push_back("Reg $" + to_string(bitset<4>(mem[2]).to_ulong()) +
                          " in ram slot " + to_string(port));

      // ra_memory.insert(ra_memory.begin() + port, reg);
      ra_memory.at(port) = reg;
    } else if(mem[0] == "0100") {
      // load (from ram)
      unsigned long port = bitset<4>(mem[1]).to_ulong();
      unsigned long reg = bitset<4>(mem[2]).to_ulong();

      // cout << bitset<8>(ra_memory[port]).to_ulong() << " in reg $" << reg <<
      // endl;

      ca_memory.push_back("RAM port $" + to_string(bitset<8>(ra_memory[port]).to_ulong()) +
                          " to reg $" + to_string(reg));

      registers.at(reg) = ra_memory[port];
      
      // registers.insert(registers.begin() + reg, ra_memory[port]);
    } else if (mem[0] == "0101") {
      // out
      unsigned long port = bitset<4>(mem[1]).to_ulong();
      unsigned long reg = bitset<4>(mem[2]).to_ulong();

      // cout << "Out " << bitset<8>(registers[reg]).to_ulong() << " to port "
      // << port << endl;

      ca_memory.push_back("Out " +
                          to_string(bitset<8>(registers[reg]).to_ulong()) +
                          " to port " + to_string(port));

    } else if (mem[0] == "0110") {
      // add
      unsigned long reg1 = bitset<4>(mem[1]).to_ulong();
      unsigned long reg2 = bitset<4>(mem[2]).to_ulong();
      unsigned long outreg = bitset<4>(mem[3]).to_ulong();

      // cout << "Add reg $" << reg1 << " and reg $" << reg2 << " = "
      // << bitset<8>(registers[reg1]).to_ulong() +
      // bitset<8>(registers[reg2]).to_ulong()
      // << " to reg $" << outreg << endl;

      ca_memory.push_back("Add reg $" + to_string(reg1) + " and reg $" +
                          to_string(reg2) + " = " +
                          to_string(bitset<8>(registers[reg1]).to_ulong() +
                                    bitset<8>(registers[reg2]).to_ulong()) +
                          " to reg $" + to_string(outreg));

      registers[outreg] = bitset<8>(bitset<8>(registers[reg1]).to_ulong() +
                                    bitset<8>(registers[reg2]).to_ulong())
                              .to_string();
    }else if(mem[0] == "0111") {
      // sub
      unsigned long reg1 = bitset<4>(mem[1]).to_ulong();
      unsigned long reg2 = bitset<4>(mem[2]).to_ulong();
      unsigned long outreg = bitset<4>(mem[3]).to_ulong();

      // cout << "Add reg $" << reg1 << " and reg $" << reg2 << " = "
      // << bitset<8>(registers[reg1]).to_ulong() +
      // bitset<8>(registers[reg2]).to_ulong()
      // << " to reg $" << outreg << endl;

      ca_memory.push_back("Sub reg $" + to_string(reg1) + " and reg $" +
                          to_string(reg2) + " = " +
                          to_string(bitset<8>(registers[reg1]).to_ulong() -
                                    bitset<8>(registers[reg2]).to_ulong()) +
                          " to reg $" + to_string(outreg));

      registers[outreg] = bitset<8>(bitset<8>(registers[reg1]).to_ulong() -
                                    bitset<8>(registers[reg2]).to_ulong())
                              .to_string();
    }else if(mem[0] == "1000") {
      // jump
      unsigned long reg = bitset<4>(mem[1]).to_ulong();
      unsigned long linee = bitset<8>(registers[reg]).to_ulong();

      ca_memory.push_back("Jump to line " + to_string(line));

      line = linee - 1;
    }else if(mem[0] == "1001") {
      // jump cond. (if reg == 0)
      unsigned long reg = bitset<4>(mem[1]).to_ulong();
      unsigned long linee = bitset<8>(registers[reg]).to_ulong();

      ca_memory.push_back("Jump to line " + to_string(line) + " if reg $" + to_string(reg) + " == 0");

      if(bitset<8>(registers[reg]).to_ulong() == 0) {
        line = linee - 1;
      }
    }
  }

  void crom() {
    string output = " ____________________\n";
    VariadicTable<int, string> vt({"LINE", "BINARY"}, 10);

    VariadicTable<int, string> vt2({"LINE", "OPERATION"}, 10);
    for (int i = 0; i < ro_memory.size(); i++) {
      string out2 = "";
      for (int j = 0; j < ro_memory[i].size(); j++) {
        out2 += ro_memory[i][j] + " ";
      }
      vt.addRow((i + 1), out2);
      vt2.addRow((i + 1), ca_memory[i]);
      output += ("|" + out2 + "|" + "\n");
    }

    vt2.print(cout);
    vt.print(cout);

    // return output + " --------------------";
  }

  void cmem() {
    // put ra_memory and registers into a table-like string
    string rams = "";
    string regs = "";
    string output = "ram: ";
    for (int i = 0; i < ra_memory.size(); i++) {
      output += ra_memory[i] + ";";
      rams += to_string(bitset<8>(ra_memory[i]).to_ulong()) + ";";
    }
    output += "\nreg: ";
    for (int i = 0; i < registers.size(); i++) {
      // output += bitset<8>(registers[i]).to_ulong() + ";";
      regs += to_string(bitset<8>(registers[i]).to_ulong()) + ";";
    }

    VariadicTable<string, string> vt({"Mem Type", "Data"}, 10);

    vt.addRow("RAM", rams);
    vt.addRow("REG", regs);
    vt.addRow("ROM", "[PRELOADED]");

    vt.print(cout);

    // return output;
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