#include <stdio.h>
#include <string.h>


#define MARKER_SIZE 4


int
parse(char *s) {
	int b = 0, i, j;
	int n = strlen(s);

	while(b < n - MARKER_SIZE) {
		for (i = 0; i < MARKER_SIZE; i++) {
			for(j = i + 1; j < MARKER_SIZE; j++) {
				if(s[b + i] == s[b + j]) {
					b += i + 1;
					break;
				}
			}

			if (j < MARKER_SIZE) {
				break;
			}
		}

		if(i == MARKER_SIZE) {
			return b + j;
		}
	}

	return -1;
}


int
main(void) {
	int j, n;
	char buffer[10 * BUFSIZ];

	fgets(buffer, 10 * BUFSIZ, stdin);
	n = strlen(buffer);
	if(buffer[n - 1] == '\n') {
		n--;
		buffer[n] = '\0';
	}
	if(!n) {
		return 0;
	}
	j = parse(buffer);
	if(j >= 0) {
		printf("%d\n", j);
	}

	return 0;
}
