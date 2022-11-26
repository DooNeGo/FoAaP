#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void nulling_array(int array[], int size){
    for (int i=0; i<size; i++){
        array[i]=0;
    }
}
void matrix_generate(int *matrix, int rows, int coloumns){
    srand(time(0));
    for (int i=0; i<rows; i++){
        for (int j=0; j<coloumns; j++){
            *(matrix+i*coloumns+j)=rand()%12+(-2);
        }
    }
} 
void array_output(int array[], int size){
    for (int i=0; i<size; i++){
        printf("%3d\n", array[i]);
    }
    printf("\n");
}
void matrix_output(int *matrix, int rows, int coloumns){
    for (int i=0; i<rows; i++){
        for (int j=0; j<coloumns; j++){
            printf("%3d", *(matrix+i*coloumns+j));
        }
        printf("\n");
    }
}
void ReapetElemInaRow(int *matrix, int array[], int rows, int coloumns){
    int i, j, k, counter=1;
    for (int i=0; i<rows; i++){
        for (int j=0; j<coloumns-1; j++){
            for (int k=j+1; k<coloumns; k++){
                if (*(matrix+i*coloumns+j)==*(matrix+i*coloumns+k))
                    counter++;
            }
            if (counter>array[i]) array[i]=counter;
            counter=1;
        }
    }
}
void selectionSortbyMaxNofIdenEleminaRow(int arrayForWrite[],int arrayForSort[], int *matrix, int rows, int coloumns){
    int min, i, j, k, temp;
    for (i=0; i<rows-1; i++){
    min=i;
        for (j=i+1; j<rows; j++){
            if (arrayForSort[min]>arrayForSort[j])
                min=j;
        }
        if (min!=i){
            for (k=0; k<coloumns; k++){
                arrayForWrite[k]=*(matrix+i*coloumns+k);
                *(matrix+i*coloumns+k)=*(matrix+min*coloumns+k);
                *(matrix+min*coloumns+k)=arrayForWrite[k];
            }
        }
        temp=arrayForSort[i];
        arrayForSort[i]=arrayForSort[min];
        arrayForSort[min]=temp;
    }
}
void findaColumnNwithoutNegElem(int *matrix, int rows, int coloumns){
    int counter;
    for (int j=0; j<coloumns; j++){
    counter=0;
        for (int i=0; i<=counter; i++){
            if (*(matrix+i*coloumns+j)>=0){
                counter++;
                if (counter==rows){
                    j++;
                    printf("The number of the first column that doesn't contain any negative elements: %d", j);
                    goto jump;
                }
            }
            else if (*(matrix+i*coloumns+j)<0) counter=0;
        }
    }
    printf("\nAll columns contain negative elements \n");
    jump:
    printf("\n");
}
int main(){
    int n, m;
    printf("Enter dimension of 2D matrix: ");
    scanf("%d%d", &n, &m);
    int a[n][m], a1[n], a2[m];
    int *matrix=&a[0][0];
    nulling_array(a1, n);
    nulling_array(a2, m);
    printf("Generated matrix: \n");
    matrix_generate(matrix, n, m);
    matrix_output(matrix, n, m);
    ReapetElemInaRow(matrix, a1, n, m);
    printf("\nThe number of repeated elements in a row: \n");
    array_output(a1, n);
    selectionSortbyMaxNofIdenEleminaRow(a2, a1, matrix, n, m);
    printf("Sorted matrix: \n");
    matrix_output(matrix, n, m);
    printf("\nSorted array: \n");
    array_output(a1, n);
    findaColumnNwithoutNegElem(matrix, n, m);
    system("pause");
    return 0;
}