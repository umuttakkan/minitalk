/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ultis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:00:35 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/28 13:45:27 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int(int a)
{
	int	len;

	len = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		len += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		len += ft_int(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (len + 1);
}

int	ft_point(unsigned long a, int cont)
{
	int	len;

	len = 0;
	if (cont == 1)
	{
		len += write(1, "0x", 2);
		cont = 0;
	}
	if (a >= 16)
		len += ft_point(a / 16, cont);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_hex(unsigned int a, char c)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (len + 1);
}

int	ft_unsigned(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_unsigned(a / 10);
	write(1, &"0123456789"[a & 10], 1);
	return (len + 1);
}
