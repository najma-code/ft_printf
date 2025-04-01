/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonge <emonge@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:31:38 by emonge            #+#    #+#             */
/*   Updated: 2025/03/02 19:32:06 by emonge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifiers(char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*str == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*str == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if ((*str == 'd') || (*str == 'i'))
		count = ft_putnbr(va_arg(args, int));
	else if (*str == 'u')
		count = ft_putnbr_un(va_arg(args, unsigned int));
	else if (*str == 'x')
		count = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		count = ft_putchar('%');
	else
	{
		count = ft_putchar('%');
		count += ft_putchar(*str);
	}
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			count += ft_specifiers((char *)format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
