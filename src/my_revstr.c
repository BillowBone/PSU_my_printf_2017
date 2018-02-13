/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** my_revstr.c
*/

#include "include.h"

char *my_revstr(char *str)
{
	int i = 0;
	int n = my_strlen(str) - 1;
	char str2[my_strlen(str)];

	while (i < (n + 1)) {
		str2[i] = str[n - i];
		i = i + 1;
	}
	i = 0;
	while (i < (n + 1)) {
		str[i] = str2[i];
		i = i + 1;
	}
	return (str);
}
