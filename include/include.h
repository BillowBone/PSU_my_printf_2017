/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

char *binary(int nb);
char whichletter_low(int nb);
char whichletter_up(int nb);
char up_or_low(int modulo, char c);
char *hexadecimal(long nb, char c);
char *octal(int nb);
int percent_flag(char c, int *j, int flag);
int my_putconvert(char c, int flag, long nb);
int f2(char c, int *j, int flag, long nb);
int db(const char *format, int *j, int flag, ...);
int my_putflag3(char c, int *j, int flag, char *format);
void octal3digits(char *str);
int how_much_flags(const char *format);
int my_putflag(char c, int *j, int flag, char *str);
int is_it_flag(char c, int *j, int flag);
int print_noflag(const char *format, int i, int *j, int flag);
int my_printf(const char *format, ...);
void my_putchar(char c);
void my_putstr(char *str);
int my_put_unsigned(unsigned int nb);
int my_put_long(long nb);
int my_put_nbr(int nb);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
int loop(char c, int *j, int flag, ...);
#endif /* MY_H_ */
