#include <stdio.h>
#include <string.h>
#include <ctype.h>


int
evaluate(char *s) {
	int n = strlen(s) / 2;
	char *a = s;
	char *b = a + n;

	while (a != b) {
		if (strchr(b, *a)) {
			if (islower(*a)) {
				return (*a - 'a') + 1;
			} else {
				return (*a - 'A') + 27;
			}
		}
		a++;
	}

	return 0;
}

int
main(void) {
	char rucksack[BUFSIZ];
	int sum = 0;

	while (fgets(rucksack, BUFSIZ, stdin)) {
		sum += evaluate(rucksack);
	}

	printf("%d\n", sum);
	return 0;
}
