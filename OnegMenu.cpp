#include "Color.h"
#include "OnegMenu.h"
#include "Choice.h"
#include "MyQsotrStrings.h"
#include "GiveAwayFile.h"
#include "ReadBook.h"
#include <strings.h>
#include <ctype.h>

int menu (char** BookStrings, size_t nlines)
{
    size_t Nmenu = 1;
    bool isconsole = 0;

    while(1)
    {
        switch (Nmenu)
        {
        case(1):
            {
                BROWN;
                printf("*-------------------------------------------------------------------------*\n");
                YELLOW;
                printf("\t   Where do you want to output the book?\n");
                GOLYBOI;
                printf("1: console\t");
                LIGHT_BLUE;
                printf("2: file\t\t");
                RED;
                printf("3: exit\n");
            }
            break;
        case(2):
            {
                BROWN;
                printf("*-------------------------------------------------------------------------*\n");
                YELLOW;
                printf("\t\tWhat you want to do with this book?\n");
                BROWN;
                printf("1: read book\t");
                GREEN;
                printf("2: sort book\t");
                RED;
                printf("3: back to menu\n");
            }
            break;

        case(3):
            {
                BROWN;
                printf("*-------------------------------------------------------------------------*\n");
                YELLOW;
                printf("\t\tHow do you want to sort the book?\n");
                LIGHT_GOLYBOI;
                printf("1: sort by the first letter\t");
                LIGHT_GREY;
                printf("2: sort by the last letter\t");
                RED;
                printf("3: back to menu\n");
            }
            break;

        case(4):
            {
                BROWN;
                printf("*-------------------------------------------------------------------------*\n");
                YELLOW;
                printf("\t\tDo you want to continue?\n");
                BLUE;
                printf("1: continue\t\t");
                RED;
                printf("2: exit\n");
            }
            break;

        default:
            {
                LIGHT_RED;
                printf("ERROR: Inccorect value of Nmenu.");

                return 0;
            }
        }

        switch(user_choice())
        {
        case(1):
            {
                switch (Nmenu)
                {
                case(1):
                    {
                        Nmenu = 2;
                        isconsole = 1;
                    }
                    break;

                case(2):
                    {
                        if (isconsole)
                        {
                            readbook((char**) BookStrings, nlines);
                        }
                        else
                        {
                            GivetoFile((const char**) BookStrings, nlines);
                        }
                        Nmenu = 4;
                    }
                    break;
                case(3):
                    {
                        sortbegin((const char**) BookStrings, nlines);
                        if (isconsole)
                        {
                            readbook((char**) BookStrings, nlines);
                        }
                        else
                        {
                            GivetoFile((const char**) BookStrings, nlines);
                        }
                        Nmenu = 4;
                    }
                    break;

                case(4):
                    {
                        BookStrings = inputdata(&nlines);
                        Nmenu = 1;
                    }
                    break;

                default:
                    {
                        LIGHT_RED;
                        printf("ERROR: Inccorect value of Nmenu.");

                        return 0;
                    }
                }
            }
            break;

        case(2):
            {
                switch(Nmenu)
                {
                case(1):
                    {
                        Nmenu = 2;
                        isconsole = 0;
                    }
                    break;

                case(2):
                    {
                        Nmenu = 3;
                    }
                    break;

                case(3):
                    {
                        sortend((const char**) BookStrings, nlines);
                        if (isconsole)
                        {
                            readbook((char**) BookStrings, nlines);
                        }
                        else
                        {
                            GivetoFile((const char**) BookStrings, nlines);
                        }
                        Nmenu = 4;
                    }
                    break;

                case(4):
                    {
                        return 0;
                    }
                    break;
                default:
                    {
                        LIGHT_RED;
                        printf("ERROR: Inccorect value of Nmenu.");

                        return 0;
                    }
                }
            }
            break;

        case(3):
            {
                switch (Nmenu)
                {
                case(1):
                    {
                        return 0;
                    }
                    break;

                case(2):
                    {
                        Nmenu = 1;
                    }
                    break;

                case(3):
                    {
                        Nmenu = 2;
                    }
                    break;

                default:
                    {
                        LIGHT_RED;
                        printf("ERROR: Inccorect value of Nmenu.");

                        return 0;
                    }
                }
            }
            break;

        default:
            {
                LIGHT_RED;
                printf("ERROR: Inccorect value of user_choice.");

                return 0;
            }
        }
    }
}

void readbook (char** BookStrings, const size_t nlines)
{
    for(size_t nstring = 0; nstring < nlines; nstring++)
    {
        printf("%s\n", *(BookStrings+nstring));
        free((void*) BookStrings[nstring]);
    }
}
