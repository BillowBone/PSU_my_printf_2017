/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Printf command-like
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include.h"

int my_putflag(char c, int *j, int flag, char *str)
{
	int i = 0;

	if ((c != 'S') || (flag != 1))
		return (0);
	while (str[i] != '\0') {
		if ((str[i] < 32) || (str[i] >= 127)) {
			my_putchar('\\');
			octal3digits(octal(str[i]));
			my_putstr(octal(str[i]));
		} else {
			my_putchar(str[i]);
		}
		i = i + 1;
	}
	*j = *j + 1;
	return (0);
}

int is_it_flag(char c, int *j, int flag)
{
	if ((c == '%') && (flag == 0)) {
		*j = *j + 1;
		return (1);
	} else {
		return (0);
	}
}

int print_noflag(const char *format, int i, int *j, int flag)
{
	if ((format[i] == '0') && (format[i + 1] == 'x')) {
		*j = *j + 2;
		return (*j);
	}
	if ((format[i] != '%') && (flag == 0)) {
		my_putchar(format[i]);
		*j = *j + 1;
	}
	return (*j);
}

int loop(char c, int *j, int flag, ...)
{
	va_list my_params;

	va_start(my_params, flag);
	if (c == 's' && flag == 1) {
		my_putstr(va_arg(my_params, char*));
		*j = *j + 1;
		return (0);
	}
	if (c == 'c' && flag == 1) {
		my_putchar(va_arg(my_params, int));
		*j = *j + 1;
		return (0);
	}
	if (c == 'S' && flag == 1)
		return (my_putflag(c, j, flag, va_arg(my_params, char*)));
	if (flag == 1)
		return (1);
	return (0);
}

int my_printf(const char* s, ...)
{
	int j[2] = {0, 0};
	va_list my_p;

	va_start(my_p, s);
	while (s[j[0]] != '\0') {
		j[1] = is_it_flag(s[j[0]], &j[0], j[1]);
		j[1] = percent_flag(s[j[0]], &j[0], j[1]);
		if (((s[j[0]] == 'l') || (s[j[0]] == 'h')) && (j[1] == 1))
			j[1] = db(s, &j[0], j[1], va_arg(my_p, long));
		if ((s[j[0]] == 's' || s[j[0]] == 'c' || s[j[0]] == 'S') && j[1] == 1)
			j[1] = loop(s[j[0]], &j[0], j[1], va_arg(my_p, int));
		if ((j[1] == 1) && ((s[j[0]] == 'b') || (s[j[0]] == 'u')
		|| (s[j[0]] == 'o') || (s[j[0]] == 'd') || (s[j[0]] == 'x')
		|| (s[j[0]] == 'X') || (s[j[0]] == 'p') || (s[j[0]] == 'i')))
			j[1] = f2(s[j[0]], &j[0], j[1], va_arg(my_p, long));
		if (j[1] == 0 && s[j[0]] != '\0')
			j[0] = print_noflag(s, j[0], &j[0], j[1]);
	}
	va_end(my_p);
	return (0);
}
