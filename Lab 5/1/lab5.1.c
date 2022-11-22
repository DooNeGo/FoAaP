#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int n, m, i, j, k=0, v=1, h=0;
  printf("Enter dimension of 2D matrix: ");
  scanf("%d %d", &n, &m);
  int a[n][m], u[n], s[m];
  for (i=0; i<n; i++) u[i]=0;
  for (i=0; i<m; i++) s[i]=0;
  // Генерация двумерного массива
  printf("Generated matrix: \n");
  for (i=0; i<n; i++){
    for (j=0; j<m; j++){
      a[i][j]=rand()%12+(-2);
      printf("%3d",a[i][j]);
    }
    printf("\n");
  }
  // Определение макс. кол-ва одинаковый элемен. в строках
  for (i=0; i<n; i++){
    for (j=0; j<m-1; j++){
      for (k=j+1; k<m; k++){
        if (a[i][j]==a[i][k]) v++;
      }
      if (v>u[i]) u[i]=v;
      v=1;
    }
  }
  printf("\nThe number of repeated elements in a row: \n");
  for (i=0; i<n; i++)
    printf("%d\n",u[i]);
  // Сортировка selectionSort
  for (i=0; i<n-1; i++){
    v=i;
    for (j=i+1; j<n; j++){
      if (u[v]>u[j]) v=j;
    }
    if (v!=i){
      for (k=0; k<m; k++){
        s[k]=a[i][k];
        a[i][k]=a[v][k];
        a[v][k]=s[k];
      }
      h=u[i];
      u[i]=u[v];
      u[v]=h;
    }
  }
  printf("\nSorted Matrix: \n");
  for (i=0; i<n; i++){
    for (j=0; j<m; j++){
      printf("%3d",a[i][j]);
    }
  printf("\n");
  }
  printf("\nSorted array: \n");
  for (i=0; i<n; i++) printf("%d\n", u[i]);
  // Определение номера первого столбца без отрицательных элементов
  for (j=0; j<m; j++){
    k=0;
    for (i=0; i<=k; i++){
      if (a[i][j]>=0){
        k++;
        if (k==n){
          j++;
          printf("The number of the first column that doesn't contain any negative elements: %d\n", j);
          goto jump;
        }
      }
      else if (a[i][j]<0) k=0;
    }
  }
  printf("\nAll columns contain negative elements \n");
  jump:
  system("pause");
  return 0;
}