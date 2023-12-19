/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:23:25 by fzutter           #+#    #+#             */
/*   Updated: 2023/12/19 16:32:49 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr(int n)
{
	char	nb[12];
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (n == -2147483648)
	{
		nb[i++] = '8';
		n = n / 10;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		temp++;
	}
	while (n != 0)
	{
		nb[i++] = (n % 10) + '0';
		n = n / 10;
	}
	temp = temp + i;
	while (i > 0)
		write(1, &nb[i-- - 1], 1);
	return (temp);
}

static	int	ft_putchar(char c)
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

static int	ft_puthex(int n)
{
	char	nb[100];
	int		i;
	int		count;
	int		temp;

	i = 0;
	count = 0;
	temp = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			temp = temp +48;
		else
			temp = temp +87;
		nb[i] = temp;
		n = n / 16;
		i++;
	}
	count = i;
	while (i > 0)
		write(1, &nb[i-- - 1], 1);
	return (count);
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
	if (type == 'x')
		count_arg = ft_puthex(va_arg(args, int));
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
}*/
