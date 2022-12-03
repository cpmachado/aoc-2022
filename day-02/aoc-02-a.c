#include <stdio.h>


int
evaluate(char opponent, char player) {
	int nO = opponent - 'A';
	int nP = player - 'X';
	int shape = nP + 1;

	if(nO == nP) {
		return shape + 3;
	}
	if((nO + 1) % 3 == nP) {
		return shape + 6;
	}

	return shape;
}

int
main(void) {
	char buffer[BUFSIZ];
	int sum = 0;
	char opponent, player;

	while(fgets(buffer, BUFSIZ, stdin)) {
		if(sscanf(buffer, "%c %c", &opponent, &player) == 2) {
			sum += evaluate(opponent, player);
		}
	}

	printf("%d\n", sum);
	return 0;
}
