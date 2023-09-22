#include <stdio.h>
#include "Clear_Buffer.h"
#include "MyAssert.h"
#include "Color.h"
#include "InputFile.h"

size_t inputbook (char file[])
{
    GAssert(file != NULL);

    BROWN;
    printf("*---------------------------------------------------------------*\n");
    YELLOW;
    printf("\tInput name of file and number of lines.\n");

    size_t nlines = 0;

    LIGHT_PURPLE;
    printf("Name of file: ");

    bool flag_exit = 1;
    while (flag_exit)
    {
        while (scanf("%s", file) != 1)
        {
            ClearStatusBuffer();

            LIGHT_RED;
            printf("Input correct name of file!\n");

            LIGHT_PURPLE;
            printf("Name of file: ");
        }

        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only name of file without extra symbols after.\n");

            LIGHT_PURPLE;
            printf("Name of file: ");
        }

        else
        {
            flag_exit = 0;
        }
    }

    BROWN;
    printf("Number lines in the book: ");

    flag_exit = 1;
    while (flag_exit)
    {
        while (scanf("%d", &nlines) != 1)
        {
            ClearStatusBuffer();

            LIGHT_RED;
            printf("Enter the correct number lines in the book.\n");

            BROWN;
            printf("Number lines in the book: ");
        }
        if (ClearStatusBuffer())
        {
            LIGHT_RED;
            printf("Input only the number of lines!\n");

            BROWN;
            printf("Number lines in the book: ");
        }
        else if (nlines == 0)
        {
            LIGHT_RED;
            printf("Book with zero lines, really?\n");

            BROWN;
            printf("Number lines in the book: ");
        }
        else
        {
            flag_exit = 0;
        }
    }

    GAssert(file != NULL);
    GAssert(nlines != 0);

    return nlines;
}
