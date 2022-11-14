#include <stdlib.h>
#include <stdio.h>
int main(){
	int max, min, n=0, i, h=0, u=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		a[i]=rand()%10;
		printf("%d\n", a[i]);
	}
	max=a[0];
	for (i=0; i<n; i++){
 		if (a[i]>max){
 		max=a[i];
		u=i;
		}
	}
	min=a[0];
	for (i=0; i<n; i++){
 		if (a[i]<min){
 		min=a[i];
		h=i;
		}
	}
	a[u]=min;
	a[h]=max;
	printf("Min&Max: %d %d\n", min, max);
	for(i=0; i<n; i++){
		printf("--%d\n", a[i]);
	}
	system("pause");
	return 0;
}