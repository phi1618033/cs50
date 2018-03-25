/**
* pointerplay.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Playing with pointers.
**/

#include <stdio.h>
#include <cs50.h>

int a, b, c;
int* pa;
int* pb;
int* pc;

void print()
{
    printf("a: %d | b: %d | c: %d | pa: %p | pb: %p | pc: %p \n", a, b, c, pa, pb, pc);
}

int main(int argc, string argv[])
{
    // a = 3; 
    // b = 4;
    // c = 5;
   
    // pa = &a;
    // pb = &b;
    // pc = &c;

    // print();

    char* str = "happy cat";
    int counter = 0;
    for (char* ptr = str; *ptr != '\0'; ptr++)
    {
        counter++;
    }
    printf("%d\n", counter);
}