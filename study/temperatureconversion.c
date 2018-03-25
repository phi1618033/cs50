/**
 * temperatureconversion.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Converts a temperature from Fahrenheit to Celcius.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(int argc, string argv[])
{
    // ask user for temperature
    float f;
    printf("Temperature in F: ");
    f = GetFloat();

    // convert F to C
    float c = (f - 32.0)*(5.0/9.0);

    // display result
    printf("Temperature in C: %.1f\n", c);
}

