#include <stdio.h>
#include <stdlib.h>

int main(void){
	float a,b,c,n;
	printf("Enter the current year: ");
	scanf("%f", &a);
	b=20;
	for(n=1626; n<=a; n++)
	{
		b=b+b*0.04;
	}
	printf("b: %0.f\n", b);
	system("pause");
	return 0;
}