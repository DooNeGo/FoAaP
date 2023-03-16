#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SYSTEM_PAUSE system("pause")
#define GO_TO_NEXT_LINE printf("\n")

enum
{
    SUCCESSFUL_COMPLETION = 0,
};

float *getArray(int size)
{
    float *newArray = (float *)malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++)
    {
        newArray[i] = -3.0 + 8.0 * rand() / (float)RAND_MAX;
        // scanf("%f", matrix + i * columns + j);
    }
    return newArray;
}

void showArray(float *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%7.2f", array[i]);
    }
}

void swap(void *elemi, void *elemj, int size)
{
    void *temp = malloc(size);
    memcpy(temp, elemi, size);
    memcpy(elemi, elemj, size);
    memcpy(elemj, temp, size);
    free(temp);
}

void *merge(void *Source, void *Source1, int countSource, int countSource1, int singleElementSize, int *outNewCount)
{
    void *newArray = malloc((countSource + countSource1) * singleElementSize);
    memcpy(newArray, Source, singleElementSize * countSource);
    memcpy(newArray + singleElementSize * countSource, Source1, singleElementSize * countSource1);
    *outNewCount = countSource + countSource1;
    return newArray;
}

void sortInDescendingOrder(float *Array, int sizeArray)
{
    for (int i = 0; i < sizeArray - 1; i++)
    {
        int arrayNumber = i;
        for (int j = i + 1; j < sizeArray; j++)
        {
            if (Array[arrayNumber] < Array[j])
            {
                arrayNumber = j;
            }
        }
        if (arrayNumber != i)
        {
            swap(&Array[i], &Array[arrayNumber], sizeof(float));
        }
    }
}

float *sortInAscendingOrder(float *Array, int sizeArray)
{
    float *newArray = (float *)malloc(sizeof(float) * sizeArray);
    memcpy(newArray, Array, sizeof(float) * sizeArray);
    for (int i = 0; i < sizeArray - 1; i++)
    {
        int arrayNumber = i;
        for (int j = i + 1; j < sizeArray; j++)
        {
            if (newArray[arrayNumber] > newArray[j])
            {
                arrayNumber = j;
            }
        }
        if (arrayNumber != i)
        {
            swap(&newArray[i], &newArray[arrayNumber], sizeof(float));
        }
    }
    return newArray;
}

int main(int argc, char **argv)
{
    srand(clock());

    int sizeArray;
    int sizeArray1;
    int newSizeArray;

    printf("Enter first array size: ");
    scanf("%d", &sizeArray);
    printf("Enter second array size: ");
    scanf("%d", &sizeArray1);

    float *Array = getArray(sizeArray);
    float *Array1 = getArray(sizeArray1);
    sortInDescendingOrder(Array, sizeArray);
    sortInDescendingOrder(Array1, sizeArray1);
    float *mergedArray = (float *)merge(Array, Array1, sizeArray, sizeArray1, sizeof(float), &newSizeArray);
    float *sortedMergedArray = sortInAscendingOrder(mergedArray, newSizeArray);

    printf("\nFirst array:\n");
    showArray(Array, sizeArray);
    printf("\nSecond array:\n");
    showArray(Array1, sizeArray1);
    printf("\nMerged array:\n");
    showArray(mergedArray, newSizeArray);
    printf("\nSorted merged array:\n");
    showArray(sortedMergedArray, newSizeArray);

    free(Array);
    free(Array1);
    free(mergedArray);
    free(sortedMergedArray);

    GO_TO_NEXT_LINE;
    SYSTEM_PAUSE;
    return SUCCESSFUL_COMPLETION;
}