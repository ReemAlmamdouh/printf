#include "main.h"
/**
 * is_printable A function that checks if character is printable.
 * @character: character to be checked.
 *
 * Return: 1 if true, 0 otherwise.
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud.
 * ALX Software Engineering Cohort 12.
 */
int is_printable(char character)
{
	if (character >= 32 && character < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * is_digit - A function that checks if character is digit.
 * @character: Character to be checked.
 *
 * Return: 1 if it's a digit, 0 otherwise.
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud.
 * ALX Software Engineering Cohort 12.
 */
int is_digit(char character)
{
	if (character >= '0' && character <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - Append ASCII Hexa-Code to Buffer.
 * @buffer: Array Of Characters.
 * @i: An Index To Start Appending.
 * @ascii_code: ASCII Code.
 *
 * Return: Always 3
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud.
 * ALX Software Engineering Cohort 12.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char mapping[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code = ascii_code * -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = mapping[ascii_code / 16];
	buffer[i] = mapping[ascii_code % 16];

	return (3);
}

/**
 * convert_size_number - Casting a number of a specified size
 * @num: Casted Number.
 * @size: Number for type to be casted
 *
 * Return: Value of number.
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud.
 * ALX Software Engineering Cohort 12.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Casted Number.
 * @size: Number for type to be casted.
 *
 * Return: Value of number
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
