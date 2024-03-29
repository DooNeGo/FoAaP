#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int sizePeople = 0;
int sizeNameofStructureFields;
char *nameofStructureFields;
int numberofFields;

struct Human
{
    char Surname[30];
    char Name[30];
    char Patronymic[30];
    char HomeAddress[30];
    char PhoneNumber[30];
    char Age[30];
} *people = (struct Human *)malloc(sizeof(struct Human) * 10);

void showMessage(const char *msg, const char *color)
{
    system("cls");
    if (color == "Green")
    {
        system("color A");
    }
    else if (color == "Red")
    {
        system("color 4");
    }
    fflush(stdin);
    printf("%s\n", msg);
    system("pause");
    system("color 7");
}

int getNumberOfFields(char *packedArray, int sizeArray)
{
    int counter = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        if (packedArray[i] == '$')
        {
            counter++;
        }
    }
    return counter;
}

char *getStructureFields(const char *packedArray, int sizePackedArray, int *counter)
{
    char *unPackedArray = (char *)malloc(sizeof(char) * sizePackedArray);
    int counter1 = 0;
    for (; *counter < sizePackedArray; (*counter)++)
    {
        unPackedArray[counter1] = packedArray[*counter];
        counter1++;
        if (packedArray[*counter] == '$')
        {
            (*counter)++;
            unPackedArray[counter1 - 1] = 0;
            return unPackedArray;
        }
    }
    return unPackedArray;
}

void showMenuItemsWithPrefix(const char *menuItemName)
{
    int counter = 0;
    for (int counter1 = 0; counter1 < numberofFields; counter1++)
    {
        char *unPackedArray = getStructureFields(nameofStructureFields, sizeNameofStructureFields, &counter);
        printf("%d - %s %s\n", counter1 + 1, menuItemName, unPackedArray);
        free(unPackedArray);
    }
    printf("0 - Return\n");
}

void showArray(struct Human *array, int sizeArray)
{
    int counter = 0;
    system("cls");
    if (sizeArray > 0)
    {
        printf("A list of people:\n");
        printf("\xC9\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA # \xBA              FIO               \xBa    Home address   \xBA  Phone number  \xBA Age \xBA\n");
        for (int i = 0; i < sizeArray; i++)
        {
            printf("\xCC\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xB9\n");
            printf("\xBA%-3d\xBA%-10s %-10s %-10s\xBA%-19s\xBA%-16s\xBA%-5s\xBA\n", i + 1, array[i].Surname, array[i].Name, array[i].Patronymic, array[i].HomeAddress, array[i].PhoneNumber, array[i].Age);
        }
        printf("\xC8\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xBC\n");
    }
    else
    {
        printf("There are no people\n");
    }
}

int load()
{
    FILE *file = fopen("data.dat", "rb");
    FILE *file1 = fopen("nameFields.txt", "r");

    if (file)
    {
        fread(&sizePeople, sizeof(int), 1, file);
        if (sizePeople < 0)
        {
            showMessage("ERROR 2", "Red");
            return 2;
        }
        else if (sizePeople > 0)
        {
            fread(people, sizeof(struct Human), sizePeople, file);
        }
        fclose(file);
    }

    if (file1)
    {
        int counter = 1;
        int i;
        nameofStructureFields = (char *)malloc(sizeof(char) * 10);
        for (i = 0; !feof(file1); i++)
        {
            if (i != 0 && i % 10 == 0)
            {
                counter++;
                nameofStructureFields = (char *)realloc(nameofStructureFields, sizeof(char) * 10 * counter + 1);
            }
            fscanf(file1, "%c", &nameofStructureFields[i]);
        }
        sizeNameofStructureFields = i++;
        fclose(file1);
    }
    else
    {
        return 3;
    }

    return 0;
}

void save()
{
    FILE *file = fopen("data.dat", "wb");
    FILE *file1 = fopen("nameFields.txt", "w");
    fwrite(&sizePeople, sizeof(int), 1, file);
    if (sizePeople > 0)
    {
        fwrite(people, sizeof(struct Human), sizePeople, file);
    }
    for (int i = 0; i < sizeNameofStructureFields - 1; i++)
    {
        fprintf(file1, "%c", nameofStructureFields[i]);
    }

    fflush(file);
    fflush(file1);
    fclose(file1);
    fclose(file);
}

int checkForDuplicates(char *startofArray, char *startofArray1, int arraySize, int structureSize, int numberofElementstoCompare, int singleElementSize)
{
    int counter = 0;
    for (int i = 0; i < arraySize * structureSize; i += structureSize)
    {
        counter = 0;
        for (int j = 0; j < numberofElementstoCompare * singleElementSize; j += singleElementSize)
        {
            if (strcmp(startofArray1 + j, startofArray + i + j) == 0)
            {
                counter++;
                if (counter == numberofElementstoCompare)
                {
                    showMessage("This human already exists", "Red");
                    return true;
                }
            }
        }
    }
    return false;
}

int read(char *array, int size)
{
    char ch;
    int i;
    int flag = 0;
    fflush(stdin);
    for (i = 0; i < size - 1 && !flag; i++)
    {
        do
        {
            scanf("%c", &ch);

            if (ch != '\n')
            {
                array[i] = ch;
                break;
            }
            else if (i != 0)
            {
                flag = 1;
            }
            else
            {
                showMessage("ERROR, please enter characters", "Red");
                system("cls");
                return 1;
            }
        } while (!flag);
    }
    array[i - 1] = 0;
    return 0;
}

void swap(void *elemi, void *elemj, int size)
{
    void *temp = malloc(size);
    memcpy(temp, elemi, size);
    memcpy(elemi, elemj, size);
    memcpy(elemj, temp, size);
    free(temp);
}

int showSortMenuByOrder()
{
    int parameter = -1;
    while (1)
    {
        fflush(stdin);
        system("cls");
        printf("1 - Ascending\n2 - Descending\n0 - Return\n");
        scanf("%d", &parameter);
        if (parameter >= 0 && parameter <= 2)
            return parameter;
        else
            showMessage("Wrong number, please try again", "Red");
    }
}

void sort(int parameter, int parameter1, struct Human *unSortedArray, int sizeUnSortedArray, int singleElemSize)
{
    int num;
    struct Human *array = (struct Human *)malloc(sizeof(struct Human) * sizeUnSortedArray);
    memcpy(array, unSortedArray, sizeUnSortedArray * sizeof(struct Human));
    for (int i = 0; i < sizeUnSortedArray - 1; i++)
    {
        num = i;
        for (int k = i + 1; k < sizeUnSortedArray; k++)
        {
            if (parameter1 == 1)
            {
                if (memcmp(array[num].Surname + singleElemSize * (parameter - 1), array[k].Surname + singleElemSize * (parameter - 1), 1) < 0)
                    num = k;
            }
            else if (parameter1 == 2)
            {
                if (memcmp(array[num].Surname + singleElemSize * (parameter - 1), array[k].Surname + singleElemSize * (parameter - 1), 1) > 0)
                    num = k;
            }
        }
        if (num != i)
        {
            swap(&array[i], &array[num], sizeof(struct Human));
        }
    }
    showArray(array, sizeUnSortedArray);
    free(array);
    system("pause");
}

void showSortMenuByField()
{
    int parameter = -1;
    while (1)
    {
        system("cls");
        fflush(stdin);
        showMenuItemsWithPrefix("Sort by");
        scanf("%d", &parameter);
        if (parameter > 0 && parameter <= numberofFields)
        {
            int parameter1 = showSortMenuByOrder();
            if (parameter1 != 0)
            {
                sort(parameter, parameter1, people, sizePeople, sizeof(struct Human) / numberofFields);
            }
        }
        else if (parameter == 0)
        {
            return;
        }
        else
        {
            showMessage("Wrong number, please try again", "Red");
        }
    }
}

void filter(struct Human *source, int sizeSource, char *string, int singleElementSize, int structureSize)
{
    int counter = 0;
    int numLetters = strlen(string);
    struct Human *array = (struct Human *)malloc(sizeof(struct Human) * sizeSource);
    for (int i = 0; i < sizeSource; i++)
    {
        for (int j = 0; j < structureSize; j += singleElementSize)
        {
            if (memcmp(source[i].Surname + j, string, numLetters) == 0)
            {
                array[counter] = source[i];
                counter++;
                break;
            }
        }
    }
    printf("Number of matches: %d\n", counter);
    if (counter > 0)
    {
        showArray(array, counter);
    }
    free(array);
    system("pause");
}

void showFilterMenu()
{
    char *string = (char *)malloc(sizeof(char) * 30);
    while (1)
    {
        system("cls");
        do
        {
            printf("Search(0 - Return): ");
        } while (read(string, 30));
        if (string[0] == '0')
        {
            return;
        }
        else
        {
            filter(people, sizePeople, string, sizeof(struct Human) / numberofFields, sizeof(struct Human));
        }
    }
}

const char *getFieldValue(const char *packedArray, int sizePackedArray, int fieldNumber)
{
    int i;
    int counter = 0;
    char *temp = (char *)malloc(sizeof(char) * sizePackedArray);
    for (int counter1 = 0; counter1 < sizePackedArray; counter1++)
    {
        if (counter == fieldNumber - 1)
        {
            for (i = 0; i < sizePackedArray && packedArray[counter1] != '$'; i++)
            {
                temp[i] = packedArray[counter1];
                counter1++;
            }
            temp[i] = 0;
            return temp;
        }
        else if (packedArray[counter1] == '$')
        {
            counter++;
        }
    }
    return temp;
}

void editHuman(int humanNumber, int parameter, int singleElementSize, const char *string)
{
    char *tempStr = (char *)malloc(sizeof(char) * 30);
    system("cls");
    fflush(stdin);
    do
    {
        printf("Enter new %s (0 - Return): ", string);
    } while (read(tempStr, 30));
    if (tempStr[0] == '0')
    {
        return;
    }
    else
    {
        strcpy(people[humanNumber - 1].Surname + singleElementSize * (parameter - 1), tempStr);
        showMessage("The change was successful", "Green");
    }
}

int getElementNumber(struct Human *array, int size)
{
    int num;
    do
    {
        showArray(array, size);
        printf("Enter the number(0 - Return): ");
        scanf("%d", &num);
        if (num < 0 || num > size)
        {
            showMessage("Wrong number, please try again", "Red");
        }
    } while (num < 0 || num > size);
    return num;
}

void showEditMenu()
{
    while (1)
    {
        int humanNumber = getElementNumber(people, sizePeople);
        bool stop = false;
        if (humanNumber == 0)
        {
            return;
        }
        int parameter = -1;
        while (!stop)
        {
            system("cls");
            printf("FIO: %-s %-s %-s  Home address: %-s  Phone number: %-s  Age: %-2s\n", people[humanNumber - 1].Surname, people[humanNumber - 1].Name, people[humanNumber - 1].Patronymic, people[humanNumber - 1].HomeAddress, people[humanNumber - 1].PhoneNumber, people[humanNumber - 1].Age);
            showMenuItemsWithPrefix("Edit");
            scanf("%d", &parameter);
            if (parameter > 0 && parameter <= numberofFields)
            {
                editHuman(humanNumber, parameter, sizeof(struct Human) / numberofFields, getFieldValue(nameofStructureFields, sizeNameofStructureFields, parameter));
            }
            else if (parameter == 0)
            {
                stop = true;
            }
            else
            {
                showMessage("Wrong number, please try again", "Red");
            }
        }
    }
}

int deleteArrayElement(struct Human *array, int sizeArray)
{
    while (1)
    {
        int num = getElementNumber(array, sizeArray);
        if (num == 0)
        {
            return sizeArray;
        }
        for (int i = num - 1; i < sizeArray; i++)
        {
            array[i] = array[i + 1];
        }
        sizeArray--;
        if ((sizeArray + 1) % 10 == 0)
        {
            people = (struct Human *)realloc(people, sizeof(struct Human) * (sizeArray + 1));
        }
        showMessage("Delete was successful", "Green");
    }
}

int insertElementToArray(struct Human *array, int sizeArray)
{
    struct Human temp;
    int counter = 0;
    system("cls");
    for (int counter1 = 0; counter1 < numberofFields; counter1++)
    {
        if (counter1 == 4 && checkForDuplicates(array[0].Surname, temp.Surname, sizeArray, sizeof(struct Human), 4, sizeof(struct Human) / numberofFields))
        {
            counter = 0;
            counter1 = 0;
            system("cls");
        }
        char *unPackedArray = getStructureFields(nameofStructureFields, sizeNameofStructureFields, &counter);

        do
        {
            printf("Enter %s (0 - Return): ", unPackedArray);
        } while (read(temp.Surname + counter1 * sizeof(struct Human) / numberofFields, 30));

        if (*(temp.Surname + counter1 * sizeof(struct Human) / 6) == '0')
        {
            return sizeArray;
        }
        free(unPackedArray);
    }

    array[sizeArray] = temp;
    sizeArray++;

    if (sizeArray % 10 == 0)
    {
        people = (struct Human *)realloc(people, sizeof(struct Human) * (sizeArray + 10));
    }

    showMessage("Adding was successful", "Green");
    return sizeArray;
}

void showMainMenu()
{
    while (1)
    {
        int parameter = -1;
        system("cls");
        fflush(stdin);
        printf("1 - Add human\n2 - Sort by\n3 - Search\n4 - Edit human\n5 - Delete human\n6 - Show people\n0 - Exit\n");
        scanf("%d", &parameter);
        if (parameter == 0)
        {
            return;
        }
        else if (parameter == 1)
        {
            sizePeople = insertElementToArray(people, sizePeople);
        }
        else if (parameter == 2)
        {
            showSortMenuByField();
        }
        else if (parameter == 3)
        {
            showFilterMenu();
        }
        else if (parameter == 4)
        {
            showEditMenu();
        }
        else if (parameter == 5)
        {
            sizePeople = deleteArrayElement(people, sizePeople);
        }
        else if (parameter == 6)
        {
            showArray(people, sizePeople);
            system("pause");
        }
        else
        {
            showMessage("Wrong number, please try again", "Red");
        }
    }
}

int main()
{
    int status = load();

    if (status == 3)
    {
        char temp[] = "surname$name$patronymic$home address$phone number$age$";
        nameofStructureFields = (char *)malloc(sizeof(char) * 55);
        memcpy(nameofStructureFields, temp, 55);
        sizeNameofStructureFields = 55;
    }

    if (status == 0 || status == 3)
    {
        numberofFields = getNumberOfFields(nameofStructureFields, sizeNameofStructureFields);
        showMainMenu();
        save();
    }

    free(people);
    free(nameofStructureFields);
    return 0;
}