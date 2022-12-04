#include <stdio.h>


int
evaluate(char *s) {
	int a, b, c, d;

	if (sscanf(s, "%d-%d,%d-%d", &a, &b, &c, &d) != 4) {
		return 0;
	}

	return (a <= c && d <= b) || (c <= a && b <= d);
}

int
main(void) {
	char buffer[BUFSIZ];
	int sum;


	while (fgets(buffer, BUFSIZ, stdin)) {
		sum += evaluate(buffer);
	}

	printf("%d\n", sum);

	return 0;
}
