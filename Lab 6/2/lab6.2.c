#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void matrix_generate(int *matrix, int *rows, int *columns){
    srand(time(0));
    for (int i=0; i<*rows; i++){
        for (int j=0; j<*columns; j++){
            *(matrix+i**columns+j)=rand()%12+(-2);
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
void find_sum_min_oddElem(int *matrix, int *rows, int *columns){
    int min, sum_min=0;
    for (int i=0; i<*rows; i+=2){
        min=*(matrix+i**columns+0);
        for (int j=0; j<*columns; j++){
            if (*(matrix+i**columns+j)<min)
                min=*(matrix+i**columns+j);
        }
        sum_min=sum_min+min;
    }
    printf("The sum of the smallest elements of odd rows: %d\n", sum_min);
}
void find_sum_max_evenElem(int *matrix, int *rows, int *columns){
    int max, sum_max=0;
    for (int i=1; i<*rows; i+=2){
        max=*(matrix+i**columns+0);
        for (int j=0; j<*columns; j++){
            if (*(matrix+i**columns+j)>max)
                max=*(matrix+i**columns+j);
        }
        sum_max=sum_max+max;
    }
    printf("The sum of the largest elements of even rows: %d\n", sum_max);
}
int main(){
    int n=6, m=6, *matrix=(int*)calloc(n*m,sizeof(int));
    printf("Generated matrix: \n");
    matrix_generate(matrix, &n, &m);
    matrix_output(matrix, &n, &m);
    find_sum_min_oddElem(matrix, &n, &m);
    find_sum_max_evenElem(matrix, &n, &m);
    free(matrix);
    system("pause");
    return 0;
}