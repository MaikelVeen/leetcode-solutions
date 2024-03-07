#include <stdio.h>
#include <string.h>

_Bool isValid(char *s)
{
    short len = strlen(s);

    if (len % 2 != 0)
        return 0;

    short indexOpen = 0;
    char open[len];

    for (short i = 0; i < len; ++i)
        switch (s[i])
        {
        case '{':
            open[indexOpen] = s[i];
            ++indexOpen;
            break;
        case '}':
            if (indexOpen > 0 && open[indexOpen - 1] == '{')
                --indexOpen;
            else
                return 0;
            break;
        case '[':
            open[indexOpen] = s[i];
            ++indexOpen;
            break;
        case ']':
            if (indexOpen > 0 && open[indexOpen - 1] == '[')
                --indexOpen;
            else
                return 0;
            break;
        case '(':
            open[indexOpen] = s[i];
            ++indexOpen;
            break;
        case ')':
            if (indexOpen > 0 && open[indexOpen - 1] == '(')
                --indexOpen;
            else
                return 0;
            break;
        default:
            return 0;
        }

    if (indexOpen == 0)
        return 1;
    else
        return 0;
}