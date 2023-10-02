#ifndef __ONEGMENU_H__
#define __ONEGMENU_H__

int Menu (char** BookStrings, size_t NumberLines);
void ReadBook (char** BookStrings, const size_t NumberLines);
void MenuTitle (const size_t MenuNumber);
int MenuActions (size_t* MenuNumber, bool* IsConsole,
                  char** BookStrings, size_t NumberLines);

#endif
