#include<assembler.h>
#include<string.h>
#include<instructions.h>
#include<stdio.h>
#include<stdlib.h>

void assemble(int lines, char** assembly, vm_word* machine_code){
	
	int line_counter;
	char tokens[4][20];

	for(line_counter = 0; line_counter < lines; line_counter++){
		tokenize(assembly[line_counter],tokens);
		machine_code[line_counter] = interpret(tokens);
	}
	return;
}

void tokenize(char* line, char tokens[][20]){
	
	int token_counter;
	int char_counter = 0;
	int token_char_counter;
	for(token_counter =0; token_counter < MAX_TOKENS_PER_LINE; token_counter++){
		while(line[char_counter]==' '){
			char_counter++;
		}
		for(token_char_counter=0;line[char_counter]!='\0'&&line[char_counter]!=' ';char_counter++){
			tokens[token_counter][token_char_counter++] = line[char_counter];
		}
		tokens[token_counter][token_char_counter]='\0';
	}
}

vm_word interpret(char tokens[][20]){
	vm_word machine_code;
	
	if(strcmp("HALT",tokens[0])==0||strcmp("halt", tokens[0])==0){
		machine_code = 0x0000;
		return machine_code;	
	} else if(strcmp("ADD",tokens[0])==0||strcmp("add", tokens[0])==0){
		machine_code = ADD;
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[1]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[2]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[3]);
		return machine_code;
	} else if(strcmp("SUB",tokens[0])==0||strcmp("sub", tokens[0])==0){
		machine_code = SUB;
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[1]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[2]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[3]);
		return machine_code;
	} else if(strcmp("MUL",tokens[0])==0||strcmp("mul", tokens[0])==0){
		machine_code = MUL;
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[1]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[2]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[3]);
		return machine_code;
	} else if(strcmp("DIV",tokens[0])==0||strcmp("div", tokens[0])==0){
		machine_code = DIV;
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[1]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[2]);
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[3]);
		return machine_code;
	} else if(strcmp("LOAD",tokens[0])==0||strcmp("load", tokens[0])==0){
		machine_code = LOAD;
		machine_code = machine_code << 4;
		machine_code = machine_code | getregister(tokens[1]);
		machine_code = machine_code << 8;
		machine_code = machine_code | atoi(tokens[2]); 
		return machine_code;
	} else {
		printf("Invalid assembler instruction: %s\n", tokens[0]);
		exit(1);
	}

}

vm_word getregister(char* token){
	vm_word register_number;
	if(strcmp("R0",token)==0||strcmp("r0",token)==0){
		register_number = 0;
		return register_number;
	} else if(strcmp("R1",token)==0||strcmp("r1",token)==0){
		register_number = 1;
		return register_number;
	} else if(strcmp("R2",token)==0||strcmp("r2",token)==0){
		register_number = 2;
		return register_number;
	} else if(strcmp("R3",token)==0||strcmp("r3",token)==0){
		register_number = 3;
		return register_number;
	} else {
		printf("Invalid vm register: %s\n", token);
		exit(1);
	}

}
