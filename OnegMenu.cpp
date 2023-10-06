#include <stdio.h>
#include "OnegMenu.h"
#include "ReadBook.h"
#include "Color.h"
#include "Choice.h"
#include <strings.h>
#include <ctype.h>
#include "FuncMenu.h"

int Menu ()
{
    PrimaryWords();

    MassiveStings MS = {};

    FormsTextData (&MS);

    if (MS.UnSortedBookStrings == nullptr || MS.SortedBookStrings == nullptr)
    {
        LIGHT_RED;
        printf("Incorrect value of BookStrings.\n");

        return 0;
    }

    size_t MenuNumber = 1;
    bool IsConsole = 0;

    while(1)
    {
        MenuTitle(MenuNumber);

        if (MenuActions(&MenuNumber, &IsConsole,
                       &MS) == 1)
        {
            return 0;
        }
    }
}

void MenuTitle (const size_t MenuNumber)
{
    switch (MenuNumber)
    {
    case(1):
        {
            Menu1Title();
        }
        break;
    case(2):
        {
            Menu2Title();
        }
        break;

    case(3):
        {
            Menu3Title();
        }
        break;

    case(4):
        {
            Menu4Title();
        }
        break;

    default:
        {
            SelectMenuError();
        }
    }
}

int MenuActions (size_t* MenuNumber, bool* IsConsole,
                  MassiveStings* MS)
{
    switch (*MenuNumber)
    {
    case(1):
        {
            if (Menu1Actions(MenuNumber, IsConsole, MS))
            {
                return 1;
            }
        }
        break;

    case(2):
        {
            Menu2Actions(MenuNumber, IsConsole, MS);

        }
        break;

    case(3):
        {
            Menu3Actions(MenuNumber, IsConsole, MS);
        }
        break;

    case(4):
        {
            if (Menu4Actions(MenuNumber, MS))
            {
                return 1;
            }
        }
        break;

    default:
        {
            SelectMenuError();
        }
    }
    return 0 ;
}

void OutputText (char** BookStrings, const size_t NumberLines)
{
    for(size_t StringNumber = 0; StringNumber < (NumberLines-1); StringNumber++)
    {
        printf("%s\n", *(BookStrings+StringNumber));
    }
}

void DelStruct (MassiveStings* MS)
{
    free(MS->SortedBookStrings);
    free(MS->UnSortedBookStrings);
    MS->NumberLines = 0;
}
