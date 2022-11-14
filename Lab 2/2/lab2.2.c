#include <stdlib.h>
#include <stdio.h>

int main() {
	int a, b, c, N;
	printf_s("Enter a:");
	scanf_s("%d", &a);
	printf_s("Enter b:");
	scanf_s("%d", &b);
	printf_s("Enter c:");
	scanf_s("%d", &c);
	printf_s("Enter N:");
	scanf_s("%d", &N);

	if (a % N == 0 && b % N == 0 && c % N == 0)
		printf_s("N is the divisor of all numbers");
	else if (a % N != 0 && b % N != 0 && c % N != 0)
		printf_s("N isn't the divisor of all numbers");
	else {
		if (a % N == 0)
			printf_s("N is divisor a, ");
		else printf_s("N isn't divisor a, ");
		if (b % N == 0)
			printf_s("N is divisor b, ");
		else printf_s("N isn't divisor b, ");
		if (c % N == 0)
			printf_s("N is divisor c, ");
		else printf_s("N isn't divisor c, ");
	}
	return 0;
}
