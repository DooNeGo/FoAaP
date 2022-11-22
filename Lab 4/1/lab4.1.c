#include <stdlib.h>
#include <stdio.h>
int main(){
	int max, min, n, i, h=0, u=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		a[i]=rand()%10;
		printf("%3d", a[i]);
	}
	max=a[0];
	for (i=1; i<n; i++){
 		if (a[i]>max){
 			max=a[i];
			u=i;
		}
	}
	min=a[0];
	for (i=1; i<n; i++){
 		if (a[i]<min){
 			min=a[i];
			h=i;
		}
	}
	a[u]=min;
	a[h]=max;
	printf("\n\nMin&Max: %d %d\n", min, max);
    printf("\nModified array: \n");
	for(i=0; i<n; i++) printf("%3d", a[i]);
	printf("\n");
	system("pause");
	return 0;
}