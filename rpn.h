struct Stack_value{
	int value;
	struct Stack_value* prev;
};

struct Stack{
	struct Stack_value* top;
};

int pop(struct Stack*);
void push(struct Stack*, int);
