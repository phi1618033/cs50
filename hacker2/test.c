/***************************************************************************
* test.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* 
***************************************************************************/

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/resource.h>
#include <sys/time.h>

#define UNUSED(x) (void)(x)

#undef calculate
#undef getrusage

#define PASSPHRASE_MAX_LENGTH 3
#define FIRST_CHAR 97
#define LAST_CHAR 99

char* phrase;

void genstr();
void gentest1();
void gentest2();
double calculate(const struct rusage* b, const struct rusage* a);

int main(void)
{
    // struct rusage before, after;
    // double timing;

    // getrusage(RUSAGE_SELF, &before);
    // gentest2();
    // getrusage(RUSAGE_SELF, &after);

    // timing = calculate(&before, &after);
    // printf("TIMING:       %.2f\n", timing);

    char key[] = "!";
    char* pwd = crypt(key, "CA");
    printf("%s\n", pwd);

    return 0;
}

void genstr()
{
    for(unsigned char i = 32; i < 127; i++)
        for(unsigned char j = 32; j < 127; j++)
            for(unsigned char k = 32; k < 127; k++)
                for(unsigned char l = 32; l < 127; l++)
                    for(unsigned char m = 32; m < 127; m++)
                        for(unsigned char n = 32; n < 127; n++)
                            for(unsigned char o = 32; o < 127; o++)
                                for(unsigned char p = 32; p < 127; p++)
                                {
                                    sprintf(phrase, "%c%c%c%c%c%c%c%c", i, j, k, l, m, n, o, p);
                                    char* __phrase = phrase;
                                    while(isspace((unsigned char)*__phrase))
                                        ++__phrase;
                                    printf("%s\n", __phrase);
                                }
                
}

void gentest1()
{
    phrase = (char*)malloc(sizeof(char) * PASSPHRASE_MAX_LENGTH);
    char* _phrase = phrase;
    for(unsigned char i = 32; i <= 80; i++)
        for(unsigned char j = 32; j <= 80; j++)
            for(unsigned char k = 32; k <= 80; k++)
            {
                sprintf(phrase, "%c%c%c", i, j, k);
                // char* __phrase = phrase;
                // while(isspace((unsigned char)*__phrase))
                //     ++__phrase;
                // printf("%s\n", __phrase);
                printf("%s\n", phrase);
            }
    free(_phrase);
                                
}

void iterate(char *str, int idx, int len) 
{
    char c;

    if (idx < (len - 1)) 
    {
        for (c = 32; c <= 80; ++c) 
        {
            str[idx] = c;
            iterate(str, idx + 1, len);
        }
    } 
    else 
    {
        for (c = 32; c <= 80; ++c) 
        {
            str[idx] = c;
            printf("%s\n", str);
        }
    }
}

void gentest2()
{
    int len = 3;
    char str[len + 1];
    memset(str, 0, len + 1);
    iterate(str, 0, len);           
}

/**
 * Returns number of seconds between b and a.
 */
double calculate(const struct rusage* b, const struct rusage* a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}

