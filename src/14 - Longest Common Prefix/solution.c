#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return;
    }

    if (strsSize == 1)
    {
        return strs[0];
    }

    int shortestWord = 200;

    for (int i = 0; i < strsSize; ++i)
    {
        int wordLength = strlen(strs[i]);
        if (wordLength < shortestWord)
        {
            shortestWord = wordLength;
        }
    }

    int len = 0;
    for (int i = 0; i < shortestWord; i++)
    {
        for (int j = 0; j < strsSize - 1; ++j)
        {
            if (strs[j][i] == strs[j + 1][i])
            {
                if (j == strsSize - 2)
                {
                    ++len;
                }

                continue;
            }
            else
            {
                goto out;
            }
        }
    }
out:
    if (len > 0)
    {
        char *commonPrefix = malloc((len + 1) * sizeof(char));
        // Set terminator just after the end of prefix.
        strs[0][len] = '\0';
        strcpy(commonPrefix, strs[0]);
        return commonPrefix;
    };

    return "";
}