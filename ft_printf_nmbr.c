/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nmbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonge <emonge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:56:29 by emonge            #+#    #+#             */
/*   Updated: 2025/03/25 14:44:04 by emonge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_hexlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
	return (ft_intlen(n));
}

int	ft_putnbr_hex(unsigned long n, char *base)
{
	int		i;
	int		len;
	char	*str;

	len = ft_hexlen(n);
	i = len - 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	str[len] = '\0';
	if (n == 0)
		str[0] = base[0];
	while (n > 0)
	{
		str[i--] = base[n % 16];
		n /= 16;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	i;
	int				count;

	i = (unsigned long)ptr;
	count = 0;
	if (!ptr)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_hex(i, "0123456789abcdef");
	return (count);
}
