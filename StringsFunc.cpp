#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "StringsFunc.h"

void SwapStrings (char** left_element, char** right_element)
{
    char* temp =  *left_element;
    *left_element = *right_element;
    *right_element =  temp;
}

int Mystrcmp (const char *str1, const char *str2)
{
    size_t i1 = 0, i2 = 0;
    while(!isalpha(str1[i1]) && (str1[i1] != '\0'))
    {
        i1++;
    }
    while(!isalpha(str2[i2]) && (str2[i2] != '\0'))
    {
        i2++;
    }
    while((str1[i1] != '\0') && (str2[i2] != '\0'))
    {
        if(tolower(str1[i1]) != tolower(str2[i2]))
        {
            return (tolower(str1[i1]) - tolower(str2[i2]));
        }
        i1++;
        i2++;
    }

    return tolower(str1[i1]) - tolower(str2[i2]);
}

int MystrcmpEnd (const char *str1, const char *str2)
{
    size_t i1 = strlen(str1)-1, i2 = strlen(str2)-1;   // change strlen to another way

    while((str1[i1] != '\0') && (str2[i2] != '\0'))
    {
                while(!isalpha(str1[i1]) && (str1[i1] != '\0'))
                {
                i1--;
                }
                while(!isalpha(str2[i2]) && (str2[i2] != '\0'))
                {
                i2--;
                }

        if(tolower(str1[i1]) != tolower(str2[i2]))
        {
            return (tolower(str1[i1]) - tolower(str2[i2]));
        }
        i1--;
        i2--;
    }

    return tolower(str1[i1]) - tolower(str2[i2]);
}
