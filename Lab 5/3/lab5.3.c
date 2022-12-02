#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void findNum_firstRow_ordered_ascending_order(int *matrix, int *rows, int *columns, int *row_num){
    int counter, i, j;
    for (i=0; i<*rows; i++){
        counter=0;
        for (j=0; j<=counter; j++){
            if (*(matrix+i**columns+j)<*(matrix+i**columns+j+1)){
                counter++;
                if (counter==*columns-1){
                    *row_num=i;
                    goto jump;
                }
            }
            else if (*(matrix+i**columns+j)>*(matrix+i**columns+j+1)){
                counter=0;
            }
        }
    }
    jump:;
}
void matrix_generate(int *matrix, int *rows, int *columns, int *row_num, int *repeats){
    srand(time(0));
    int i, j;
    while (*row_num==-1){
        *repeats=*repeats+1;
        for (i=0; i<*rows; i++){
            for (j=0; j<*columns; j++){
                *(matrix+i**columns+j)=rand()%14-2;
            }
        }
        findNum_firstRow_ordered_ascending_order(matrix, rows, columns, row_num);
    }
}
void matrix_output(int *matrix, int *rows, int *columns){
    for (int i=0; i<*rows; i++){
        for (int j=0; j<*columns; j++){
            printf("%3d", *(matrix+i**columns+j));
        }
        printf("\n");
    }
}
void reverse_rowElem(int *matrix, int *columns, int *row_num){
    int temp, i=*row_num, j, k;
    for (j=0; j<*columns/2.0; j++){
        k=*columns-(j+1);
        if (k!=j){
            temp=*(matrix+i**columns+j);
            *(matrix+i**columns+j)=*(matrix+i**columns+k);
            *(matrix+i**columns+k)=temp;
        }
    }
}
int main(){
    int n, m, row_num=-1, repeats=0;
    printf("Enter dimension of 2D matrix: ");
    scanf("%d%d", &n, &m);
    int *matrix=(int*)calloc(n*m, sizeof(int));
    matrix_generate(matrix, &n ,&m, &row_num, &repeats);
    printf("Generated matrix: \n");
    matrix_output(matrix, &n, &m);
    printf("Row number whose elements are sorted in ascending order: %d\n", row_num+1);
    printf("New matrix: \n");
    reverse_rowElem(matrix, &m, &row_num);
    matrix_output(matrix, &n, &m);
    printf("Number of generated arrays: %d\n", repeats);
    system("pause");
    return 0;
}