#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int sizePeople = 0;
const char nameofStructureFields[] = {"surname\nname\npatronymic\nhome address\nphone number\nage\n"};
int numberofFields;
int sizeNameofStructureFields;

struct Human
{
    char Surname[30];
    char Name[30];
    char Patronymic[30];
    char HomeAddress[30];
    char PhoneNumber[30];
    char Age[30];
} *people = (struct Human *)malloc(sizeof(struct Human) * (sizePeople + 1));

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
int doCheckNumberofFields(const char *packedArray, int sizeArray)
{
    int counter = 0;
    for (int i = 0; i < sizeArray; i++)
    {
        if (packedArray[i] == '\n')
            counter++;
    }
    return counter;
}
char *readPackedArray(const char *packedArray, int sizePackedArray, int *counter)
{
    char *unPackedArray = (char *)malloc(sizeof(char) * sizePackedArray);
    int counter1 = 0;
    for (; *counter < sizePackedArray; (*counter)++)
    {
        unPackedArray[counter1] = packedArray[*counter];
        counter1++;
        if (packedArray[*counter] == '\n')
        {
            (*counter)++;
            unPackedArray[counter1 - 1] = '\000';
            return unPackedArray;
        }
    }
    return unPackedArray;
}
void showFieldDependentMenu(const char *string)
{
    int counter = 0;
    for (int counter1 = 0; counter1 < numberofFields; counter1++)
    {
        char *unPackedArray = readPackedArray(nameofStructureFields, sizeNameofStructureFields, &counter);
        printf("%d - %s %s\n", counter1 + 1, string, unPackedArray);
        free(unPackedArray);
    }
    printf("0 - Return\n");
}
void showArray(struct Human *array, int sizeArray)
{
    system("cls");
    int counter = 0;
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
        printf("There are no people\n");
}
int doRepetitionCheck(char *startofArray, char *startofArray1, int arraySize, int structureSize, int numberofElementstoCompare, int singleElementSize)
{
    int counter = 0;
    for (int j = 0; j < numberofElementstoCompare * singleElementSize; j += singleElementSize)
    {
        for (int i = 0; i < arraySize * structureSize; i += structureSize)
        {
            if (strcmp(startofArray1 + j, startofArray + i + j) == 0)
                counter++;
        }
    }
    if (counter == numberofElementstoCompare)
    {
        showMessage("This human already exists", "Red");
        return true;
    }
    else
        return false;
}
int writeString(char *array, int size)
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
                flag = 1;
            else
            {
                showMessage("ERROR, please enter characters", "Red");
                system("cls");
                return 1;
            }
        } while (!flag);
    }
    array[i - 1] = '\000';
    return 0;
}
void copyArray(struct Human *dest, struct Human *source, int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = source[i];
}
void swap(struct Human *elemi, struct Human *elemj)
{
    struct Human temp;
    temp = *elemi;
    *elemi = *elemj;
    *elemj = temp;
}
int sortAscendingDescending()
{
    int parameter;
    while (1)
    {
        fflush(stdin);
        system("cls");
        printf("1 - Ascending\n2 - Descending\n0 - Return\n");
        scanf("%d", &parameter);
        if (parameter == 1 || parameter == 2 || parameter == 0)
            return parameter;
        else
            showMessage("Wrong number, please try again", "Red");
    }
}
struct Human *sortEngine(int parameter, int parameter1, struct Human *unSortedArray, int sizeUnSortedArray, int singleElementSize)
{
    int num;
    struct Human *array = (struct Human *)malloc(sizeof(struct Human) * sizeUnSortedArray);
    copyArray(array, unSortedArray, sizeUnSortedArray);
    for (int i = 0; i < sizeUnSortedArray - 1; i++)
    {
        num = i;
        for (int k = i + 1; k < sizeUnSortedArray; k++)
        {
            if (parameter1 == 1)
            {
                if (memcmp(array[num].Surname + singleElementSize * (parameter - 1), array[k].Surname + singleElementSize * (parameter - 1), 1) < 0)
                    num = k;
            }
            else if (parameter1 == 2)
            {
                if (memcmp(array[num].Surname + singleElementSize * (parameter - 1), array[k].Surname + singleElementSize * (parameter - 1), 1) > 0)
                    num = k;
            }
        }
        if (num != i)
            swap(&array[i], &array[num]);
    }
    return array;
}
void sortByMenu()
{
    int parameter, parameter1;
    while (1)
    {
        system("cls");
        fflush(stdin);
        showFieldDependentMenu("Sort by");
        scanf("%d", &parameter);
        if (parameter > 0 && parameter < numberofFields + 1)
        {
            parameter1 = sortAscendingDescending();
            if (parameter1 != 0)
            {
                struct Human *sortedArray = sortEngine(parameter, parameter1, people, sizePeople, sizeof(struct Human) / numberofFields);
                showArray(sortedArray, sizePeople);
                system("pause");
                free(sortedArray);
            }
        }
        else if (parameter == 0)
            return;
        else
            showMessage("Wrong number, please try again", "Red");
    }
}
void searchEngine(struct Human *source, int sizeSource, char *string, int singleElementSize, int structureSize)
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
    if (counter > 0)
        showArray(array, counter);
    printf("Number of matches: %d\n", counter);
    free(array);
    system("pause");
}
void searchMenu()
{
    int counter = 0;
    char *string = (char *)malloc(sizeof(char) * 30);
    while (1)
    {
        system("cls");
        printf("Search(0 - Return): ");
        writeString(string, 30);
        if (string[0] == '0')
            return;
        searchEngine(people, sizePeople, string, sizeof(struct Human) / 6, sizeof(struct Human));
    }
}
const char *showSpecificField(const char *unPackedArray, int sizeUnPackedArray, int fieldNumber)
{
    int i;
    int counter = 0;
    char *temp = (char *)malloc(sizeof(char) * sizeUnPackedArray);
    for (int counter1 = 0; counter1 < sizeUnPackedArray; counter1++)
    {
        if (counter == fieldNumber - 1)
        {
            for (i = 0; i < sizeUnPackedArray && unPackedArray[counter1] != '\n'; i++)
            {
                temp[i] = unPackedArray[counter1];
                counter1++;
            }
            temp[i] = '\000';
            return temp;
        }
        else if (unPackedArray[counter1] == '\n')
            counter++;
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
    } while (writeString(tempStr, 30));
    if (tempStr[0] == '0')
        return;
    strcpy(people[humanNumber - 1].Surname + singleElementSize * (parameter - 1), tempStr);
    showMessage("The change was successful", "Green");
}
int doChoice(struct Human *array, int size)
{
    int num;
    do
    {
        showArray(array, size);
        printf("Enter the number(0 - Return): ");
        scanf("%d", &num);
        if (num < 0 || num > size)
            showMessage("Wrong number, please try again", "Red");
    } while (num < 0 || num > size);
    return num;
}
void editHumanMenu()
{
    int parameter;
    while (1)
    {
        int humanNumber = doChoice(people, sizePeople);
        if (humanNumber == 0)
            return;
        bool stop = false;
        while (!stop)
        {
            system("cls");
            printf("FIO: %-s %-s %-s  Home address: %-s  Phone number: %-s  Age: %-2s\n", people[humanNumber - 1].Surname, people[humanNumber - 1].Name, people[humanNumber - 1].Patronymic, people[humanNumber - 1].HomeAddress, people[humanNumber - 1].PhoneNumber, people[humanNumber - 1].Age);
            showFieldDependentMenu("Edit");
            scanf("%d", &parameter);
            if (parameter > 0 && parameter < numberofFields + 1)
                editHuman(humanNumber, parameter, sizeof(struct Human) / numberofFields, showSpecificField(nameofStructureFields, sizeNameofStructureFields, parameter));
            else if (parameter == 0)
                stop = true;
            else
                showMessage("Wrong number, please try again", "Red");
        }
    }
}
int removeArrayElement(struct Human *array, int sizeArray)
{
    while (1)
    {
        int num = doChoice(array, sizeArray);
        if (num == 0)
            return sizeArray;
        for (int i = num - 1; i < sizeArray; i++)
            array[i] = array[i + 1];
        sizeArray--;
        array = (struct Human *)realloc(array, sizeof(struct Human) * (sizeArray + 1));
        showMessage("Delete was successful", "Green");
    }
}
int addArrayElement(struct Human *array, int sizeArray)
{
    struct Human temp;
    int counter = 0;
    system("cls");
    for (int counter1 = 0; counter1 < numberofFields; counter1++)
    {
        if (doRepetitionCheck(array[0].Surname, temp.Surname, sizeArray, sizeof(struct Human), 3, sizeof(struct Human) / 6))
        {
            counter = 0;
            counter1 = 0;
            system("cls");
        }
        char *unPackedArray = readPackedArray(nameofStructureFields, sizeNameofStructureFields, &counter);
        do
        {
            printf("Enter %s (0 - Return): ", unPackedArray);
        } while (writeString(temp.Surname + counter1 * sizeof(struct Human) / numberofFields, 30));
        if (*(temp.Surname + counter1 * sizeof(struct Human) / 6) == '0')
            return sizeArray;
        free(unPackedArray);
    }
    array[sizeArray] = temp;
    sizeArray++;
    array = (struct Human *)realloc(array, sizeof(struct Human) * (sizeArray + 1));
    showMessage("Adding was successful", "Green");
    return sizeArray;
}
void menu()
{
    int parameter;
    while (1)
    {
        system("cls");
        fflush(stdin);
        printf("1 - Add human\n2 - Sort by\n3 - Search\n4 - Edit human\n5 - Delete human\n6 - Show people\n0 - Exit\n");
        scanf("%d", &parameter);
        if (parameter == 0)
            return;
        else if (parameter == 1)
            sizePeople = addArrayElement(people, sizePeople);
        else if (parameter == 2)
            sortByMenu();
        else if (parameter == 3)
            searchMenu();
        else if (parameter == 4)
            editHumanMenu();
        else if (parameter == 5)
            sizePeople = removeArrayElement(people, sizePeople);
        else if (parameter == 6)
        {
            showArray(people, sizePeople);
            system("pause");
        }
        else if (parameter < 0 || parameter > 6)
            showMessage("Wrong number, please try again", "Red");
    }
}
int main()
{
    sizeNameofStructureFields = strlen(nameofStructureFields);
    numberofFields = doCheckNumberofFields(nameofStructureFields, sizeNameofStructureFields);
    menu();
    free(people);
    return 0;
}