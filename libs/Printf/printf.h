/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:02:40 by bbastos-          #+#    #+#             */
/*   Updated: 2025/11/17 12:25:16 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_putchar_pf(char c);
int	ft_putnbr_pf(int n);
int	ft_printdec(unsigned int nb);
int	ft_printhex(unsigned long int nb, int caseflag);
int	ft_printptr(void *ptr);

#endif
