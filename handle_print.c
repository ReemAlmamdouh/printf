#include "main.h"
/**
 * handle_print - A function that prints an argument
 *                , based on its type.
 * @format: Pointer to formatted strings
 *          , in order to print the arguments.
 * @ind: Pointer to the current index of the formatted string.
 * @argumentsList: List of Arguments To Be Printed.
 * @buffer: Buffer array to handle print.
 * @flags: Parameter that calculates active flags.
 * @width: Geting Width Of The Printed String.
 * @precision: Precision Specifier.
 * @size: Size Specifier.
 *
 * Return: 1 or 2
 *
 * Authors: Ahmed Abdel Nasser & Reem Al-Mahmoud
 * ALX Software Engineering Cohort 12
 */
int handle_print(const char *format, int *ind, va_list argumentsList, char buffer[],
		int flags, int width, int precision, int size)
{
	int i;
	int argumentLength = 0;
	int printedCharactersNumber = -1;

	fmt_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string},  {'\0', NULL}
	};
	for (i = 0 ; format_types[i].fmt != '\0' ; i++)
	{
		if (format[*ind] == format_types[i].fmt)
		{
			return (format_types[i].fn(argumentsList, buffer, flags,
					       	width, precision, size));
		}
	}

	if (format_types[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
		{
			return (-1);
		}
		argumentLength = argumentLength + write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
		{
			argumentLength = argumentLength + write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (format[*ind] != '%' && format[*ind] != ' ')
			{
				--(*ind);
			}
			if (format[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}
		argumentLength = argumentLength + write(1, &format[*ind], 1);
		return (argumentLength);
	}
	return (printedCharactersNumber);
}
