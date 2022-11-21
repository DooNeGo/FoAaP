#include <stdio.h>
#include <stdlib.h>
#include <ctime>
int main(){
  srand(time(0));
  int n, m, i, j, k=0, v=1;
  printf("Enter n and m: ");
  scanf("%d %d", &n, &m);
  int a[n][m], u[n], s[m];
  for(i=0; i<n; i++) u[i]=0;
  printf("Generated matrix: \n");
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      a[i][j]=rand()%13+(-3);
      printf("%3d",a[i][j]);
    }
    printf("\n");
  }
  for(i=0; i<n; i++){
    for(j=0; j<m-1; j++){
      for(k=j+1; k<m; k++){
        if(a[i][j]==a[i][k]) v++;
      }
      if(v>u[i]) u[i]=v;
      v=1;
    }
  }
  printf("\nThe number of repeated elements in a row: \n");
  for(i=0; i<n; i++)
    printf("%d\n",u[i]);
  for(i=0; i<n-1; i++){
    for(v=i+1; v<n; v++){
      if (u[i]>u[v]){
        for(k=0; k<m; k++){
          s[k]=a[i][k];
          a[i][k]=a[v][k];
          a[v][k]=s[k];
        }
      }
    }
  }
  printf("\nSorted Matrix: \n");
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      printf("%3d",a[i][j]);
    }
  printf("\n");
  }
  for(j=0; j<=i; j++){
    for(i=0; i<k; i++){
      if(a[i][j]>0){
        k++;
        if(k=m){
          j++;
          printf("The number of the column that doesn't contain any negative elements: %d\n", j);
          break;
        }
      }
      else if(j){
        printf("\nNo negative elements\n");
        break;
      }
      else if(a[i][j]<0) k=0;
    }
  }
  system("pause");
  return 0;
}