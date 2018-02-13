/*
** EPITECH PROJECT, 2017
** hexadecimal.c
** File description:
** Function that converts an integer into an hexadecimal base
*/

#include <stdlib.h>
#include "include.h"

char whichletter_low(int nb)
{
	if (nb == 10)
		return ('a');
	if (nb == 11)
		return ('b');
	if (nb == 12)
		return ('c');
	if (nb == 13)
		return ('d');
	if (nb == 14)
		return ('e');
	if (nb == 15)
		return ('f');
	return ('/');
}

char whichletter_up(int nb)
{
	if (nb == 10)
		return ('A');
	if (nb == 11)
		return ('B');
	if (nb == 12)
		return ('C');
	if (nb == 13)
		return ('D');
	if (nb == 14)
		return ('E');
	if (nb == 15)
		return ('F');
	return ('/');
}

char up_or_low(int modulo, char c)
{
	if ((c > 64) && (c < 91))
		return (whichletter_up(modulo));
	if ((c > 96) && (c < 123))
		return (whichletter_low(modulo));
	return ('/');
}

char *hexadecimal(long nb, char c)
{
	char *result;
	int i = 0;
	int modulo = 0;

	result = malloc(sizeof(char) * 100);
	while (nb > 0) {
		modulo = nb % 16;
		if (modulo < 10) {
			result[i] = modulo + 48;
		} else {
			result[i] = up_or_low(modulo, c);
		}
		if (nb < 16)
			nb = 0;
		nb = nb / 16;
		i = i + 1;
	}
	result[i] = '\0';
	result = my_revstr(result);
	return (result);
}
