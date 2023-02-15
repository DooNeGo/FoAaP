#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findFirstRowSortedDescending(int *matrix, int rows, int columns)
{
    int counter = 0;
    int i;
    bool flag = false;
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            if (*(matrix + i * columns + j) >= *(matrix + i * columns + j + 1))
            {
                counter = 0;
                break;
            }
            else
            {
                counter++;
            }
        }
        if (counter == columns - 1)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        return i;
    }
    else
    {
        return flag;
    }
}
int *generateMatrix(int rows, int columns)
{
    srand(time(0));
    int *matrix = (int *)malloc(sizeof(int) * rows * columns);
    while (!findFirstRowSortedDescending(matrix, rows, columns))
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                *(matrix + i * columns + j) = rand() % 12 + (-2);
            }
        }
    }
    return matrix;
}
void showMatrix(int *matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%3d", *(matrix + i * columns + j));
        }
        printf("\n");
    }
}
void changetheOrderofElements(int *matrix, int rowSortedDescending, int columns)
{
    int temp;
    for (int i = 0; i < columns / 2; i++)
    {
        temp = *(matrix + rowSortedDescending * columns + i);
        *(matrix + rowSortedDescending * columns + i) = *(matrix + rowSortedDescending * columns + columns - i - 1);
        *(matrix + rowSortedDescending * columns + columns - i - 1) = temp;
    }
}
int main()
{
    int rows;
    int columns;
    int rowSortedDescending;
    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &columns);
    int *matrix = generateMatrix(rows, columns);
    printf("Generated Matrix:\n");
    showMatrix(matrix, rows, columns);
    rowSortedDescending = findFirstRowSortedDescending(matrix, rows, columns);
    printf("Row sorted descending: %d\n", rowSortedDescending + 1);
    changetheOrderofElements(matrix, rowSortedDescending, columns);
    printf("Changed matrix:\n");
    showMatrix(matrix, rows, columns);
    free(matrix);
    system("pause");
    return 0;
}