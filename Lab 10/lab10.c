#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SYSTEM_PAUSE system("pause");
#define GO_TO_NEXT_LINE printf("\n");

float *getMatrix(int rows, int columns)
{
    srand(time(0));
    float *matrix = (float *)malloc(sizeof(int) * rows * columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(matrix + i * columns + j) = -3.0 + 8.0 * rand() / (float)RAND_MAX;
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
        GO_TO_NEXT_LINE
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

void divideRow(float *rowStart, float divider, int columns)
{
    for (int i = 0; i < columns; i++)
    {
        *(rowStart + i) /= divider;
    }
}

float *doGauss(float *matrix, int rows, int columns)
{
    float *newMatrix = copyArray(matrix, rows, columns);
    for (int i = 0; i < rows; i++)
    {
        float divider = *(newMatrix + i * columns + i);
        divideRow(newMatrix + i * columns, divider, columns);
        for (int k = i + 1; k < rows; k++)
        {
            float temp = *(newMatrix + k * columns + i);
            for (int l = 0; l < columns; l++)
            {
                *(newMatrix + k * columns + l) -= *(newMatrix + i * columns + l) * temp;
            }
        }
    }
    return newMatrix;
}

float *getRoots(float *matrix, int rows, int columns)
{
    float *roots = (float *)malloc(sizeof(float) * rows);
    for (int i = rows - 1; i >= 0; i--)
    {
        float temp = 0;
        for (int j = rows - (rows - 1 - i); j < rows; j++)
        {
            temp += *(matrix + i * columns + j) * roots[j];
        }
        roots[i] = *(matrix + i * columns + rows) - temp;
    }
    return roots;
}

void showRoots(float *roots, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("x%d: %f  ", i + 1, roots[i]);
    }
    GO_TO_NEXT_LINE
}

int main()
{
    clock_t timeBefore;
    clock_t timeAfter;

    int rows;
    int columns;
    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &columns);

    float *matrix = getMatrix(rows, columns);
    // {1.14 -2.15 -5.11 -4.16 -0.71 0.81 -0.02 -0.17 0.42 -1.13 7.05 6.15};

    timeBefore = clock();
    float *newMatrix = doGauss(matrix, rows, columns);
    float *roots = getRoots(newMatrix, rows, columns);
    timeAfter = clock();

    double delay = (double)(timeAfter - timeBefore) / CLOCKS_PER_SEC;

    printf("\nEntered matrix:\n");
    showMatrix(matrix, rows, columns);
    printf("\nNew matrix:\n");
    showMatrix(newMatrix, rows, columns);
    printf("\nRoots: ");
    showRoots(roots, rows);
    printf("\n\nDelay : %.30lf seconds\n", delay);

    free(roots);
    free(matrix);
    free(newMatrix);

    SYSTEM_PAUSE
    return 0;
}