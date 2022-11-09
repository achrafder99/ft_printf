/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:40:56 by adardour          #+#    #+#             */
/*   Updated: 2022/11/09 18:38:37 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_puts(char *str);
void		ft_putnbr(int n);
int			numberofdigits(int number);
void		ft_putnbr_u(unsigned int n);
typedef struct specifier
{
	int		count;
	int		number;
	int		temp;
	int		i;
	char	*temp_;
}			t_sp;
int			putnbr_base_16(uint64_t number, char specifier);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
int			numberofdigits_u(unsigned int number);
int			printf_number_u(unsigned int number);
int			printf_pecentage(char *pecentage);
#endif
