#ifndef _ASSEMBLER_H_
#define _ASSEMBLER_H_

#define MAX_TOKENS_PER_LINE 4

#include<vm.h>


void assemble(int lines, char** assembly, vm_word* machine_code);

void tokenize(char* line, char tokens[][20]);

vm_word interpret(char tokens[][20]);

vm_word getregister(char* token);

#endif
