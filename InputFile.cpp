#include <stdio.h>
#include "Clear_Buffer.h"
#include "MyAssert.h"
#include "Color.h"
#include "InputFile.h"
#include "ReadBook.h"
#include <string.h>

size_t InputInfFile (char file[])
{
    GAssert(file != NULL);

    BROWN;
    printf("*---------------------------------------------------------------*\n");
    YELLOW;
    WPrintf("\tInput name of file(<30 symbols) and number of lines.\n");

    size_t NumberLines = 0;

    LIGHT_PURPLE;
    WPrintf("Name of file: ");

    bool flag_exit = 1;
    while (flag_exit)
    {
        while (scanf("%s", file) != 1)
        {
            ClearStatusBuffer();

            LIGHT_RED;
            printf("Input correct name of file!\n");

            LIGHT_PURPLE;
            WPrintf("Name of file: ");
        }

        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only name of file without extra symbols after.\n");

            LIGHT_PURPLE;
            WPrintf("Name of file: ");
        }

        else if (strlen(file) <= MaxLenthFileName)
        {
            flag_exit = 0;
        }

        else
        {
            LIGHT_RED;
            printf("Input name file less than 30 symbols, please.\n");

            LIGHT_PURPLE;
            WPrintf("Name of file: ");
        }
    }

    BROWN;
    WPrintf("Number lines in the book: ");

    flag_exit = 1;
    while (flag_exit)
    {
        while (scanf("%d", &NumberLines) != 1)
        {
            ClearStatusBuffer();

            LIGHT_RED;
            printf("Enter the correct number lines in the book.\n");

            BROWN;
            WPrintf("Number lines in the book: ");
        }
        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only the number of lines!\n");

            BROWN;
            WPrintf("Number lines in the book: ");
        }
        else if (NumberLines == 0)
        {
            LIGHT_RED;
            printf("Book with zero lines, really?\n");

            BROWN;
            WPrintf("Number lines in the book: ");
        }
        else
        {
            flag_exit = 0;
        }
    }

    GAssert(file != NULL);
    GAssert(NumberLines != 0);

    return NumberLines;
}
