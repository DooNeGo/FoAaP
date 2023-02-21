#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void showMessage(const char *msg, const char *color)
{
    system("cls");
    if (color == "Green")
        system("color A");
    else
        system("color 4");
    fflush(stdin);
    printf("%s\n", msg);
    system("pause");
    system("color 7");
}
int load(int *temp, int *returnedSize)
{
    int i = 0;
    int counter = 1;
    FILE *f = fopen("f.txt", "rt");
    if (!f)
    {
        showMessage("ERROR1 file", "Red");
        fclose(f);
        return 1;
    }
    for (i = 0; !feof(f); i++)
    {
        if (i % 10 == 0)
        {
            counter++;
            do
            {
                temp = (int *)realloc(temp, sizeof(int) * counter * 10);
            } while (!temp);
            fscanf(f, "%d", &temp[i]);
            if (temp[i] < 10 && temp[i] > -10 || temp[i] > 99 || temp[i] < -99)
            {
                showMessage("ERROR2 file", "Red");
                fclose(f);
                return 1;
            }
        }
    }
    *returnedSize = i;
    fclose(f);
    return 0;
}
void createNewSpecificFile(int *temp, int size)
{
    int K;
    printf("Enter K: ");
    scanf("%d", &K);
    FILE *g = fopen("g.txt", "wt");
    for (int i = 0; i < size; i++)
    {
        if (temp[i] > K)
        {
            fprintf(g, "%d\n", temp[i]);
        }
    }
    showMessage("The new file was created successfully", "Green");
}
int main()
{
    int *temp;
    do
    {
        temp = (int *)malloc(sizeof(int) * 10);
    } while (!temp);
    int sizeArray;
    if (!load(temp, &sizeArray))
    {
        createNewSpecificFile(temp, sizeArray);
    }
    free(temp);
    return 0;
}