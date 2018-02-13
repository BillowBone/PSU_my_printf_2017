/*
** EPITECH PROJECT, 2017
** my_printf2.c
** File description:
** Part 2 of the my_printf function code
*/

#include <unistd.h>
#include <stdarg.h>
#include "include.h"

int percent_flag(char c, int *j, int flag)
{
	if ((c == '%') && (flag == 1)) {
		my_putchar('%');
		*j = *j + 1;
		return (0);
	}
	if (flag == 1)
		return (1);
	if (flag == 0)
		return (0);
	return (0);
}

int my_putconvert(char c, int flag, long nb)
{
	if ((c == 'b') && (flag == 1))
		my_putstr(binary(nb));
	if ((c == 'u') && (flag == 1))
		my_put_unsigned(nb);
	if ((c == 'o') && (flag == 1))
		my_putstr(octal(nb));
	if (((c == 'x') || (c == 'X')) && (flag == 1))
		my_putstr(hexadecimal(nb, c));
	if ((c == 'p') && (flag == 1)) {
		my_putstr("0x");
		my_putstr(hexadecimal(nb, c));
	}
	if (((c == 'd') || (c == 'i')) && (flag == 1))
		my_put_nbr(nb);
	if ((c == 'c') && (flag == 1))
		my_putchar(nb);
	return (0);
}

int f2(char c, int *j, int flag, long nb)
{
	if (flag == 0)
		return (0);
	if ((c == 'b') || (c == 'u') || (c == 'o') || (c == 'd')) {
		my_putconvert(c, flag, nb);
		*j = *j + 1;
		return (0);
	}
	if ((c == 'x') || (c == 'X') || (c == 'p') || (c == 'i')) {
		my_putconvert(c, flag, nb);
		*j = *j + 1;
		return (0);
	}
	if (c == 'c') {
		my_putconvert(c, flag, nb);
		*j = *j + 1;
		return (0);
	}
	if (flag == 1)
		return (1);
	return (0);
}

int db(const char *format, int *j, int flag, ...)
{
	va_list my_params;

	va_start(my_params, flag);
	if ((format[*j] == 'l') && (format[*j + 1] == 'd') && (flag == 1)) {
		my_put_long(va_arg(my_params, long));
		*j = *j + 2;
		return (0);
	}
	if ((format[*j] == 'h') && (format[*j + 1] == 'd') && (flag == 1)) {
		my_put_nbr(va_arg(my_params, long));
		*j = *j + 2;
		return (0);
	}
	va_end(my_params);
	if (flag == 1)
		return (1);
	if (flag == 0)
		return (0);
	return (0);
}

int my_putflag3(char c, int *j, int flag, char *format)
{
	if ((c == 's') && (flag == 1)) {
		write(1, format, my_strlen(format));
		*j = *j + 1;
	}
	return (0);
}
