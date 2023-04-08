#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
    ArgumentOutOfRangeException = 2,
} CodeStatus;

#endif

#ifndef BOOL
#define BOOL

typedef enum Bool
{
    False = 0,
    True = 1,
} Bool;

#endif

#ifndef STRING
#define STRING

typedef struct String String;
String *ConstructString(int initialSize);
CodeStatus InsertCharArrToString(String *arr, const char *string);
CodeStatus InsertElemToString(String *arr, const char elem);
CodeStatus ClearString(String *arr);
char *ConvertStringToCharArray(const String *arr);
CodeStatus SetCharArrToString(String *arr, const char *string);
int GetSizeOfString();
char GetStringElem(String *str, unsigned int index);
int GetCountString(const String *str);
CodeStatus SetPtrString(String *dest, String *source);
CodeStatus SetString(String *dest, const String source);
Bool IsEqualStrings(const String *str, const String *str1);

#endif