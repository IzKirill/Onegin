#ifndef __MYQSORTSTRINGS_H__
#define __MYQSORTSTRINGS_H__

typedef int (*ComparType) (const char *, const char *);

void SortStrings (char** text5, const size_t lines,
                ComparType cmpstrings);
#endif
