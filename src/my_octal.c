/*
** EPITECH PROJECT, 2017
** octal.c
** File description:
** Function that converts an integer in octal base
*/

#include <stdlib.h>
#include "include.h"

char *octal(int nb)
{
	char *result;
	int i = 0;
	int modulo = 0;

	result = malloc(sizeof(char) * 100);
	while (nb > 0) {
		modulo = nb % 8;
		result[i] = modulo + 48;
		if (nb < 8)
			nb = 0;
		nb = nb / 8;
		i = i + 1;
	}
	result[i] = '\0';
	result = my_revstr(result);
	return (result);
}
