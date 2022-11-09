/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:44:50 by adardour          #+#    #+#             */
/*   Updated: 2022/11/09 14:39:42 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	puts_hexa(char *str, char specifier)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (specifier == 'X')
	{
		while (i < len)
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	while (len--)
	{
		write(1, &str[len], 1);
		i++;
	}
	free(str);
}

int	putnbr_base_16(uint64_t number, char specifier)
{
	t_sp	sp;

	sp = (t_sp){.temp = 0, .i = 0};
	sp.temp_ = (char *)ft_calloc(100, 1);
	if (sp.temp_ == NULL)
		return (0);
	if (number == 0)
	{
		free(sp.temp_);
		return (ft_putchar('0'));
	}
	while (number != 0)
	{
		sp.temp = number % 16;
		if (sp.temp < 10)
			sp.temp_[sp.i++] = sp.temp + 48;
		else
			sp.temp_[sp.i++] = sp.temp + 87;
		number = number / 16;
	}
	puts_hexa(sp.temp_, specifier);
	return (sp.i);
}
