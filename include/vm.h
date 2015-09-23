#ifndef _VM_H_
#define _VM_H_

#include<stdint.h>
#include<instructions.h>
#include<registers.h>

#define OPERAND_SIZE 8

typedef uint_fast8_t operand;

struct vm_instr{
	instr instruction;
	reg registers[3];
	operand op;	
};

typedef uint_fast16_t vm_word;

void eval(vm_word* program);

struct vm_instr fetch(vm_word *program_counter);

void execute(struct vm_instr instruc);

void clear_registers();

void print_registers();

#endif
