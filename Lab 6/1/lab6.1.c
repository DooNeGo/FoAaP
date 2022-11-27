#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void array_output(float *array, int *size){
    for (int i=0; i<*size; i++){
        printf("%6.2f", *(array+i));
    }
    printf("\n");
}
void array_generate(float *array, int *size){
	srand(time(0));
    printf("Generated array: \n");
	for(int i=0; i<*size; i++){
		*(array+i)=-3.0+8.0*rand()/(float)RAND_MAX;
	}
}
void find_max_elem(float *array, int *size){
	float max=*array;
	for (int i=0; i<*size; i++){
 		if (*(array+i)>max){
 			max=*(array+i);
		}
	}
    printf("Max element of array: %0.2f\n", max);
}
int *find_lastNum_positive_num(float *array, int *size){
    int *numLast_positive_num;
    for (int i=0; i<*size; i++){
        if ((*(array+i))>0){
            numLast_positive_num=&i;
        }
    }
    printf("Number of the last positive number: %d\n", *numLast_positive_num);
    return numLast_positive_num;
}
void find_sumElem_lstPositive_num(float *array, int *size){
    float sum=0;
    int *numLast_positive_num=find_lastNum_positive_num(array, size);
    for (int i=0; i<*numLast_positive_num-1; i++){
        sum=sum+*(array+i);
    }
    printf("The sum of the array elements up to the last positive element: %0.2f\n", sum);
}
int main(){
    int n;
    printf("Enter array dimension: ");
    scanf("%d", &n);
    float a[n];
    array_generate(a, &n);
    array_output(a, &n);
    find_max_elem(a, &n);
    find_sumElem_lstPositive_num(a, &n);
    system("pause");
    return 0;
}