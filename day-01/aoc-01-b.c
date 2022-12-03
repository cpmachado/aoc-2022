#include <stdio.h>

void
updateMax(int v[], int n, int acc) {
	int i, j;

	for(i = 0; i < n; i++) {
		if(v[i] < acc) {
			for(j = n - 1; j > i; j--) {
				v[j] = v[j - 1];
			}
			v[i] = acc;
			break;
		}
	}
}


int
main(void) {
	char buffer[BUFSIZ];
	int v[3] = { 0, 0, 0 };
	int reading;
	int acc = 0;
	int i;

	while(fgets(buffer, BUFSIZ, stdin)) {
		if(sscanf(buffer, "%d", &reading) == 1) {
			acc += reading;
		} else {
			updateMax(v, 3, acc);
			acc = 0;
		}
	}

	updateMax(v, 3, acc);
	acc = 0;

	for(i = 0; i < 3; i++) {
		acc += v[i];
	}

	printf("%d\n", acc);

	return 0;
}
