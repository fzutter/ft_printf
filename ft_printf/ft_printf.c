/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:23:25 by fzutter           #+#    #+#             */
/*   Updated: 2024/02/06 11:10:20 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static	int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_puthex(int n, char type)
{
	char			*base;
	int				i;
	unsigned int	num;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int) n;
	if (num > 16 - 1)
		i += ft_puthex(num / 16, type);
	i += ft_putchar(*(base + (num % 16)));
	return (i);
}

static	int	ft_arg_type(char type, va_list args)
{
	int	count_arg;

	count_arg = 0;
	if (type == '%')
	{
		write(1, "%", 1);
		count_arg++;
	}
	if (type == 'd' || type == 'i')
		count_arg = ft_putnbr(va_arg(args, int));
	if (type == 'c')
		count_arg = ft_putchar(va_arg(args, int));
	if (type == 's')
		count_arg = ft_putstr(va_arg(args, char *));
	if (type == 'x' || type == 'X')
		count_arg = ft_puthex(va_arg(args, int), type);
	if (type == 'u')
		count_arg = ft_putunnbr(va_arg(args, unsigned int));
	if (type == 'p')
		count_arg = ft_putadd(va_arg(args, void const *));
	return (count_arg);
}

int	ft_printf(const char *format, ...)
{
	int			count_c;
	int			i;
	va_list		args;

	va_start (args, format);
	count_c = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count_c = count_c + ft_arg_type(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			count_c++;
		}
	}
	va_end (args);
	return (count_c);
}
/*
int	main(void)
{
	printf("Test 1 string %s\n", "ok c'est bon");
	ft_printf("Test 1 string %s\n", "ok c'est bon");
	printf("\n");
	printf("Test 2 int %i\n", '5264');
	ft_printf("Test 2 int %i\n", '5264');
	printf("\n");
	printf("Test 3 pourcent %%\n", '%');
	ft_printf("Test 3 pourcent %%\n", '%');
	printf("\n");
	printf("Test 4 unsigned int %u\n", "5264");
	ft_printf("Test 4 unsigned int %u\n", "5264");
	printf("\n");
	printf("Test 5 char %c\n", 'r');
	ft_printf("Test 5 char %c\n", 'r');
	printf("\n");
	printf("Test 6 pointer %p\n", "rere");
	ft_printf("Test 6 pointer %p\n", "rere");
	printf("\n");
	printf("Test 7 pointer %x\n", '-521');
	ft_printf("Test 7 pointer %x\n", '-521');
	printf("\n");
	printf("Test 8 pointer %X\n", '3248');
	ft_printf("Test 8 pointer %X\n", '3248');
}*/
