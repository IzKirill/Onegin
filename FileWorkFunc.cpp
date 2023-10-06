#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "OnegMenu.h"
#include "MyAssert.h"
#include "FileWorkFunc.h"
#include "InputFile.h"
#include "Color.h"

int FormsMassiveStrigns (char filename[], MassiveStings* MS)
{
    char* buf = ScanFile((char*) filename, MS);

    MS->SortedBookStrings = (char**) calloc(MS->NumberLines, sizeof(char*));
    MS->UnSortedBookStrings = (char**) calloc(MS->NumberLines, sizeof(char*));

    if (MS->SortedBookStrings == NULL || MS->UnSortedBookStrings == NULL)
    {
        exit(1); // ??
    }

    for (size_t NElem = 0, line = 1; line <= MS->NumberLines; NElem++)
    {
        if (buf[NElem] == '\n')
        {                                                   // не всегда менять отд функ
            if (line < (MS->NumberLines - 1))
            {
                MS->SortedBookStrings[line] = (char*) (buf + NElem + 1);
                MS->UnSortedBookStrings[line] = (char*) (buf + NElem + 1);
            }
            *(buf + NElem) = '\0';
            line++;
        }
    }

    MS->UnSortedBookStrings[0] = buf;
    MS->SortedBookStrings[0] = buf;

    free(buf);

    return 0;
}

char* ScanFile (char filename[], MassiveStings* MS)
{
    FILE *text = NULL;

    bool flag_exit = 1;

    while (flag_exit)
    {
        text = fopen(filename, "r");

        if (text == NULL)
        {
            LIGHT_RED;
            printf("Cannot open source file.\n\n");

            InputInfFile(filename);

        }
        else
        {
            flag_exit = 0;
        }
    }

    GAssert(text != NULL);

    char TimeBuf[MAX_COUNT_CHARS] = {};
    while (!feof(text) && !ferror(text))
    {
         fgets(TimeBuf, MAX_COUNT_CHARS, text);
         (MS->NumberLines)++;
    }

    if (ferror(text))
    {
        LIGHT_RED;
        printf("File Error.\n");
        exit(1);         // ??
    }

    rewind(text);

    struct stat buff = {};
    fstat (fileno (text), &buff);

    char* buf = (char*) calloc(buff.st_size+1, sizeof(char));

    fread(buf, sizeof(char), buff.st_size, text);

    buf[buff.st_size] = '\0';

    fclose(text);

    return buf;
}
