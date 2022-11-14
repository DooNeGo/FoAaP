#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf_s("Menu:\n");
	printf_s("1 - Summer\n");
	printf_s("2 - Spring\n");
	printf_s("3 - Winter\n");
	printf_s("4 - Fall\n");
	printf_s("What your choice?\n");
	scanf_s("%d", &n);
	switch (n) {
	case 1:
		printf_s("June\n");
		printf_s("July\n");
		printf_s("August\n");
		break;
	case 2:
		printf_s("March\n");
		printf_s("April\n");
		printf_s("May\n");
		break;
	case 3:
		printf_s("December\n");
		printf_s("January\n");
		printf_s("February\n");
		break;
	case 4:
		printf_s("September\n");
		printf_s("October\n");
		printf_s("November\n");
		break;
	default:
		printf_s("Wrong number");
		break;
	}
		return 0;
}
