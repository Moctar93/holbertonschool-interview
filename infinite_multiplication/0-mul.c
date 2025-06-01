#include "holberton.h"
#include <stdlib.h>

/**
 * _isdigit - Checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if all digits, 0 otherwise.
 */
int _isdigit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * print_error - Prints "Error" and exits with status 98.
 */
void print_error(void)
{
	char *error = "Error\n";
	int i;

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	exit(98);
}

/**
 * multiply - Multiplies two positive numbers represented as strings.
 * @num1: The first number string.
 * @num2: The second number string.
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, carry, n1, n2, *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;
	result = calloc(len, sizeof(int));
	if (!result)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * main - Entry point for the program.
 * @argc: The number of arguments.
 * @argv: The arguments array.
 *
 * Return: 0 on success, exits with 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	if (!_isdigit(argv[1]) || !_isdigit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);
	return (0);
}
