/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printprt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:15:45 by bbastos-          #+#    #+#             */
/*   Updated: 2025/11/17 12:30:24 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printptr(void *ptr)
{
	int	result;

	result = 0;
	if (ptr == NULL)
		return (ft_putstr_pf("(nil)"));
	else
		result += ft_putstr_pf("0x");
	result += ft_printhex((unsigned long int) ptr, 0);
	return (result);
}
