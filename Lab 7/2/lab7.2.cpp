#include <stdio.h>
#include <stdlib.h>

void counttheNumberofSpaces(char *array)
{
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
        if (array[i] == '\000')
        {
            break;
        }
        else
        {
            if (array[i] == ' ')
            {
                counter++;
            }
        }
    }
    printf("Number of spaces: %d\n", counter);
}
char *writeString(int size)
{
    char ch;
    char *array=(char *)malloc(sizeof(char)*size);
    int counter = 0;
    fflush(stdin);
    for (int i = 0; i < size - 1; i++)
    {
        scanf("%c", &ch);
        if (ch != '\n')
        {
            array[i] = ch;
            counter++;
        }
        else
        {
            break;
        }
    }
    array[counter] = '\000';
    fflush(stdin);
    return array;
}
int main()
{
    printf("Enter the string: ");
    char *array = writeString(100);
    counttheNumberofSpaces(array);
    free(array);
    system("pause");
    return 0;
}