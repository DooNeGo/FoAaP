#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void matrix_generate(int *matrix, int *rows, int *columns){
    srand(time(0));
    for (int i=0; i<*rows; i++){
        for (int j=0; j<*columns; j++){
            *(matrix+i**columns+j)=rand()%11-2;
        }
    }
}
void matrix_input_user(int *matrix, int *rows, int *columns){
    for (int i=0; i<*rows; i++){
        for (int j=0; j<*columns; j++){
            scanf("%d", (matrix+i**columns+j));
        }
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
int findNum_firstRow_ordered_ascending_order(int *matrix, int *rows, int *columns){
    int counter, i, j, *row_num;
    for (i=0; i<*rows; i++){
        counter=0;
        for (j=0; j<=counter; j++){
            if (*(matrix+i**columns+j)<*(matrix+i**columns+j+1)){
                counter++;
                if (counter==*columns-1){
                    *row_num=i;
                    i++;
                    printf("\nRow number whose elements are sorted in ascending order: %d\n", i);
                    goto jump;
                }
            }
            else if (*(matrix+i**columns+j)>*(matrix+i**columns+j+1)){
                counter=0;
            }
        }
    }
    printf("\nNone of the rows are sorted in ascending order");
    *row_num=-1;
    jump:
    printf("\n");
    return *row_num;
}
void reverse_orderElem(int *matrix, int *columns, int *row_num){
    int temp, j, i=*row_num, k, max;
    for (j=0; j<*columns-1; j++){
        max=j;
        for (k=j+1; k<*columns; k++){
            if (*(matrix+i**columns+j)<*(matrix+i**columns+k)){
                max=k;
            }
        }
        if (max!=j){
            temp=*(matrix+i**columns+j);
            *(matrix+i**columns+j)=*(matrix+i**columns+max);
            *(matrix+i**columns+max)=temp;
        }
    }
}
int main(){
    int n, m, row_num, select_num;
    printf("Enter dimension of 2D matrix: ");
    scanf("%d%d", &n, &m);
    int a[n][m], a1[m], *matrix=&a[0][0];
    printf("1 - Enter matrix manually\n2 - Generate matrix\nEnter the value of your choice: ");
    scanf("%d", &select_num);
    switch (select_num){
    case 1:
        printf("Enter %d-by-%d Matrix Values: \n", n, m);
        matrix_input_user(matrix, &n, &m);
        printf("\nEntered matrix: \n");
        break;
    case 2:
        printf("Generated matrix: \n");
        matrix_generate(matrix, &n ,&m);
        break;
    default:
        printf("Wrong number");
        break;
    }
    matrix_output(matrix, &n, &m);
    row_num=findNum_firstRow_ordered_ascending_order(matrix, &n, &m);
    if (row_num!=-1){
        printf("New matrix: \n");
        reverse_orderElem(matrix, &m, &row_num);
        matrix_output(matrix, &n, &m);
    }
    system("pause");
    return 0;
}