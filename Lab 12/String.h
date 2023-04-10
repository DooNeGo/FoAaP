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
String *StringConstructor(unsigned int initialSize);
CodeStatus StringAdd(String *arr, const char *string);
CodeStatus StringAddCharElem(String *arr, const char elem);
CodeStatus StringClear(String *str, int initialSize);
char *StringGetValue(const String *arr);
CodeStatus StringSetValue(String *arr, const char *string);
int StringSize();
char StringElem(const String *str, unsigned int index);
int StringCount(const String *str);
Bool IsEqualStrings(const String *str, const String *str1);
Bool StringEqual(const String *str, const void *elem);
CodeStatus StringFree(String *str);

#endif