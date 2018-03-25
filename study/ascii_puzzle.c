/**
* ascii_puzzle.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Pass the seven chars to printf() so that executing your code will print the word "POINTER". 
**/

#include <stdio.h>

int main(void)
{
   int s = 65;
   int* t = &s;

   // TODO: Print "POINTER" using these chars 

   char C = 'I';
   char N = s + 'P' - 'A';
   char B = *t - s + N + 2;
   char E = &s - t + 78;
   char J = *t + 19;
   char I = N + 'A' - s - 1;
   char O = 347/5;

   printf("%c%c%c%c%c%c%c\n", N, I, C, E, J, O, B);
}