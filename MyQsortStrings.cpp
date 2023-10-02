#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "MyQsotrStrings.h"
#include "StringsFunc.h"

static void SortThree (char** text5, ComparType cmpstrings);
static void SortTwo (char** text5, ComparType cmpstrings);

void SortStrings (char** text5, const size_t NumberLines,
                  ComparType cmpstrings)
{
    if (NumberLines == 0 || NumberLines == 1)
    {
        return;
    }

    size_t Left = 0, Right = NumberLines-2;

    size_t Mid = Right/2;

    if ((Right - Left) == 1)
    {
        SortTwo(text5, cmpstrings);
        return;
    }
    else if ((Right - Left) == 2)
    {
        SortThree(text5, cmpstrings);
        return;
    }
    else
    {
        while (Left < Right)
        {

            int NumberGoodStings = 0;

            int ResultCmpLeftMid = cmpstrings(*(text5+Left),*(text5+Mid));
            int ResultCmpRightMid = cmpstrings(*(text5+Right),*(text5+Mid));

            if (ResultCmpLeftMid <= 0 && Left != Mid)
            {
                Left++;
                NumberGoodStings++;
            }

            if (ResultCmpRightMid > 0)
            {
                Right--;
                NumberGoodStings++;
            }

            if (NumberGoodStings == 0)
            {
                if (ResultCmpLeftMid == 0)
                {
                    Mid = Right;
                }
                else if (ResultCmpRightMid == 0)
                {
                    Mid = Left;
                }

                SwapStrings(text5+Left, text5+Right);
            }
        }
    }

    SortStrings(text5, Mid+1, cmpstrings);
    SortStrings(text5+Mid+1, NumberLines-Mid-1, cmpstrings);
}

static void SortTwo(char** text5, ComparType cmpstrings)
{
    if (cmpstrings(*(text5+0), *(text5+1)) > 0)
    {
        SwapStrings(text5, text5+1);
    }
}

static void SortThree (char** text5, ComparType cmpstrings)
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

