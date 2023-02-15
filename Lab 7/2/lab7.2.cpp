#include <stdio.h>
#include <stdlib.h>

void counttheNumberofSpaces(char *string)
{
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
        if (string[i] == '\000')
        {
            break;
        }
        else
        {
            if (string[i] == ' ')
            {
                counter++;
            }
        }
    }
    printf("Number of spaces: %d\n", counter);
}
char *writeString(int sizeString)
{
    char ch;
    char *string = (char *)malloc(sizeof(char) * sizeString);
    fflush(stdin);
    for (int i = 0; i < sizeString - 1; i++)
    {
        scanf("%c", &ch);
        if (ch != '\n')
        {
            string[i] = ch;
        }
        else
        {
            break;
        }
    }
    string[sizeString - 1] = '\000';
    fflush(stdin);
    return string;
}
int main()
{
    printf("Enter the string: ");
    char *string = writeString(100);
    counttheNumberofSpaces(string);
    free(string);
    system("pause");
    return 0;
}