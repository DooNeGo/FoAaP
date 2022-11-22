#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b,c,d,F,R=100;
	for(a=0;a<=2;a++){
		for(b=0;b<=5;b++){
			for(c=0;c<=20;c++){
				for(d=0;d<=50;d++){
					if(R==(a*50+b*20+c*5+d*2))
						F++;
				}
			}
		}
	}
	printf("Number of dialing methods: %d\n", F);
	system("pause");
	return 0;
}