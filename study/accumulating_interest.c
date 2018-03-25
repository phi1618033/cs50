/**
 * accumulating_interest.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Calculates accumulated interest.
 */

#include <cs50.h>
#include <stdio.h>

double accumulate_interest(double balance, double rate);

int main(void)
{
    printf("Starting balance: ");
    double start = GetDouble();
    printf("Annual interest rate: ");
    double interest = GetDouble();
    double updated = accumulate_interest(start, interest);
    printf("Updated balance: %.2f\n", updated);
}

double accumulate_interest(double balance, double rate)
{
	// multiply starting balance by interest rate
	double acc_int = balance * rate;

    // add interest to starting balance
    balance += acc_int;

    // return updated balance
    return balance;
}

