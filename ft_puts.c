/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:55:40 by adardour          #+#    #+#             */
/*   Updated: 2022/11/07 18:44:19 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puts(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
