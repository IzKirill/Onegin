#ifndef __MYQSORTSTRINGS_H__
#define __MYQSORTSTRINGS_H__

void SortStrings (char** text5, const size_t lines,
                int (*cmpstrings) (const char *, const char *));
int sortbegin (const char** BookStrings, const size_t nlines);
int sortend (const char** BookStrings, const size_t nlines);

#endif
