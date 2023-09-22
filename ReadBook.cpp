#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "ReadBook.h"
#include "Color.h"
#include "InputFile.h"
#include "MyAssert.h"

char** inputdata (size_t* nlines)
{
    char file[30] = { };

    *nlines = inputbook((char*) file);

    char** BookStrings = (char**) ReadFile (file, nlines);

    return BookStrings;
}

char** ReadFile (const char filename[], size_t* nlines)
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

            *nlines = inputbook((char*) filename);

        }
        else
        {
            flag_exit = 0;
        }
    }

    GAssert(text != NULL);

    struct stat buff;
    fstat (fileno (text), &buff);

    char* buf = (char*) calloc(buff.st_size+1, sizeof(char));
    buf[buff.st_size] = '\n';

    fread(buf, sizeof(char), buff.st_size, text);

    fclose(text);

    char** text5 = (char**) calloc(*nlines, sizeof(char*));

    size_t NElem = 0, line = 1;

    while(line < *nlines)
    {
        if (buf[NElem] == '\n')
        {
            if (line + 1 < *nlines)
                text5[line] = (char*) (buf + NElem + 1);
            *(buf + NElem) = '\0';
            line++;
        }
        NElem++;
    }

    text5[0] = buf;

    return text5;
}
