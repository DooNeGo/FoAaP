#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL,"English");
	float x,a;
	printf("Enter x:");
	scanf("%f",&x);
	a=16*x*x;
	printf("you entered a:%0.3f",a);
}

	