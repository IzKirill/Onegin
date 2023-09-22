#include <stdio.h>
#include <stdlib.h>
#include "ReadBook.h"
#include "OnegMenu.h"
#include "InputFile.h"
#include "Color.h"

int main ()
{
    BROWN;
    printf("*---------------------------------------------------------------*\n");
    LIGHT_BLUE;
    printf("\tHello, this program work with book.\n");
    LIGHT_GOLYBOI;
    printf("You can read the book on the console or in the file.\n"
    "You can sort the strings in the book by the first or last letter.\n");
    LIGHT_GREEN;
    printf("Good luck!\n");

    size_t nlines = 0;

    char** BookStrings = inputdata (&nlines);

    if (BookStrings == nullptr)
    {
        LIGHT_RED;
        printf("Incorrect value of BookStrings.\n");

        return 0;
    }

    return menu(BookStrings, nlines);
}
