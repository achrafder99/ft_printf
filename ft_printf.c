/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:35:06 by adardour          #+#    #+#             */
/*   Updated: 2022/11/09 17:16:18 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	printf_string(char *str)
{
	int	count;

	count = 0;
	if (str != NULL)
		count += ft_puts(str);
	else
		count += ft_puts("(null)");
	return (count);
}

static int	printf_number(va_list ap)
{
	int	count;
	int	number;

	count = 0;
	number = va_arg(ap, int);
	ft_putnbr(number);
	count = numberofdigits(number);
	return (count);
}

static int	ft_specifier(char *format, va_list ap)
{
	t_sp	specifier;

	specifier = (t_sp){.count = 0, .number = 0};
	if (*format == 'c')
		specifier.count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		specifier.count += printf_string(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		specifier.count += printf_number(ap);
	else if (*format == 'u')
		specifier.count += printf_number_u(va_arg(ap, unsigned int));
	else if (*format == 'X' || *format == 'x')
		specifier.count += putnbr_base_16(va_arg(ap, unsigned int), *format);
	else if (*format == 'p')
	{
		specifier.count += ft_puts("0x");
		specifier.count += (putnbr_base_16(va_arg(ap, unsigned long), *format));
	}
	else if (*format == '%')
		specifier.count = ft_putchar('%');
	else
		ft_putchar(*format);
	return (specifier.count);
}

int	ft_printf(const char *format, ...)
{
	t_sp	specifier;
	va_list	listofarg;

	specifier = (t_sp){.count = 0};
	va_start(listofarg, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			specifier.count += ft_putchar(*format);
			format++;
		}
		while (*format == '%' && *format != '\0')
		{
			format++;
			specifier.count += ft_specifier((char *)format, listofarg);
			if (*format == '%')
				break ;
		}
		if (*format == '\0')
			break ;
		format++;
	}
	va_end(listofarg);
	return (specifier.count);
}
