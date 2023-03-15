#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SYSTEM_PAUSE system("pause")
#define GO_TO_NEXT_LINE printf("\n")

enum
{
    SUCCESSFUL_COMPLETION = 0,
    DOES_NOT_CONVERGE = 1,
    CONVERGES = 0,
    CONVERGES_BUT_THE_SEQUENCE_OF_ROWS_IS_NOT_CORRECT = 2,
};

float *getMatrix(int rows, int columns)
{
    //srand(time(0));
    float *matrix = (float *)malloc(sizeof(float) * rows * columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            //*(matrix + i * columns + j) = -3.0 + 8.0 * rand() / (float)RAND_MAX;
            scanf("%f", matrix + i * columns + j);
        }
    }
    return matrix;
}

void nullArray(float *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void showMatrix(float *matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%7.2f", *(matrix + i * columns + j));
        }
        GO_TO_NEXT_LINE;
    }
}

float *getStartRoots(float *matrix, int rows, int columns)
{
    float *roots = (float *)malloc(sizeof(float) * rows);
    for (int i = 0; i < rows; i++)
    {
        // roots[i] = matrix[i * columns + columns - 1];
        roots[i] = 0;
    }
    return roots;
}

float getMaxElement(float *array, int size, int *outMaxElementNumber)
{
    float max = array[0];
    *outMaxElementNumber = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
            *outMaxElementNumber = i;
        }
    }
    return max;
}

int checkConvergence(float *matrix, int rows, int columns, int *outSequenceArray)
{
    for (int i = 0; i < rows; i++)
    {
        float temp1 = 0;
        float rowMaxElement = fabs(getMaxElement(matrix + i * columns, rows, outSequenceArray + i));
        for (int j = 0; j < rows; j++)
        {
            temp1 += fabs(matrix[i * columns + j]);
        }
        if (rowMaxElement < temp1 - rowMaxElement)
        {
            return DOES_NOT_CONVERGE;
        }
    }
    //showArrrayInt(outSequenceArray, rows);
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (outSequenceArray[i] == outSequenceArray[j])
                return DOES_NOT_CONVERGE;
        }
    }

    for (int i = 0; i < rows - 1; i++)
    {
        if (outSequenceArray[i] > outSequenceArray[i + 1])
        {
            return CONVERGES_BUT_THE_SEQUENCE_OF_ROWS_IS_NOT_CORRECT;
        }
    }

    return CONVERGES;
}

float *getDividedMatrix(float *matrix, int rows, int columns)
{
    float *dividedMatrix = (float *)malloc(sizeof(float) * rows * columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j == i)
                dividedMatrix[i * columns + j] = 0;
            else
                dividedMatrix[i * columns + j] = -matrix[i * columns + j] / matrix[i * columns + i];
        }
    }
    return dividedMatrix;
}

float *findRoots(float *dividedMatrix, float *startRoots, int rows, int columns, float measurementError)
{
    float *newRoots = (float *)malloc(sizeof(float) * rows);
    memcpy(newRoots, startRoots, sizeof(float) * rows);
    while (1)
    {
        float *tempRoots = (float *)malloc(sizeof(float) * rows);
        int counter = 0;
        nullArray(tempRoots, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns - 1; j++)
            {
                tempRoots[i] += dividedMatrix[i * columns + j] * newRoots[j];
            }
            float vector = -dividedMatrix[i * columns + columns - 1];
            tempRoots[i] += vector;
            if (fabs(tempRoots[i] - newRoots[i]) <= measurementError)
            {
                counter++;
            }
        }
        memcpy(newRoots, tempRoots, sizeof(float) * rows);
        free(tempRoots);
        if (counter == rows)
        {
            break;
        }
    }
    return newRoots;
}

void swap(void *elemi, void *elemj, int size)
{
    void *temp = malloc(size);
    memcpy(temp, elemi, size);
    memcpy(elemi, elemj, size);
    memcpy(elemj, temp, size);
    free(temp);
}

void sortMatrixRowsByGreatestDiagonalElement(float *matrix, int *sequenceArray, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        if (sequenceArray[i] == i)
            continue;
        swap(matrix + i * columns, matrix + sequenceArray[i] * columns, sizeof(float) * columns);
        swap(&sequenceArray[i], &sequenceArray[sequenceArray[i]], sizeof(int));
    }
}

int main(int argc, char **argv)
{
    int rows;
    int columns;
    float measurementError;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &columns);

    printf("Enter SLAE:\n");
    int isConverges;
    float *matrix;
    int *sequenceArray;

    matrix = getMatrix(rows, columns);
    sequenceArray = (int *)malloc(sizeof(int) * rows);
    isConverges = checkConvergence(matrix, rows, columns, sequenceArray);
    if (isConverges == DOES_NOT_CONVERGE)
    {
        printf("\nMatrix doesn't converge!!!\n");
        free(matrix);
        free(sequenceArray);
        SYSTEM_PAUSE;
        return DOES_NOT_CONVERGE;
    }
    showMatrix(matrix, rows, columns);
    if (isConverges == CONVERGES_BUT_THE_SEQUENCE_OF_ROWS_IS_NOT_CORRECT)
    {
        sortMatrixRowsByGreatestDiagonalElement(matrix, sequenceArray, rows, columns);
        free(sequenceArray);
    }
    printf("Enter measurement error: ");
    scanf("%f", &measurementError);

    float *dividedMatrix = getDividedMatrix(matrix, rows, columns);
    float *startRoots = getStartRoots(dividedMatrix, rows, columns);
    float *newRoots = findRoots(dividedMatrix, startRoots, rows, columns, measurementError);

    printf("\nEntered matrix:\n");
    showMatrix(matrix, rows, columns);
    printf("\nDivided matrix:\n");
    showMatrix(dividedMatrix, rows, columns);
    printf("\nStart roots: ");
    showMatrix(startRoots, 1, rows);
    printf("\nNew roots: ");
    showMatrix(newRoots, 1, rows);

    free(matrix);
    free(dividedMatrix);
    free(startRoots);
    free(newRoots);

    SYSTEM_PAUSE;
    return SUCCESSFUL_COMPLETION;
}

// {0.66 -1.44 -0.18 1.83 0.48 -0.24 0.37 -0.84 0.86 0.43 0.64 0.64} rows = 3, columns 4

// {10 -1 2 0 6 -1 11 -1 3 25 2 -1 10 -1 -11 0 3 -1 8 15} rows = 4, columns = 5
// {0 3 -1 8 15 10 -1 2 0 6 2 -1 10 -1 -11 -1 11 -1 3 25}
// {1.14 -0.38 3.89 3.66 -1.14 0.94}