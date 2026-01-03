#include <stdio.h>
#include "stack.h"

int pali(void)
{
    int i;
    int flag = 1;

    for (i = 0; i <= top / 2; i++)
    {
        if (stack[i] != stack[top - i])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}
