/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:17:20 by bbastos-          #+#    #+#             */
/*   Updated: 2025/11/17 11:51:37 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printhex(unsigned long int nb, int caseflag)
{
	int			len;
	const char	*hex;

	hex = (caseflag == 1) ? "0123456789ABCDEF" : "0123456789abcdef"; // caseflag == 1 → maiúsculas, 0 → minúsculas. 
	len = 0;
	if (nb >= 16)
		len += ft_printhex(nb / 16, caseflag);
	len += ft_putchar_pf(hex[nb % 16]);
	return (len);
}

#include <stdio.h>
int	main(void)
{
	int num = 255;

	printf("\nreturn --> %d\n",ft_printhex(num, 1));
	printf("\nreturn --> %d\n",ft_printhex(num, 0));
}
