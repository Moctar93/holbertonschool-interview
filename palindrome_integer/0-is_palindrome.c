#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palinfrom, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int reverse = 0, remainder, number;


	number = n;

	while (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}
	if (number == reverse)
		return (1);
	else
		return (0);
}
