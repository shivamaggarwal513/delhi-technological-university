#include "Functions.h"

char a[50] = "Shivam";
char b[50] = "Aggarwal";

char* strCat(char* dest, const char* source)
{
    int i = strLen(dest);
    for (int j = 0; source[j] != '\0'; i++, j++)
        dest[i] = source[j];
    dest[i] = '\0';
    return dest;
}

char* strRev(char* str)
{
    int j = strLen(str) - 1;
    char temp;
    for (int i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

char* strUpr(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return str;
}

char* strLwr(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    return str;
}

int strLen(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int strCmp(const char* str1, const char* str2)
{
    int i = 0;
    while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
        i++;
    return str1[i] - str2[i];
}