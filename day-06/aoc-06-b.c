#include <stdio.h>
#include <string.h>


#define MARKER_SIZE 14


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
	int i = 0, j, n;
	char buffer[BUFSIZ];
	char *s = buffer;

	while(fgets(s, BUFSIZ - MARKER_SIZE, stdin)) {
		j = parse(buffer);
		if(j >= 0) {
			break;
		}
		n = strlen(s);
		if (n > MARKER_SIZE) {
			memcpy(buffer, &s[n - 1 - MARKER_SIZE], MARKER_SIZE);
		} else {
			break;
		}
		i += n;
		s = buffer + MARKER_SIZE;
	}

	if(j >= 0) {
		printf("%d\n", i + j);
	}

	return 0;
}
