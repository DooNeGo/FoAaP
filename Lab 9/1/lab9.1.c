#include <stdio.h>
#include <stdlib.h>

void showMessage(const char *msg, const char *color)
{
    system("cls");

    if (color == "Green")
        system("color A");
    else if (color == "Red")
        system("color 4");

    printf("%s\n", msg);

    system("pause");
    system("color 7");
}

int *load(int *returnedSize)
{
    int i = 0;
    int counter = 1;
    int *temp = (int *)malloc(sizeof(int) * 10);
    FILE *f = fopen("f.txt", "rt");

    if (!f)
    {
        showMessage("ERROR1 file", "Red");
        fclose(f);
        temp[0] = 1;
        return temp;
    }
    for (i = 0; !feof(f); i++)
    {
        if (i % 10 == 0 && i > 0)
        {
            counter++;
            temp = (int *)realloc(temp, sizeof(int) * counter * 10);
        }

        fscanf(f, "%d", &temp[i]);

        if (temp[i] < 10 && temp[i] > -10 || temp[i] > 99 || temp[i] < -99)
        {
            showMessage("ERROR2 file", "Red");
            fclose(f);
            temp[0] = 1;
            return temp;
        }
    }
    *returnedSize = i;
    fclose(f);
    return temp;
}

void createNewSpecificFile(int *temp, int size)
{
    int K;
    FILE *g = fopen("g.txt", "wt");

    printf("Enter K: ");
    scanf("%d", &K);

    for (int i = 0; i < size; i++)
    {
        if (temp[i] > K)
        {
            fprintf(g, "%d\n", temp[i]);
        }
    }
    fflush(g);
    fclose(g);
    showMessage("The new file was created successfully", "Green");
}

int main()
{
    int sizeArray;
    int *temp = load(&sizeArray);

    if (temp[0] != 1)
    {
        createNewSpecificFile(temp, sizeArray);
    }

    free(temp);
    return 0;
}
