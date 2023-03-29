#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class CPU {

string halt = "0000";

    public:
void runLine(string opcode, vector<string> operand) {
if(opcode == halt) {
cout << "Halt" << endl;
}
else {
unsigned long decimal = bitset<4>(operand[0]).to_ulong();
  cout<<decimal<<"\n";
}
};


};