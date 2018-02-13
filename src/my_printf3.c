/*
** EPITECH PROJECT, 2017
** my_printf3.c
** File description:
** Part 3 of the my_printf function code
*/

#include "include.h"

void octal3digits(char *str)
{
	int len = 0;

	len = my_strlen(str);
	if (len == 2) {
		my_putchar('0');
	}
	if (len == 1) {
		my_putchar('0');
		my_putchar('0');
	}
}
