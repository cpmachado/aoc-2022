#include <stdio.h>


int
main(void) {
	char buffer[BUFSIZ];
	int max = 0;
	int reading;
	int acc = 0;

	while(fgets(buffer, BUFSIZ, stdin)) {
		if(sscanf(buffer, "%d", &reading) == 1) {
			acc += reading;
		} else {
			if(max < acc) {
				max = acc;
			}
			acc = 0;
		}
	}

	if(max < acc) {
		max = acc;
	}

	printf("%d\n", max);

	return 0;
}
