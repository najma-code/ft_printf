/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonge <emonge@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:33:15 by emonge            #+#    #+#             */
/*   Updated: 2025/03/14 18:33:18 by emonge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// FUNCTIONS
int		ft_printf(char const *format, ...);
int		ft_specifiers(char *str, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_un(unsigned int n);
int		ft_putnbr_hex(unsigned long n, char *base);

#endif
