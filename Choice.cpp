#include <stdio.h>
#include "Choice.h"
#include "Clear_Buffer.h"
#include "Color.h"

size_t user_choice (const size_t NumberChoices)
{
    size_t your_choice = 0, flag_exit = 1;

    while(flag_exit)
    {
        while (scanf("%d", &your_choice) != 1 )
        {
            ClearStatusBuffer();
            LIGHT_RED;
            WPrintf("Please, write a number!\n");
        }

        size_t NumberFalls = 0;
        for (size_t i = 1; i <= NumberChoices; i++)
        {
            if (your_choice != i)
                NumberFalls++;
        }

        if (NumberFalls != NumberChoices - 1)
        {
            ClearStatusBuffer();
            LIGHT_RED;
            WPrintf("Please, write a correct number!!\n");
        }
        else
        {
            if (ClearStatusBuffer())
            {
                LIGHT_RED;
                WPrintf("Input only number and only one!\n");
            }
            else
            {
                flag_exit = 0;
            }
        }
    }

    return your_choice;
}
