#ifndef __ONEGMENU_H__
#define __ONEGMENU_H__

struct MassiveStings
{
    char** UnSortedBookStrings;
    char** SortedBookStrings;
    size_t NumberLines;
};

int Menu ();
void OutputText (char** BookStrings, const size_t NumberLines);
void MenuTitle (const size_t MenuNumber);
int MenuActions (size_t* MenuNumber, bool* IsConsole,
                  MassiveStings* MS);
void DelStruct (MassiveStings* MS);

#endif
