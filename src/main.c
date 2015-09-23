#include<stdio.h>
#include<vm.h>
#include<stdlib.h>
#include<assembler.h>
#include<string.h>

int main(int argc, char* argv[]){
	vm_word prog[10];
	char *code[5];

	code[0] = "LOAD r0 100";
	code[1] = "LOAD r1 10";
	code[2] = "ADD r2 r1 r0";
	code[3] = "HALT"; 

	assemble(4, code, prog); 
	eval(prog);
	return 0;
}
