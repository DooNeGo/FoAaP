#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	double x,a,b,c,z,e,y,d;
	printf("Enter x:");
	scanf("%lf",&x);
	printf("Enter y:");
	scanf("%lf",&y);
	printf("Enter z:");
	scanf("%lf",&z);
	
	e=2.7182818284;
	a=pow((9+pow(x-y,2)),1.0/3.0);
	b=x*x+y*y+2;
	c=exp(fabs(x-y))*pow(tan(z),3);
	d=a/b-c;
	
	printf("d:%.5f",d);
	return 0;
}