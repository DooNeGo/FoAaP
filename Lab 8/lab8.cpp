#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Human
{
    char Surname[30];
    char Name[30];
    char Patronymic[30];
    char HomeAddress[30];
    char PhoneNumber[30];
    int Age;
} people[20];

int sizePeople = 0;

void showMessage(const char *msg)
{
    system("cls");
    fflush(stdin);
    printf("%s\n", msg);
    system("pause");
}
void showPeople(struct Human *array, int sizeArray)
{
    system("cls");
    fflush(stdin);
    if (sizeArray > 0)
    {
        printf("A list of people:\n");
        for (int i = 0; i < sizeArray; i++)
        {
            printf("%2d. FIO: %-s %-s %-s  Home address: %-s  Phone number: %-s  Age: %-2d\n", i + 1, array[i].Surname, array[i].Name, array[i].Patronymic, array[i].HomeAddress, array[i].PhoneNumber, array[i].Age);
        }
    }
    else
    {
        printf("There are no people\n");
    }
}
int doRepetitionCheck(char *startofArray, int arrayElementNumbertoCompare, int arraySize, int structureSize, int numberofElementstoCompare, int singleElementSize)
{
    int counter = 0;
    for (int j = 0; j < numberofElementstoCompare * singleElementSize; j += singleElementSize)
    {
        for (int i = 0; i < arraySize * structureSize; i += structureSize)
        {
            if (strcmp(startofArray + (arrayElementNumbertoCompare) * structureSize + j, startofArray + i + j) == 0)
            {
                counter++;
            }
        }
    }
    if (counter == numberofElementstoCompare)
    {
        showMessage("This human already exists");
        return true;
    }
    else
    {
        return false;
    }
}
void writeString(char *array, int size)
{
    char ch;
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
}
void addHuman()
{
    do
    {
        system("cls");
        fflush(stdin);
        printf("Enter FIO (0 - Return): ");
        scanf("%s", &people[sizePeople].Surname);
        if (people[sizePeople].Surname[0] == '0')
        {
            return;
        }
        else
        {
            scanf("%s%s", &people[sizePeople].Name, &people[sizePeople].Patronymic);
        }
    } while (doRepetitionCheck(people[0].Surname, sizePeople, sizePeople, sizeof(struct Human), 3, 30));
    printf("Enter home address(0 - Return): ");
    fflush(stdin);
    writeString(people[sizePeople].HomeAddress, 30);
    if (people[sizePeople].HomeAddress[0] == '0')
    {
        return;
    }
    printf("Enter phone number (0 - Return): ");
    scanf("%s", &people[sizePeople].PhoneNumber);
    if (people[sizePeople].PhoneNumber[0] == '0')
    {
        return;
    }
    printf("Enter age (0 - Return): ");
    scanf("%d", &people[sizePeople].Age);
    if (people[sizePeople].Age == 0)
    {
        return;
    }
    showMessage("New human was added");
    sizePeople++;
}
void copyArray(struct Human *dest, struct Human *source, int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
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
        {
            return parameter;
        }
        else
        {
            showMessage("Wrong number, please try again");
        }
    }
}
struct Human *sortEngine(int parameter, int parameter1)
{
    int num;
    struct Human *array = (struct Human *)malloc(sizeof(struct Human) * sizePeople);
    copyArray(array, people, sizePeople);
    for (int i = 0; i < sizePeople - 1; i++)
    {
        num = i;
        for (int k = i + 1; k < sizePeople; k++)
        {
            if (parameter1 == 1)
            {
                if (parameter == 1 && memcmp(array[num].Surname, array[k].Surname, 1) < 0)
                    num = k;
                else if (parameter == 2 && memcmp(array[num].Name, array[k].Name, 1) < 0)
                    num = k;
                else if (parameter == 3 && memcmp(array[num].Patronymic, array[k].Patronymic, 1) < 0)
                    num = k;
                else if (parameter == 4 && memcmp(array[num].HomeAddress, array[k].HomeAddress, 1) < 0)
                    num = k;
                else if (parameter == 5 && array[num].Age > array[k].Age)
                    num = k;
            }
            else if (parameter1 == 2)
            {
                if (parameter == 1 && memcmp(array[num].Surname, array[k].Surname, 1) > 0)
                    num = k;
                else if (parameter == 2 && memcmp(array[num].Name, array[k].Name, 1) > 0)
                    num = k;
                else if (parameter == 3 && memcmp(array[num].Patronymic, array[k].Patronymic, 1) > 0)
                    num = k;
                else if (parameter == 4 && memcmp(array[num].HomeAddress, array[k].HomeAddress, 1) > 0)
                    num = k;
                else if (parameter == 5 && array[num].Age < array[k].Age)
                    num = k;
            }
        }
        if (num != i)
        {
            swap(&array[i], &array[num]);
        }
    }
    return array;
}
void sortBy()
{
    int parameter, parameter1;
    while (1)
    {
        system("cls");
        fflush(stdin);
        printf("1 - Sort by surname\n2 - Sort by name\n3 - Sort by patronymic\n4 - Sort home address\n5 - Sort by Age\n0 - Return\n");
        scanf("%d", &parameter);
        if (parameter > 0 && parameter < 8)
        {
            parameter1 = sortAscendingDescending();
            if (parameter1 == 1 || parameter1 == 2)
            {
                struct Human *sortedArray = sortEngine(parameter, parameter1);
                showPeople(sortedArray, sizePeople);
                system("pause");
                free(sortedArray);
            }
        }
        else if (parameter == 0)
        {
            return;
        }
        else
        {
            showMessage("Wrong number, please try again");
        }
    }
}
void searchMatches(char *string, int parameter, int number)
{
    int counter = 0;
    int numLetters = strlen(string);
    struct Human *array = (struct Human *)malloc(sizeof(struct Human) * sizePeople);
    for (int i = 0; i < sizePeople; i++)
    {
        if ((memcmp(people[i].Surname, string, numLetters) == 0 && parameter == 1) || (memcmp(people[i].Name, string, numLetters) == 0 && parameter == 2) || (memcmp(people[i].Patronymic, string, numLetters) == 0 && parameter == 3) || (memcmp(people[i].HomeAddress, string, numLetters) == 0 && parameter == 4) || (memcmp(people[i].PhoneNumber, string, numLetters) == 0 && parameter == 5) || (people[i].Age == number && parameter == 6))
        {
            array[counter] = people[i];
            counter++;
        }
    }
    if (counter > 0)
    {
        showPeople(array, counter);
    }
    printf("Number of matches: %d\n", counter);
    free(array);
    system("pause");
}
void search(int parameter, const char *parameter1)
{
    char *string = (char *)malloc(sizeof(char) * 30);
    int number;
    system("cls");
    fflush(stdin);
    printf("Enter %s for search(0 - Return): ", parameter1);
    if (parameter > 0 && parameter < 6)
    {
        writeString(string, 30);
    }
    else if (parameter == 6)
    {
        scanf("%d", &number);
    }
    if ((parameter > 0 && parameter < 6 && string[0] == '0') || (parameter == 6 && number == 0))
    {
        return;
    }
    searchMatches(string, parameter, number);
}
void searchMenu()
{
    int parameter;
    while (1)
    {
        system("cls");
        printf("1 - Search by surname\n2 - Search by name\n3 - Search by patronymic\n4 - Search by home address\n5 - Search by phone number\n6 - Search by age\n0 - Return\n");
        scanf("%d", &parameter);
        if (parameter == 1)
        {
            search(parameter, "surname");
        }
        else if (parameter == 2)
        {
            search(parameter, "name");
        }
        else if (parameter == 3)
        {
            search(parameter, "patronymic");
        }
        else if (parameter == 4)
        {
            search(parameter, "home address");
        }
        else if (parameter == 5)
        {
            search(parameter, "phone number");
        }
        else if (parameter == 6)
        {
            search(parameter, "age");
        }
        else if (parameter == 0)
        {
            return;
        }
        else
        {
            showMessage("Wrong number, please try again");
        }
    }
}
void editHuman(int humanNumber, const char *parameter)
{
    char *tempStr = (char *)malloc(sizeof(char) * 30);
    int tempNum = 1;
    system("cls");
    fflush(stdin);
    printf("Enter new %s(0 - Return): ", parameter);
    if (parameter != "age")
    {
        writeString(tempStr, 30);
    }
    else
    {
        scanf("%d", &tempNum);
    }
    if (tempStr[0] == '0' || tempNum == 0)
    {
        return;
    }
    if (parameter == "surname")
    {
        strcpy(people[humanNumber - 1].Surname, tempStr);
    }
    else if (parameter == "name")
    {
        strcpy(people[humanNumber - 1].Name, tempStr);
    }
    else if (parameter == "patronymic")
    {
        strcpy(people[humanNumber - 1].Patronymic, tempStr);
    }
    else if (parameter == "home address")
    {
        strcpy(people[humanNumber - 1].HomeAddress, tempStr);
    }
    else if (parameter == "phone number")
    {
        strcpy(people[humanNumber - 1].PhoneNumber, tempStr);
    }
    else if (parameter == "age")
    {
        people[humanNumber - 1].Age = tempNum;
    }
    showMessage("The change was successful");
}
int doChoice(struct Human *array, int size)
{
    int humanNumber;
    do
    {
        showPeople(array, size);
        printf("Enter the human's number(0 - Return): ");
        scanf("%d", &humanNumber);
        if (humanNumber < 0 || humanNumber > sizePeople)
        {
            showMessage("Wrong number, please try again");
        }
    } while (humanNumber < 0 || humanNumber > sizePeople);
    return humanNumber;
}
void editHumanMenu()
{
    int parameter;
    while (1)
    {
        int humanNumber = doChoice(people, sizePeople);
        if (humanNumber == 0)
        {
            return;
        }
        bool stop = false;
        while (!stop)
        {
            system("cls");
            printf("FIO: %-s %-s %-s  Home address: %-s  Phone number: %-s  Age: %-2d\n", people[humanNumber - 1].Surname, people[humanNumber - 1].Name, people[humanNumber - 1].Patronymic, people[humanNumber - 1].HomeAddress, people[humanNumber - 1].PhoneNumber, people[humanNumber - 1].Age);
            printf("1 - Edit surname\n2 - Edit name\n3 - Edit patronymic\n4 - Edit home address\n5 - Edit phone number\n6 - Edit age\n0 - Return\n");
            scanf("%d", &parameter);
            if (parameter == 1)
            {
                editHuman(humanNumber, "surname");
            }
            else if (parameter == 2)
            {
                editHuman(humanNumber, "name");
            }
            else if (parameter == 3)
            {
                editHuman(humanNumber, "patronymic");
            }
            else if (parameter == 4)
            {
                editHuman(humanNumber, "home address");
            }
            else if (parameter == 5)
            {
                editHuman(humanNumber, "phone number");
            }
            else if (parameter == 6)
            {
                editHuman(humanNumber, "age");
            }
            else if (parameter == 0)
            {
                stop = true;
            }
            else if (parameter < 0 || parameter > 6)
            {
                showMessage("Wrong number, please try again");
            }
        }
    }
}
void deleteHuman()
{
    while (1)
    {
        int humanNumber = doChoice(people, sizePeople);
        if (humanNumber == 0)
        {
            return;
        }
        for (int i = humanNumber - 1; i < sizePeople - 1; i++)
        {
            people[i] = people[i + 1];
        }
        sizePeople--;
        showMessage("Delete human successfully");
    }
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
        {
            return;
        }
        else if (parameter == 1)
        {
            addHuman();
        }
        else if (parameter == 2)
        {
            sortBy();
        }
        else if (parameter == 3)
        {
            searchMenu();
        }
        else if (parameter == 4)
        {
            editHumanMenu();
        }
        else if (parameter == 5)
        {
            deleteHuman();
        }
        else if (parameter == 6)
        {
            showPeople(people, sizePeople);
            system("pause");
        }
        else if (parameter < 0 || parameter > 6)
        {
            showMessage("Wrong number, please try again");
        }
    }
}
int main()
{
    menu();
    return 0;
}