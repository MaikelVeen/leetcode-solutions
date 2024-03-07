#include <stdio.h>
#include <string.h>

_Bool checkIfPangram(char *sentence)
{
    int alpha[26], idx = 26;
    while (idx--)
        alpha[idx] = -1;

    int len = strlen(sentence);

    for (int i = 0; i < len; i++)
    {
        int c = (int)sentence[i];
        alpha[c % 26] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] < 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    printf("%d \n", checkIfPangram("leetcode"));
    printf("%d \n", checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));

    return 0;
}
