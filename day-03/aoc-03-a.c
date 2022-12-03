#include <stdio.h>
#include <string.h>
#include <ctype.h>


int
evaluate(char *s) {
	int n = strlen(s) / 2;
	char *a = s;
	char *b = a + n;
	char *ptr;
	int res;

	while (a != b) {
		ptr = b;
		while (*ptr != '\n') {
			if (*a == *ptr) {
				if (islower(*a)) {
					return (*a - 'a') + 1;
				} else {
					return res = (*a - 'A') + 27;
				}
			}
			ptr++;
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
