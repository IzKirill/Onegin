#include <stdio.h>
#include "GiveAwayFile.h"
#include "Color.h"
#include "OnegMenu.h"

int PrintInFile(char** BookStrings, const size_t NumberLines)
{
    FILE* TextFile = fopen("Book.txt", "w");

    if (TextFile == NULL)
    {
        LIGHT_RED;
        printf("Cannot open source file.\n\n");

        exit(2); // ???
    }

    for (size_t Line = 0; Line < (NumberLines-1); Line++)
    {
        fprintf(TextFile,"%s\n", *(BookStrings+Line));
    }

    fclose(TextFile);

    LIGHT_GREEN;
    printf("Your text is successfully moved to file Book.txt.\n");

    return 0;
}
