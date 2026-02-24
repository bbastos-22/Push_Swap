/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:30:40 by bbastos-          #+#    #+#             */
/*   Updated: 2026/01/04 16:15:50 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_format(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	if (spec == 's')
		return (ft_putstr_pf(va_arg(args, char*)));
	if (spec == 'p')
		return (ft_printptr(va_arg(args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	if (spec == 'u')
		return (ft_printdec(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_printhex((unsigned long int)va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_printhex((unsigned long int)va_arg(args, unsigned int), 1));
	if (spec == '%')
		return (ft_putchar_ft('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_argscondition(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
