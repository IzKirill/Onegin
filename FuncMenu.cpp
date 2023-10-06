#include <stdio.h>
#include "OnegMenu.h"
#include "ReadBook.h"
#include "Color.h"
#include "FuncMenu.h"
#include "Choice.h"
#include "MyQsotrStrings.h"
#include "GiveAwayFile.h"
#include "StringsFunc.h"

void PrintDelemiter ()
{
    printf("*-------------------------------------------------------------------------*\n");
}

void PrimaryWords ()
{
    BROWN;
    PrintDelemiter();
    LIGHT_BLUE;
    printf("\tHello, this program work with book.\n");
    LIGHT_GOLYBOI;
    printf("You can read the book on the console or in the file.\n"
    "You can sort the strings in the book by the first or last letter.\n");
    LIGHT_GREEN;
    printf("Good luck!\n");
}

void Menu1Title ()
{
    BROWN;
    PrintDelemiter();
    YELLOW;
    printf("\t   Where do you want to output the book?\n");
    GOLYBOI;
    printf("1: console\t");
    LIGHT_BLUE;
    printf("2: file\t\t");
    RED;
    WPrintf("3: exit\n");
}

void Menu2Title ()
{
    BROWN;
    PrintDelemiter();
    YELLOW;
    printf("\t\tWhat you want to do with this book?\n");
    BROWN;
    printf("1: read book\t");
    GREEN;
    printf("2: sort book\t");
    RED;
    WPrintf("3: back to menu\n");
}

void Menu3Title (void)
{
    BROWN;
    PrintDelemiter();
    YELLOW;
    printf("\t\tHow do you want to sort the book?\n");
    LIGHT_GOLYBOI;
    printf("1: sort by the first letter\t");
    LIGHT_GREY;
    printf("2: sort by the last letter\t");
    RED;
    WPrintf("3: back to menu\n");
}

void Menu4Title ()
{
    BROWN;
    PrintDelemiter();
    YELLOW;
    printf("\t\tDo you want to continue?\n");
    BLUE;
    printf("1: continue with this file\t");
    LIGHT_GREY;
    printf("2: back to main menu\t");
    RED;
    WPrintf("3: exit\n");
}

int SelectMenuError ()
{
    LIGHT_RED;
    printf("ERROR: Inccorect value of Nmenu.");

    return 0;
}

int Menu1Actions (size_t* MenuNumber, bool* IsConsole, MassiveStings* MS)
{
    switch(user_choice(3))
    {
    case(1):
        {
            *MenuNumber = 2;
            *IsConsole = 1;
        }
        break;

    case(2):
        {
            *MenuNumber = 2;
            *IsConsole = 0;
        }
        break;

    case(3):
        {
            DelStruct(MS);
            return 1;
        }
        break;

    default:
        {
            DelStruct(MS);
            SelectChoiceError();
        }
    }
    return 0;
}

int Menu2Actions (size_t* MenuNumber, bool* IsConsole,
                  MassiveStings* MS)
{
    switch(user_choice(3))
    {
    case(1):
        {
            if (*IsConsole)
            {
                OutputText(MS->UnSortedBookStrings, MS->NumberLines);
            }
            else
            {
                PrintInFile(MS->UnSortedBookStrings, MS->NumberLines);
            }
            *MenuNumber = 4;
        }
        break;

    case(2):
        {
            *MenuNumber = 3;
        }
        break;

    case(3):
        {
            *MenuNumber = 1;
        }
        break;

    default:
        {
            DelStruct(MS);
            SelectChoiceError();
        }
    }
    return 0;
}

int Menu3Actions (size_t* MenuNumber, bool* IsConsole,
                  MassiveStings* MS)
{
    switch(user_choice(3))
    {
    case(1):
        {
            SortStrings(MS->SortedBookStrings, MS->NumberLines, Mystrcmp);
            if (*IsConsole)
            {
                OutputText(MS->SortedBookStrings, MS->NumberLines);
            }
            else
            {
                PrintInFile(MS->SortedBookStrings, MS->NumberLines);
            }
            *MenuNumber = 4;
        }
        break;

    case(2):
        {
            SortStrings(MS->SortedBookStrings, MS->NumberLines, MystrcmpEnd);
            if (*IsConsole)
            {
                OutputText(MS->SortedBookStrings, MS->NumberLines);
            }
            else
            {
                PrintInFile(MS->SortedBookStrings, MS->NumberLines);
            }
            *MenuNumber = 4;
        }
        break;

    case(3):
        {
            *MenuNumber = 2;
        }
        break;

    default:
        {
            DelStruct(MS);
            SelectChoiceError();
        }
    }
    return 0;
}

int Menu4Actions (size_t* MenuNumber, MassiveStings* MS)
{
    switch(user_choice(3))
    {
    case(1):
        {
            *MenuNumber = 1;
        }
        break;

    case(2):
        {
            DelStruct(MS);
            Menu();
        }
        break;
    case(3):
        {
            DelStruct(MS);
            return 1;
        }
        break;

    default:
        {
            DelStruct(MS);
            SelectChoiceError();
        }
    }
    return 0;
}

void SelectChoiceError ()
{
    LIGHT_RED;
    printf("ERROR: Inccorect value of user_choice.");
}
