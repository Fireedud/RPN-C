#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "rpn.h"

float pop(struct Stack *S)
{
	assert(S->top != NULL);
	struct Stack_value *top = S->top;
	float retval = top->value;
	(S->top) = top->prev;
	free(top);
	return retval;
}

void push(struct Stack *S, float n)
{
	struct Stack_value *val = malloc(sizeof(struct Stack_value));
	assert(val != NULL);
	(val->prev) = (S->top);
	(val->value) = n;
	(S->top) = val;
}

int op(char *c)
{
	return ((strcmp(c,"+")!=0)&&(strcmp(c,"-")!=0)&&(strcmp(c,"*")!=0)&&(strcmp(c,"/")!=0));
}

float eval(struct Stack *S, char exp[])
{
	char *val = strtok(exp, " ");
	while(val != NULL){
		if(op(val)){
			push(S, atof(val));
		} else {
			float n = pop(S);
			float m = pop(S);
			float r;
			switch(val[0]){
				case '+':
					r = m+n;
					break;
				case '-':
					r = m-n;
					break;
				case '*':
					r = m*n;
					break;
				case '/':
					assert(n!=0 && "Div by 0");
					r = m/n;
					break;
				default:
					break;
			}
			push(S, r);
		}
		val = strtok(NULL, " ");
	}
	return pop(S);
}

int main(int argc, char *argv[])
{
	char exp[200]; //I will assume this for now
	struct Stack *S = calloc(1, sizeof(struct Stack));
	while(1){
		if(fgets(exp, 200, stdin) != NULL){
			if(exp[0] == '\n') break;
			//eliminate trailing newlines
			int pos = strlen(exp) - 1; 
			if(exp[pos] == '\n') exp[pos] = '\0';
			printf("%f\n", eval(S, exp));
		}
	}

	return 0;
}	
