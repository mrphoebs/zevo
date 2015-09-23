vm: src/vm.c include/vm.h include/instructions.h include/registers.h
	gcc -Wall -std=c11 -o zevo src/vm.c src/main.c src/instructions.c src/assembler.c -I ./include 

