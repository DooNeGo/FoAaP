#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int i, a[6][6], j, min=0, max=0, summin, summax;
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
        min=a[0][0];
        for (j=0; j<6; j++){
            if (a[i][j]<min)
                min=a[i][j];
        }
        summin=summin+min;
    }
    for (i=1; i<6; i=i+2){
        max=a[0][0];
        for (j=0; j<6; j++){
            if (a[i][j]>max)
                max=a[i][j];
        }
        summax=summax+max;
    }
    printf("The sum of the smallest elements of odd rows: %d\n", summin);
    printf("The sum of the largest elements of even rows: %d\n", summax);
    system("pause");
    return 0;
}