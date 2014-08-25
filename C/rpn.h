struct Stack_value{
	float value;
	struct Stack_value* prev;
};

struct Stack{
	struct Stack_value* top;
};

float pop(struct Stack*);
void push(struct Stack*, float);
