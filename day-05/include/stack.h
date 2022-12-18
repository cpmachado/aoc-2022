typedef struct Stack *Stack;


Stack StackCreate(unsigned long n);

void StackDelete(Stack s, void (*deto)(void*));

int StackPush(Stack s, void* value);

void* StackPop(Stack s);

unsigned long StackCapacity(Stack s);

unsigned long StackHeight(Stack s);

void StackReverse(Stack s);
