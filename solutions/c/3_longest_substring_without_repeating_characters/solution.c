#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    // Fill an array of 128 integers with -1;
    // -1 representing not found char.
    int chars[128], idx = 128;
    while (idx--)
        chars[idx] = -1;

    int start = -1, length = 0, localLength;
    size_t c;

    while (s[++idx] != '\0')
    {
        // Convert the char into integer.
        c = (size_t)s[idx];

        // If char is already found, set start to index of last occurence.
        if (chars[c] > start)
            start = chars[c];

        // Current length is difference between current index and last repeated char.
        localLength = idx - start;
        if (length < localLength)
            length = localLength;

        // Set the current index at the position of the char.
        chars[c] = idx;
    }
    return (start > -1 ? length : idx);
}

int main(void)
{
    printf("%d \n", lengthOfLongestSubstring("pwwkwe"));

    return 0;
}