/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:14:25 by fzutter           #+#    #+#             */
/*   Updated: 2024/02/06 11:10:35 by fzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putunnbr(unsigned int n);
int		ft_putadd(void const *p);
int		ft_putchar(char c);

#endif
