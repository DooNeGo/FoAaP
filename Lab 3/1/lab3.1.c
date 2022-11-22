#include <stdio.h>
#include <stdlib.h>
int main(void){
	float a, b=20, n;
	printf("Enter the current year: ");
	scanf("%f", &a);
	for(n=1626; n<=a; n++) b=b+b*0.04;
	printf("Cost of capital today: %0.f\n", b);
	system("pause");
	return 0;
}