#ifndef __READBOOK_H__
#define __READBOOK_H__

const int MaxLenthFileName = 30;

char* ScanFile (char filename[], size_t* nlines);
char** FormsMassiveStrigns (const char filename[], size_t* nlines);
char** FormsTextData (size_t* nlines);

#endif
