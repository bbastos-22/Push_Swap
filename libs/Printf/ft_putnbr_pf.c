/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:05 by bbastos-          #+#    #+#             */
/*   Updated: 2025/11/17 10:53:17 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_pf(int n)
{
	int			len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len += ft_putchar_pf('-');
	}
	if (nb > 9)
		len += ft_putnbr_pf(nb / 10);
	len += ft_putchar_pf((nb % 10) + '0');
	return (len);
}
