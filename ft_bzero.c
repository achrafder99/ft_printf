/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:36:11 by adardour          #+#    #+#             */
/*   Updated: 2022/11/07 18:43:10 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*pp;

	i = 0;
	pp = (char *)s;
	while (i < n)
	{
		pp[i] = 0;
		i++;
	}
}
