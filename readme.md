# A virtual CPU written in C++.

# Example Usage

## Import package:

CPU being the folder containing the CPU.h file.

```Cpp
#include "./packages/CPU/CPU.h"
```

## Initialize:

```Cpp
CPU cpu;
```

## Load ROM:

```Cpp
cpu.ro_memory.push_back({"0001", "0001", "00000111"});
cpu.ro_memory.push_back({"0010", "0001", "0010", "0000"});
// keep adding binary
```

## Run:

```Cpp
cpu.run();
```

## Print Memory:

```Cpp
cpu.crom();
cpu.cmem();
```

## Final:

```Cpp
#include <iostream>
#include <string>
#include <vector>

#include "./packages/CPU/CPU.h"

using namespace std;


int main(int argc, char *argv[]) {

  CPU cpu;

  cpu.ro_memory.push_back({"0001", "0001", "00000111"});
  cpu.ro_memory.push_back({"0010", "0001", "0010", "0000"});
  cpu.ro_memory.push_back({"0011", "0001", "0010", "0000"});
  cpu.ro_memory.push_back({"0101", "0001", "0010", "0000"});
  cpu.ro_memory.push_back({"0110", "0001", "0010", "0000"});
  cpu.ro_memory.push_back({"0000", "000000000000"});

  cpu.run();

  cpu.crom();

  cpu.cmem();

  return 0;
}
```

## Example Output:

```txt
-----------------------------------------------
| LINE |               OPERATION              |
-----------------------------------------------
|    1 | 7 in reg $1                          |
|    2 | Move reg $1 to reg $2                |
|    3 | Reg $2 in ram slot 1                 |
|    4 | Out 7 to port 1                      |
|    5 | Add reg $1 and reg $2 = 14 to reg $0 |
|    6 | Halt                                 |
-----------------------------------------------
-------------------------------
| LINE |        BINARY        |
-------------------------------
|    1 | 0001 0001 00000111   |
|    2 | 0010 0001 0010 0000  |
|    3 | 0011 0001 0010 0000  |
|    4 | 0101 0001 0010 0000  |
|    5 | 0110 0001 0010 0000  |
|    6 | 0000 000000000000    |
-------------------------------
--------------------------
| Mem Type |    Data     |
--------------------------
| RAM      | 0;7;0;      |
| REG      | 14;7;7;0;   |
| ROM      | [PRELOADED] |
--------------------------
```