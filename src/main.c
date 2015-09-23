#include<stdio.h>
#include<vm.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	vm_word prog[] = {0x5001,0x5102,0x4201};
	eval(prog);
	return 0;
}
