#include <stdlib.h>

#include "stack.h"
#include "warehouse.h"

struct Warehouse {
	Stack *v;
	Stack temp;
	unsigned long n;
};

Warehouse
WarehouseCreate(unsigned long n, unsigned long cap) {
	Warehouse w = (Warehouse)malloc(sizeof(struct Warehouse));
	unsigned long i;

	if(!w
		|| !(w->v = (Stack*)malloc(sizeof(Stack) * n))
		|| !(w->temp = StackCreate(cap))) {
		free(w->v);
		free(w);
		return NULL;
	}

	for (i = 0; i < n; i++) {
		if(!(w->v[i] = StackCreate(cap))) {
			for (i--; i >= 0; i--) {
				StackDelete(w->v[i], NULL);
			}
			free(w->temp);
			free(w->v);
			free(w);
			return NULL;
		}
	}

	w->n = n;

	return w;
}

void
WarehouseDelete(Warehouse w) {
	unsigned long i;

	if (!w) {
		return;
	}

	for(i = 0; i < w->n; i++) {
		StackDelete(w->v[i], free);
	}
	free(w->v);
	free(w);
}

unsigned long
WarehouseNStack(Warehouse w) {
	return w->n;
}

int
WarehouseInsert(Warehouse w, unsigned long i, char c) {
	char *v = (char*)malloc(sizeof(char));

	if (!v) {
		return 0;
	}
	*v = c;
	return StackPush(w->v[i - 1], v);
}

void
WarehouseReverse(Warehouse w) {
	unsigned long i;

	for(i = 0; i < w->n; i++) {
		StackReverse(w->v[i]);
	}
}

int
WarehouseMove(Warehouse w, unsigned long o, unsigned long d) {
	char *v = StackPop(w->v[o - 1]);

	if(!v) {
		return 0;
	}

	return StackPush(w->v[d - 1], v);
}

int
WarehouseMoveK(Warehouse w, unsigned long k, unsigned long o, unsigned long d) {
	unsigned long i;
	char *v;

	for (i = 0; i < k; i++) {
		v = StackPop(w->v[o - 1]);
		StackPush(w->temp, v);
	}

	for (i = 0; i < k; i++) {
		v = StackPop(w->temp);
		StackPush(w->v[d - 1], v);
	}

	return 1;
}

char
WarehouseGetTop(Warehouse w, unsigned long i) {
	char c, *v = StackPop(w->v[i - 1]);

	if(!v) {
		return ' ';
	}

	c = *v;
	StackPush(w->v[i - 1], v);
	return c;
}
