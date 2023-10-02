#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include "ReadBook.h"
#include "Color.h"
#include "InputFile.h"
#include "MyAssert.h"

char** FormsTextData (size_t* nlines)
{
    char file[MaxLenthFileName] = { };

    *nlines = InputInfFile((char*) file);

    char** BookStrings = (char**) FormsMassiveStrigns (file, nlines);

    return BookStrings;
}

char** FormsMassiveStrigns (const char filename[], size_t* nlines)
{                   //подумать о содержимым
    char* buf = ScanFile((char*) filename, nlines);

    char** text5 = (char**) calloc(*nlines, sizeof(char*));

    if (text5 == NULL)
    {
        exit(1); // ??
    }

    for (size_t NElem = 0, line = 1; line < *nlines; NElem++)
    {
        if (buf[NElem] == '\n')
        {                                                   // не всегда менять отд функ
            if (line + 1 < *nlines)
                text5[line] = (char*) (buf + NElem + 1);
            *(buf + NElem) = '\0';
            line++;
        }
    }

    text5[0] = buf;

    return text5;
}

char* ScanFile (char filename[], size_t* nlines)
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

            *nlines = InputInfFile(filename);

        }
        else
        {
            flag_exit = 0;
        }
    }

    GAssert(text != NULL);

    struct stat buff = { };
    fstat (fileno (text), &buff);

    char* buf = (char*) calloc(buff.st_size+1, sizeof(char));
    buf[buff.st_size] = '\n';

    fread(buf, sizeof(char), buff.st_size, text);

    fclose(text);

    return buf;
}
