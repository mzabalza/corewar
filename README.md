Corewar
=====
## 1 What is Corewar?

Corewar is a very peculiar game. It’s about bringing “players” together around a “VIRTUAL MACHINE”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.
The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them.
The game ends when all the processes are dead. The winner is the last player reported to be “alive”.


This project can be divided into three distinctive parts:

### 1. 1 The assembler:
This is the program that will compile your champions and translate them from assembly language into “Bytecode”, a machine code, which will be directly interpreted by the virtual machine.
### 1. 2 The virtual machine:
It’s the “arena” in which the champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. It allows to execute numerous simultaneous processes.
### 1. 3 The champion:
For now, only needs to prove that writing some bits and pieces of assembly language.

## Allowed functions
Within the project, it is allowed to use only the following libc functions:open, read, lseek, write, close, malloc, realloc, free, perror, strerror, exit.

## 2. VIRTUAL MACHINE

The virtual machine has been programmed following computer architecture basics and program execution in memory. 

When a computer interprets assembly level instructions, these instructions are turned into their binary equivalents for the CPU to read. Instructions consists of an opcode and any applicable data that goes with it, if required (e.g. register names, memory addresses).

<img src="https://github.com/mzabalza/corewar2/blob/master/img/architecture.png" width="50%">

Our virtual machine acts exactly the same way. At the beginning of the programm the virtual machine will take the players programm and will put it into the arena(space of limited memory: 64 x 64 bytes). Then a PC(Programm Counter) will point at the first instruction of the player, and will execute the instructions one by one. In our case the VM will be able to read 16 different types of intructions:

- LIVE
- LD
- ST
- ADD
- SUB
- AND
- OR
- XOR
- ZJMP
- LDI
- STI
- FORK
- LLD
- LLDI
- LFORK
- AFF

Bassically the VM will the operations like:
- Modify info in the arena/process registers.
- Create/Kill processes.

The main goal of the game is to stay alive so the VM will meanwhile record the last time a player said the instruction live.
At the end of the playing cycles the VM will show the winning player.

## 3. PROJECT USAGE
### 3.1 Clone and Compile
```
brew install sdl2_image
```
```
git clone --recursive https://github.com/mzabalza/corewar.git; make
```
![compile](gifs/compile.gif)

### 3.2 Execute binary

![compile](gifs/run_vm.gif)
