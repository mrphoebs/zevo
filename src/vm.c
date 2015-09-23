#include<vm.h>
#include<stdio.h>
#include<stdbool.h>

bool running = true;
int_fast8_t vm_registers[4];

void eval(vm_word* program){

	clear_registers();
	vm_word* program_counter = program;
	struct vm_instr current_instr;

	while(running){
	 current_instr = fetch(program_counter++);
	 execute(current_instr);
	}
	print_registers();
	return;
}


struct vm_instr fetch(vm_word* program_counter){
	struct vm_instr current_instr;
	current_instr.instruction = (*program_counter & 0xF000)>>12;
	current_instr.registers[0] = (*program_counter & 0x0F00)>>8;
	current_instr.registers[1] = (*program_counter & 0x00F0)>>4;
	current_instr.registers[2] = (*program_counter & 0x000F);
	current_instr.op = (*program_counter & 0x00FF);
	return current_instr;
}

void execute(struct vm_instr instr){
	switch(instr.instruction){
		case HALT: running = false;
			   break;
		case ADD: vm_registers[instr.registers[0]] = add(vm_registers[instr.registers[1]], vm_registers[instr.registers[2]]);
			  break;
		case SUB: vm_registers[instr.registers[0]] = sub(vm_registers[instr.registers[1]], vm_registers[instr.registers[2]]);
			  break;
 		case MUL: vm_registers[instr.registers[0]] = mul(vm_registers[instr.registers[1]], vm_registers[instr.registers[2]]);
			  break;
		case DIV: vm_registers[instr.registers[0]] = divide(vm_registers[instr.registers[1]], vm_registers[instr.registers[2]]);
			  break;
		case LOAD: vm_registers[instr.registers[0]] = instr.op;
			  break;
		default: running = false;
	}
}

void clear_registers(){
	vm_registers[0]=0;
	vm_registers[1]=0;
	vm_registers[2]=0;
	vm_registers[3]=0;
}

void print_registers(){
	printf("r0: %d\n", vm_registers[0]);
	printf("r1: %d\n", vm_registers[1]);
	printf("r2: %d\n", vm_registers[2]);
	printf("r3: %d\n", vm_registers[3]);
}
