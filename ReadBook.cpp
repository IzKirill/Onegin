#include <stdio.h>
#include <stdlib.h>
#include "OnegMenu.h"
#include "FileWorkFunc.h"
#include "ReadBook.h"
#include "InputFile.h"

int FormsTextData (MassiveStings* MS)
{
    char file[MaxLenthFileName] = {};

    InputInfFile((char*) file);

    FormsMassiveStrigns (file, MS);

    return 0;
}

