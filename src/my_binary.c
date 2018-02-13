/*
** EPITECH PROJECT, 2017
** binary.c
** File description:
** Function that converts an unsigned char in base 2
*/

#include <stdlib.h>
#include "include.h"

char *binary(int nb)
{
	char *result;
	int i = 0;
	int modulo = 0;

	result = malloc(sizeof(char) * 100);
	while (nb > 0) {
		modulo = nb % 2;
		if (modulo == 0) {
			result[i] = '0';
		} else {
			result[i] = '1';
		}
		if (nb == 1)
			nb = 0;
		nb = nb / 2;
		i = i + 1;
	}
	result[i] = '\0';
	result = my_revstr(result);
	return (result);
}
