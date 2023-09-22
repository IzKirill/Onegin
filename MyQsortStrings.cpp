#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "MyQsotrStrings.h"
#include "StringsFunc.h"

static void SortThree (char** text5, int (*cmpstrings) (const char *, const char *));
static void SortTwo (char** text5, int (*cmpstrings) (const char *, const char *));

int sortbegin (const char** BookStrings, const size_t nlines)
{
    SortStrings((char**) BookStrings, nlines, Mystrcmp);
    return 0;
}

int sortend (const char** BookStrings, const size_t nlines)
{
    SortStrings((char**) BookStrings, nlines, MystrcmpEnd);
    return 0;
}

void SortStrings (char** text5, const size_t lines,
                  int (*cmpstrings) (const char *, const char *))
{
    if (lines == 0 || lines == 1)
    {
        return;
    }

    size_t left = 0, right = lines-2;

    size_t mid = right/2;

    if ((right - left) == 1)
    {
        SortTwo(text5, cmpstrings);
        return;
    }
    else if ((right - left) == 2)
    {
        SortThree(text5, cmpstrings);
        return;
    }
    else while (left < right)
    {

        int i = 0;

        if (cmpstrings(*(text5+left),*(text5+mid)) <= 0 && left != mid)
        {
            left++;
            i++;
        }

        if (cmpstrings(*(text5+right),*(text5+mid)) > 0)
        {
            right--;
            i++;
        }

        if (i == 0)
        {
            if (cmpstrings(*(text5+left),*(text5+mid)) == 0)
            {
                mid = right;
            }
            else if (cmpstrings(*(text5+right),*(text5+mid)) == 0)
            {
                mid = left;
            }

            SwapStrings(text5+left, text5+right);
        }
    }

    SortStrings(text5, mid+1, cmpstrings);
    SortStrings(text5+mid+1, lines-mid-1, cmpstrings);
}

static void SortTwo(char** text5, int (*cmpstrings) (const char *, const char *))
{
    if (cmpstrings(*(text5+0), *(text5+1)) > 0)
    {
        SwapStrings(text5, text5+1);
    }
}

static void SortThree (char** text5, int (*cmpstrings) (const char *, const char *))
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = i+1; j < 3; j++)
        {
            if (cmpstrings(*(text5+i), *(text5+j)) > 0)
            {
                SwapStrings(text5+i, text5+j);
            }
        }
    }
}

