#include "Color.h"
#include "OnegMenu.h"
#include "Choice.h"
#include <strings.h>
#include <ctype.h>
#include "FuncMenu.h"

int Menu (char** BookStrings, size_t NumberLines)
{
    size_t MenuNumber = 1;
    bool IsConsole = 0;

    while(1)
    {
        MenuTitle(MenuNumber);

        if (MenuActions(&MenuNumber, &IsConsole,
                       (char**) BookStrings, NumberLines) == 1)
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
                  char** BookStrings, size_t NumberLines)
{
    switch (*MenuNumber)
    {
    case(1):
        {
            if (Menu1Actions(MenuNumber, IsConsole))
            {
                return 1;
            }
        }
        break;

    case(2):
        {
            Menu2Actions(MenuNumber, IsConsole, (char**) BookStrings, NumberLines);

        }
        break;

    case(3):
        {
            Menu3Actions(MenuNumber, IsConsole, (char**) BookStrings, NumberLines);
        }
        break;

    case(4):
        {
            if (Menu4Actions(MenuNumber, (char**) BookStrings, NumberLines))
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

void ReadBook (char** BookStrings, const size_t NumberLines)
{
    for(size_t StringNumber = 0; StringNumber < NumberLines; StringNumber++)
    {
        printf("%s\n", *(BookStrings+StringNumber));
    }
    free(BookStrings); // отдельную функцию
}
