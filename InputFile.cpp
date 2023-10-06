#include <stdio.h>
#include "Clear_Buffer.h"
#include "MyAssert.h"
#include "Color.h"
#include "InputFile.h"
#include "OnegMenu.h"
#include "ReadBook.h"
#include <string.h>

size_t InputInfFile (char filename[])
{
    GAssert(filename != NULL);

    BROWN;
    printf("*---------------------------------------------------------------*\n");
    YELLOW;
    WPrintf("\tInput name of file(<30 symbols).\n");

    LIGHT_PURPLE;
    WPrintf("Name of file: ");

    bool flag_exit = 1;
    while (flag_exit)
    {
        while (scanf("%s", filename) != 1)
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

        else if (strlen(filename) <= MaxLenthFileName)
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

    GAssert(filename != NULL);

    return 0;
}
