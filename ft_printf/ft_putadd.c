/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:08:12 by fzutter           #+#    #+#             */
/*   Updated: 2024/02/06 11:10:22 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(void const *p)
{
	unsigned long	adr;
	char			*base;
	char			res[21];
	int				i;
	int				count;

	count = 2;
	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 20;
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	write(1, "0x", 2);
	while (i <= 20)
	{
		ft_putchar (res[i]);
		i++;
		count++;
	}
	return (count);
}
