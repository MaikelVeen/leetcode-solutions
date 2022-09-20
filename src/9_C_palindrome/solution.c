#include <stdio.h>
#include <limits.h>

int numPlaces(int n)
{
    if (n < 0)
        return numPlaces((n == INT_MIN) ? INT_MAX : -n);
    if (n < 10)
        return 1;
    return 1 + numPlaces(n / 10);
}

_Bool isPalindrome(int x)
{
    if (x < 0)
    {
        return 0;
    }

    int len = numPlaces(x);
    int digits[len];

    for (int i = 0; i < len; ++i)
    {
        digits[i] = x % 10;
        x /= 10;
    }

    int start = 0, end = len - 1;
    while (start != end && end > start)
    {
        if (digits[start] == digits[end])
        {
            ++start;
            --end;
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    printf("%d\n", isPalindrome(1529587));
    printf("%d\n", isPalindrome(121));
    printf("%d\n", isPalindrome(1221));

    return 0;
}
