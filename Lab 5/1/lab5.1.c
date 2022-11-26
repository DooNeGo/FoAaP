#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void array_nulling(int array[], int size){
    for (int i=0; i<size; i++){
        array[i]=0;
    }
}
void matrix_generate(int *matrix, int rows, int columns){
    srand(time(0));
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            *(matrix+i*columns+j)=rand()%12+(-2);
        }
    }
} 
void array_output(int array[], int size){
    for (int i=0; i<size; i++){
        printf("%3d\n", array[i]);
    }
    printf("\n");
}
void matrix_output(int *matrix, int rows, int columns){
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            printf("%3d", *(matrix+i*columns+j));
        }
        printf("\n");
    }
}
void reapeat_elemNum_row(int *matrix, int array[], int rows, int columns){
    int i, j, k, counter=1;
    for (i=0; i<rows; i++){
        for (j=0; j<columns-1; j++){
            for (k=j+1; k<columns; k++){
                if (*(matrix+i*columns+j)==*(matrix+i*columns+k))
                    counter++;
            }
            if (counter>array[i]) array[i]=counter;
            counter=1;
        }
    }
}
void selectionSort_maxNum_identicElem_row(int array_temp[],int array_sort[], int *matrix, int rows, int columns){
    int min, i, j, k, temp;
    for (i=0; i<rows-1; i++){
    min=i;
        for (j=i+1; j<rows; j++){
            if (array_sort[min]>array_sort[j])
                min=j;
        }
        if (min!=i){
            for (k=0; k<columns; k++){
                array_temp[k]=*(matrix+i*columns+k);
                *(matrix+i*columns+k)=*(matrix+min*columns+k);
                *(matrix+min*columns+k)=array_temp[k];
            }
        }
        temp=array_sort[i];
        array_sort[i]=array_sort[min];
        array_sort[min]=temp;
    }
}
void find_columnNum_wthout_negElem(int *matrix, int rows, int columns){
    int counter;
    for (int j=0; j<columns; j++){
    counter=0;
        for (int i=0; i<=counter; i++){
            if (*(matrix+i*columns+j)>=0){
                counter++;
                if (counter==rows){
                    j++;
                    printf("The number of the first column that doesn't contain any negative elements: %d", j);
                    goto jump;
                }
            }
            else if (*(matrix+i*columns+j)<0) counter=0;
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
    array_nulling(a1, n);
    printf("Generated matrix: \n");
    matrix_generate(matrix, n, m);
    matrix_output(matrix, n, m);
    reapeat_elemNum_row(matrix, a1, n, m);
    printf("\nThe number of repeated elements in a row: \n");
    array_output(a1, n);
    selectionSort_maxNum_identicElem_row(a2, a1, matrix, n, m);
    printf("Sorted matrix: \n");
    matrix_output(matrix, n, m);
    printf("\nSorted array: \n");
    array_output(a1, n);
    find_columnNum_wthout_negElem(matrix, n, m);
    system("pause");
    return 0;
}