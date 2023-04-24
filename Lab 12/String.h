#ifndef CODE_STATUS
#define CODE_STATUS

typedef enum CodeStatus
{
    SUCCESSFUL_CODE = 0,
    UNSUCCESSFUL_CODE = 1,
} CodeStatus;

#endif

#ifndef BOOL
#define BOOL

typedef enum Bool
{
    FALSE = 0,
    TRUE = 1,
} Bool;

#endif

#ifndef STRING
#define STRING

typedef struct String String;
String *StringConstructor(unsigned int initialSize);
CodeStatus StringAdd(String *str, const char *string);
CodeStatus StringAddCharElem(String *str, const char elem);
CodeStatus StringClear(String *str, unsigned int initialSize);
char *StringGetValue(const String *str);
CodeStatus StringSetValue(String *str, const char *string);
int StringSize();
char StringElem(const String *str, unsigned int index);
int StringLength(const String *str);
int StringCapacity(const String *str);
Bool IsStringsEqual(const String *str, const String *str1);
Bool StringEquals(const String *str, const void *elem);
CodeStatus StringFree(String *str);

#endif