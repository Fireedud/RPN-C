#include <stdio.h>

#include "rpn.h"

//Stack will be a global variable for this program

void eval(char *exp[])
{
	char c = '1'; //anything besides '\0' will work
	int i = 0;
	char temp[10]; //I will assume that for now
	while(c != '\0'){
		for(i=0; c != ' '; c = exp[i++]){
			temp[i] = c;
		}
		//PSUEDOCODE:
		//If int(temp) {
		//    push(stack, temp);
		//    }
		//Else doop
	}
}
