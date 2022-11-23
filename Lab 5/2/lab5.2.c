#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int i, a[6][6], j, min, max, sum_min=0, sum_max=0;
    srand(time(0));
    printf("Generated matrix: \n");
    for (i=0; i<6; i++){
        for (j=0; j<6; j++){
            a[i][j]=rand()%10;
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<6; i=i+2){
        min=a[i][0];
        for (j=0; j<6; j++){
            if (a[i][j]<min)
                min=a[i][j];
        }
        sum_min=sum_min+min;
    }
    for (i=1; i<6; i=i+2){
        max=a[i][0];
        for (j=0; j<6; j++){
            if (a[i][j]>max)
                max=a[i][j];
        }
        sum_max=sum_max+max;
    }
    printf("The sum of the smallest elements of odd rows: %d\n", sum_min);
    printf("The sum of the largest elements of even rows: %d\n", sum_max);
    system("pause");
    return 0;
}