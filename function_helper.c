/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:54:37 by adardour          #+#    #+#             */
/*   Updated: 2022/11/09 17:10:20 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	numberofdigits(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		i += 1;
	else if (number < 0)
	{
		number *= -1;
		i += 1;
	}
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	numberofdigits_u(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		i += 1;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
}

int	printf_number_u(unsigned int number)
{
	int	count;

	count = 0;
	ft_putnbr_u(number);
	count += numberofdigits_u(number);
	return (count);
}
