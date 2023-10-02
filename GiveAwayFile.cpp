#include <stdio.h>
#include "GiveAwayFile.h"
#include "Color.h"

int PrintInFile(char** BookStrings, const size_t NumberLines)
{
    FILE* TextFile = fopen("Book.txt", "w");

    for (size_t Line = 0; Line < NumberLines; Line++)
    {
        fprintf(TextFile,"%s\n", *(BookStrings+Line));
    }

    fclose(TextFile);

    LIGHT_GREEN;
    printf("Your text is successfully moved to file Book.txt.\n");

    return 0;
}
