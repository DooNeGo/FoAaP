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
char *writeString()
{
    char ch;
    char *string = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++)
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
    return string;
}
int main()
{
    printf("Enter the string: ");
    char *string = writeString();
    counttheNumberofSpaces(string);
    free(string);
    system("pause");
    return 0;
}