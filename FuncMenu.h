#ifndef __FUNCMENU_H__
#define __FUNCMENU_H__

void PrintDelemiter (void);
void Menu1Title(void);
void Menu2Title(void);
void Menu3Title(void);
void Menu4Title(void);
int SelectMenuError(void);
void SelectChoiceError(void);
int Menu1Actions(size_t* MenuNumber, bool* IsConsole);
int Menu2Actions(size_t* MenuNumber, bool* IsConsole,
                 char** BookStrings, size_t NumberLines);
int Menu3Actions(size_t* MenuNumber, bool* IsConsole,
                 char** BookStrings, size_t NumberLines);
int Menu4Actions(size_t* MenuNumber, char** BookStrings, size_t NumberLines);

#endif
