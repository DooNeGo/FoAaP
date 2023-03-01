#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float *getMatrix(int rows, int columns)
{
    float *matrix = (float *)malloc(sizeof(int) * rows * columns);
    printf("Enter matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%f", (matrix + i * columns + j));
        }
    }
    return matrix;
}

void showMatrix(float *matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f", *(matrix + i * columns + j));
        }
        printf("\n");
    }
}

float *copyArray(float *source, int rows, int columns)
{
    float *matrix = (float *)malloc(sizeof(int) * rows * columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(matrix + i * columns + j) = *(source + i * columns + j);
        }
    }
    return matrix;
}

void divideRow(float *matrix, float divider, int columns, int row)
{
    for (int i = 0; i < columns; i++)
    {
        *(matrix + row * columns + i) /= divider;
    }
}

float *getMultipliedRow(float *matrix, int row, int columns, int rows, int *counter)
{
    float *tempArray = (float *)malloc(sizeof(float) * columns);
    for (; *counter < pow(2, rows - 2) + 1;)
    {
        for (int j = 0; j < columns; j++)
        {
            tempArray[j] = *(matrix + row * columns + j) * *(matrix + *counter * columns + row);
        }
        (*counter)++;
        return tempArray;
    }
    return tempArray;
}

float *doGauss(float *matrix, int rows, int columns)
{
    float *newMatrix = copyArray(matrix, rows, columns);
    for (int i = 0; i < rows; i++)
    {
        int counter = i + 1;
        float temp = *(newMatrix + i * columns + i);
        divideRow(newMatrix, temp, columns, i);
        // showMatrix(newMatrix, 3, 4);
        for (int k = i + 1; k < rows; k++)
        {
            float *tempArray = getMultipliedRow(newMatrix, i, columns, rows, &counter);
            // printf("\n");
            // showMatrix(tempArray, 1, 4);
            // printf("%d\n", i);
            for (int l = 0; l < columns; l++)
            {
                *(newMatrix + k * columns + l) -= tempArray[l];
            }
        }
    }
    return newMatrix;
}

float *getRoots(float *matrix, int rows, int columns)
{
    float *roots = (float *)malloc(sizeof(float) * rows);
    int k = columns - 1;
    for (int i = rows - 1; i >= 0; i--)
    {
        float temp = 0;
        for (int j = k; j < columns - 1; j++)
        {
            temp += *(matrix + i * columns + j) * roots[j];
        }
        k--;
        roots[i] = *(matrix + i * columns + columns - 1) - temp;
    }
    return roots;
}

int main()
{
    int rows;
    int columns;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &columns);

    float *matrix = getMatrix(rows, columns);
    // float array[12] = {1.14 -2.15 -5.11 -4.16 -0.71 0.81 -0.02 -0.17 0.42 -1.13 7.05 6.15};
    float *newMatrix = doGauss(matrix, rows, columns);

    printf("\nEntered matrix:\n");
    showMatrix(matrix, rows, columns);
    printf("New matrix:\n");
    showMatrix(newMatrix, rows, columns);

    //float x3 = *(newMatrix + 2 * columns + 3);
    //float x2 = *(newMatrix + 1 * columns + 3) - *(newMatrix + 1 * columns + 2) * x3;
    //float x1 = *(newMatrix + 0 * columns + 3) - *(newMatrix + 0 * columns + 1) * x2 - *(newMatrix + 0 * columns + 2) * x3;
    //printf("x1: %f, x2: %f, x3: %f\n", x1, x2, x3);

    float *roots = getRoots(newMatrix, rows, columns);
    for (int i = 0; i < rows; i++)
    {
        printf("x%d: %f  ", i + 1, roots[i]);
    }
    printf("\n");

    free(matrix);
    free(newMatrix);
    system("pause");
    return 0;
}