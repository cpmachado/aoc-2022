#include <stdio.h>


int
evaluate(char opponent, char res) {
	int nO = opponent - 'A';
	int nRes = res - 'X';
	int wp = nRes * 3;
	return wp + 1 + (nO + (nRes + 2) % 3) % 3;
}

int
main(void) {
	char buffer[BUFSIZ];
	int sum = 0;
	char opponent, res;

	while(fgets(buffer, BUFSIZ, stdin)) {
		if(sscanf(buffer, "%c %c", &opponent, &res) == 2) {
			sum += evaluate(opponent, res);
		}
	}

	printf("%d\n", sum);
	return 0;
}
