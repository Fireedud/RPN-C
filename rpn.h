struct Stack_value{
	int value;
	Stack_value* prev;
};

struct Stack{
	Stack_value* top;
}

int pop(Stack);
void push(Stack, int);
