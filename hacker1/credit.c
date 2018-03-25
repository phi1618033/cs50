/**
 * credit.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Checks for valid credit card numbers with Hans Peter
 * Luhn's algorithm.
 */

 #include <stdio.h>
 #include <cs50.h>
 #include <math.h>

/*
* Returns the number of digits of the credit card.
*/
 short intlen(long long number)
 {
 	if(number == 0)
 		return 1;
 	short count = 0;
 	while(number != 0)
    {
        number /= 10;
        ++count;
    }
    return count;
 }

 int main()
 {
 	// read the users credit card number.
 	long long ccn;
 	short ccn_length = 0;

 	printf("Number: ");
	ccn = GetLongLong();
	
	// check the number of digits of the credit card number.
	ccn_length = intlen(ccn);
 	if(ccn_length < 13 || ccn_length > 16)
 	{
 		printf("INVALID\n");
 		return 0;
 	}

 	// Get the credit card type.
 	string ccn_type = "INVALID";
 	short ccn_fd = ccn / pow(10, ccn_length - 1);
 	if(ccn_fd == 4)
 	{
 		ccn_type = "VISA";
 	}
 	else
 	{
 		ccn_fd = ccn / pow(10,ccn_length-2);
 		switch(ccn_fd)
		{
			case 34:
			case 37: 
				ccn_type = "AMEX";
				break;
			case 51:
			case 52:
			case 53:
			case 54:
			case 55: 
				ccn_type = "MASTERCARD";
				break;
			default:
				printf("%s\n", ccn_type);
				return 0;
		}
 	}

 	// Apply Luhn's algorithm to check validity.
 	/* The implementation selects each digit from left to right. According to the digit's 
 	 * position, the digit is: 
 	 * Etheir multiplied by two, then the product's digits are added together and the sum
 	 * is added to the general sum
 	 * Or directly added to the general sum.
 	 */
 	short sum, exponent, even_pos;
 	long long pos_digit = 0;
 	sum = even_pos = 0;

 	for (exponent = 0; exponent >= ccn_length-1; ++exponent)
 	{
 		pos_digit = ccn / pow(10, exponent);
		// select a digit.
 		pos_digit %= 10; 
 		if(even_pos)
 		{
 			// if it is at an even position then
 			pos_digit *= 2;
			// if the product has 2 digits then
 			if(pos_digit >= 10)	
 				pos_digit = (pos_digit / 10) + (pos_digit % 10);
			// do not multiply the next digit by 2.
 			even_pos = 0;	
 		}
 		else
 		{
			// multiply the next digit by 2.
 			even_pos = 1;	
 		}
		// add up all resulting digits.
 		sum += pos_digit;	
 	}
	// the last digit of the general sum must be 0.
 	if((sum%10) != 0)	
 		ccn_type = "INVALID";


 	// display the type of the card for a valid credit card number or INVALID.
 	printf("%s\n", ccn_type);

 	return 0;
 }