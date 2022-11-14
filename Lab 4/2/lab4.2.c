#include <stdlib.h>
#include <stdio.h>
int main(){
	int avg=0, sum=0, n=0, i, h=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		a[i]=rand()%10;
		printf("%d\n", a[i]);
	}
	for (i=0; i<n; i++) sum=sum+a[i];
	avg=sum/n;
	for (i=0; i<n; i++)
		if (a[i]>avg) h++;
	printf("The number of elements is more than average: %d\n", h);
	system("pause");
	return 0;
}