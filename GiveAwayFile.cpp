#include <stdio.h>
#include "GiveAwayFile.h"
#include "Color.h"

int GivetoFile(const char** BookStrings, const size_t nlines)
{
    FILE* book = fopen("Book.txt", "w");

    for (size_t line = 0; line < nlines; line++)
    {
        fprintf(book,"%s\n", *(BookStrings+line));
    }

    fclose(book);

    LIGHT_GREEN;
    printf("Book is successfully moved to file Book.txt.\n");

    return 0;
}
