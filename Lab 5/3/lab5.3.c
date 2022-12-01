#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int findNum_firstRow_ordered_ascending_order(int *matrix, int *rows, int *columns){
    int counter, i, j, k=-1, *row_num=&k;
    for (i=0; i<*rows; i++){
        counter=0;
        for (j=0; j<=counter; j++){
            if (*(matrix+i**columns+j)<*(matrix+i**columns+j+1)){
                counter++;
                if (counter==*columns-1){
                    *row_num=i;
                    i++;
                    printf("Row number whose elements are sorted in ascending order: %d\n", i);
                    goto jump;
                }
            }
            else if (*(matrix+i**columns+j)>*(matrix+i**columns+j+1)){
                counter=0;
            }
        }
    }
    jump:
    return *row_num;
}
int matrix_generate(int *matrix, int *rows, int *columns){
    srand(time(0));
    int row_num=-1, i, j;
    while (row_num==-1){
        for (i=0; i<*rows; i++){
            for (j=0; j<*columns; j++){
                *(matrix+i**columns+j)=rand()%14-2;
            }
        }
        row_num=findNum_firstRow_ordered_ascending_order(matrix, rows, columns);
    }
    return row_num;
}
void matrix_output(int *matrix, int *rows, int *columns){
    for (int i=0; i<*rows; i++){
        for (int j=0; j<*columns; j++){
            printf("%3d", *(matrix+i**columns+j));
        }
        printf("\n");
    }
}
void reverse_orderElem(int *matrix, int *columns, int *row_num){
    int temp, j, i=*row_num, k, max;
    for (j=0; j<*columns-1; j++){
        max=j;
        for (k=j+1; k<*columns; k++){
            if (*(matrix+i**columns+max)<*(matrix+i**columns+k)){
                max=k;
            }
        }
        if (max!=i){
            temp=*(matrix+i**columns+j);
            *(matrix+i**columns+j)=*(matrix+i**columns+max);
            *(matrix+i**columns+max)=temp;
        }
    }
}
int main(){
    int n, m, row_num;
    printf("Enter dimension of 2D matrix: ");
    scanf("%d%d", &n, &m);
    int a[n][m], a1[m], *matrix=&a[0][0];
    row_num=matrix_generate(matrix, &n ,&m);
    printf("Generated matrix: \n");
    matrix_output(matrix, &n, &m);
    printf("New matrix: \n");
    reverse_orderElem(matrix, &m, &row_num);
    matrix_output(matrix, &n, &m);
    system("pause");
    return 0;
}