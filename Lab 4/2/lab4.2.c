#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(){
	float avg, sum=0;
	int n, i, h=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	srand(time(0));
	for(i=0; i<n; i++){
		a[i]=rand()%11;
		printf("%3d", a[i]);
		sum=sum+a[i];
	}
	printf("\n");
	avg=sum/n;
	for (i=0; i<n; i++)
		if (a[i]>avg) h++;
	printf("The number of elements is more than average: %d\n", h);
	system("pause");
	return 0;
}