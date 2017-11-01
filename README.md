# RegisterMachine

Here is a small Register machine implemented in C++. It supports the following commands:
* INP (Input)
* LDK (Load Constant)
* LDA (Load Address)
* MUL (Multiplication)
* ADD (Addition)
* SUB (Substraction)
* STA (Store Address)
* JNE (Jump Not Equal)
* OUT (Print Out)
* HLT (Halt)
* DIV (Divide)
* JMP (Jump)
* JEZ (Jump Equal Zero)
* JLZ (Jump Less Zero)
* JGZ (Jump Greater Zero)
* JLE (Jump Less Equal)
* JGE (Jump Greater Equal)

##### How To Build

```
g++ -std=c++11 -o registermachine main.cpp
```


##### How To Run

```
./registermachine <VALID PROGRAM TEXT FILE>
```

##### Example Program Code

Example.txt:

```
INP N
LDK 0
STA RES
LDA N
MUL N
STA QUAD
LDA RES
ADD QUAD
STA RES
LDK 1
STA VAR
LDA N
SUB VAR
STA N
JNE 5
OUT RES
HLT 99
```

```
./registermachine Example.txt
```
