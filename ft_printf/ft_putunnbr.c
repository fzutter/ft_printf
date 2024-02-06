/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:08:42 by fzutter           #+#    #+#             */
/*   Updated: 2024/02/06 11:10:29 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr(unsigned int n)
{
	char	nb[12];
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n != 0)
	{
		while (n != 0)
		{
		nb[i++] = (n % 10) + '0';
		n = n / 10;
		}
	}
	temp = temp + i;
	while (i > 0)
		write(1, &nb[i-- - 1], 1);
	return (temp);
}
