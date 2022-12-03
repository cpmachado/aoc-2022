#include <stdio.h>
#include <string.h>
#include <ctype.h>


int
evaluate(char *a, char *b, char *c) {
	char *pb, *pc;

	while (*a != '\n') {
		pb = b;
		while (*pb != '\n') {
			if (*a == *pb) {
				pc = c;
				while (*pc != '\n') {
					if (*a == *pc) {
						if (islower(*a)) {
							return (*a - 'a') + 1;
						} else {
							return (*a - 'A') + 27;
						}
					}
					pc++;
				}
			}
			pb++;
		}
		a++;
	}

	return 0;
}

int
main(void) {
	char rucksack[3][BUFSIZ];
	int sum = 0;

	while (fgets(rucksack[0], BUFSIZ, stdin)
		&& fgets(rucksack[1], BUFSIZ, stdin)
		&& fgets(rucksack[2], BUFSIZ, stdin)) {
		sum += evaluate(rucksack[0], rucksack[1], rucksack[2]);
	}

	printf("%d\n", sum);
	return 0;
}
