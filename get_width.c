#include "main.h"
/**
 * get_width - A function that calculates the width
 * @format:  Strings format in which to print the arguments
 * @i: Printed Arguments List
 * @argumentList: List of arguments
 *
 * Return: width
 *
 * Authors: Ahmed Abdel Nasser & Reem AlMamdouh
 * ALX Software Engineering Cohort 12
 */
int get_width(const char *format, int *i, va_list aList)
{
	int width = 0;
	int curr_i;

	for (curr_i = *i + 1 ; format[curr_i] != '\0' ; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width = width * 10;
			width = width + format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(aList, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_i - 1;
	return (width);
}
