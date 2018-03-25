#include <stdio.h>
#include <string.h>

void iterate(char *str, int idx, int len) 
{
    char c;

    if (idx < (len - 1)) 
    {
        for (c = 97; c <= 99; ++c) 
        {
            str[idx] = c;
            iterate(str, idx + 1, len);
        }
    } 
    else 
    {
        for (c = 97; c <= 99; ++c) 
        {
            str[idx] = c;
            printf("%s\n", str);
        }
    }
}

#define LEN 2

int main(void) 
{
    char str[LEN + 1];

    memset(str, 0, LEN + 1);

    iterate(str, 0, LEN);
}