#include <stdio.h>

#include "rpn.h"

//Stack will be a global variable for this program

void push(temp)
{
}

void eval(char exp[])
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
		//    push(temp);
		//    }
		//Else doop
	}
}

int main(int argc, char *argv[])
{
	char exp[200]; //I will assume this for now
	while(1){
		scanf("%s", &exp);
		exp[199] = '\0'; //just in case
		eval(exp);
		printf("%i", Stack.top.value);
	}

	return 0;
}	
