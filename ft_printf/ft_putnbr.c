/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:25:50 by fzutter           #+#    #+#             */
/*   Updated: 2024/02/06 11:10:25 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_zero(void)
{
	write(1, "0", 1);
	return (1);
}

int	nbrisnotzero(int n, char *nb, int i)
{
	while (n != 0)
	{
		nb[i++] = (n % 10) + '0';
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr(int n)
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
		return (nbr_zero());
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		temp++;
	}
	if (n != 0)
		i = nbrisnotzero(n, nb, i);
	temp = temp + i;
	while (i > 0)
		write(1, &nb[i-- - 1], 1);
	return (temp);
}
