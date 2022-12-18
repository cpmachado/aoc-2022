#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "warehouse.h"


void
parseRow(Warehouse w, char *s) {
	unsigned long i, n = WarehouseNStack(w);

	for (i = 0; i < n; i++) {
		if (*s == '[') {
			WarehouseInsert(w, i + 1, s[1]);
		}
		s += 4;
	}
}


Warehouse
readStacks()  {
	char buffer[BUFSIZ];
	unsigned long n;
	Warehouse w;

	fgets(buffer, BUFSIZ, stdin);
	n = strlen(buffer) / 4;
	w = WarehouseCreate(n, BUFSIZ);

	parseRow(w, buffer);

	while (fgets(buffer, BUFSIZ, stdin)) {
		if (buffer[0] == '\n')  {
			break;
		}
		parseRow(w, buffer);
	}

	WarehouseReverse(w);

	return w;
}

void
execCommand(Warehouse w, unsigned long n, unsigned long o, unsigned long d) {
	unsigned long i;

	for (i = 0; i < n; i++) {
		WarehouseMove(w, o, d);
	}
}

void
readCommands(Warehouse w) {
	char buffer[BUFSIZ];
	unsigned long n, o, d;

	while(fgets(buffer, BUFSIZ, stdin)) {
		if (sscanf(buffer, "move %lu from %lu to %lu", &n, &o, &d) == 3) {
			execCommand(w, n, o, d);
		}

	}

}

void
printTop(Warehouse w) {
	unsigned long i, n = WarehouseNStack(w);

	for (i = 1; i <= n; i++) {
		printf("%c", WarehouseGetTop(w, i));
	}
	printf("\n");
}


int
main(void) {
	Warehouse w = readStacks();
	readCommands(w);
	printTop(w);
	WarehouseDelete(w);
	return 0;
}
