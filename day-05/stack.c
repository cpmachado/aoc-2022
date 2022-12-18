#include <stdlib.h>

#include "stack.h"


struct Stack {
	unsigned long n, h;
	void** values;
};


Stack
StackCreate(unsigned long n) {
	Stack s = (Stack)malloc(sizeof(struct Stack));

	if(!s || !(s->values = (void**)malloc(sizeof(void*)*n))) {
		free((void*)s);
		return NULL;
	}

	s->n = n;
	s->h = 0;
	return s;
}

void
StackDelete(Stack s, void (*deto)(void*)) {
	unsigned long i;

	if (deto) {
		for (i = 0; i < s->h; i++) {
			deto(s->values[i]);
		}
	}

	free((void*)s->values);
	free((void*)s);
}

int
StackPush(Stack s, void* value) {
	if (s->h == s->n) {
		return 0;
	}

	s->values[s->h] = value;
	s->h++;

	return 1;
}

void*
StackPop(Stack s) {
	if (s->h) {
		s->h--;
		return s->values[s->h];
	}
	return NULL;
}

unsigned long
StackCapacity(Stack s) {
	return s->n;
}

unsigned long
StackHeight(Stack s) {
	return s->h;
}

void
StackReverse(Stack s) {
	unsigned long i;
	void* aux;

	for (i = 0; i < s->h / 2; i++) {
		aux = s->values[i];
		s->values[i] = s->values[s->h - i - 1];
		s->values[s->h - i - 1] = aux;
	}
}
