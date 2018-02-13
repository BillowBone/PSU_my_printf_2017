/*
** EPITECH PROJECT, 2017
** my_put_unsigned.c
** File description:
** my_put_nbr function-like but this one prints only unsigneds integers
*/

#include "include.h"

int my_put_unsigned(unsigned int nb)
{
	if (nb <= 9) {
		my_putchar(nb + '0');
	}
	if (nb > 9) {
		my_put_unsigned(nb / 10);
		my_put_unsigned(nb % 10);
	}
	return (0);
}
