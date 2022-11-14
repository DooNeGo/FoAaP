#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,c,d,f,g;
	printf("Enter a:");
	scanf("%f",&a);
	printf("Enter b:");
	scanf("%f",&b);
	printf("Enter c:");
	scanf("%f",&c);
	printf("Enter d:");
	scanf("%f",&d);
	printf("Enter f:");
	scanf("%f",&f);
	printf("Enter g:");
	scanf("%f",&g);
	
	if(a+b+c==d+f+g) printf("Lucky ticket");
		else printf("Bad ticket");
		
	return 0;
}