#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_
#endif

#include<stdint.h>

#define INSTRUCTION_SIZE 4 //size of instuction in bits in a VM word

typedef uint_fast8_t instr;

enum Instruction{
	HALT, ADD, SUB, MUL, DIV, LOAD 
};

int add(int op1, int op2);
int sub(int op1, int op2);
int mul(int op1, int op2);
int divide(int op1, int op2);
