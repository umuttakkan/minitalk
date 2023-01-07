/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:55:54 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/28 13:49:16 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_format(va_list *args, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((*args), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((*args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((*args), char *)));
	else
		return (ft_string("%"));
}

static bool	ft_flag_catch(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c'
			|| str[i + 1] == 'd' || str[i + 1] == 's'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (ft_flag_catch(str, i))
			len += ft_format(&args, str[++i]);
		else
		{
			if (str[0] == '%')
				return (0);
			len += write(1, &str[i], 1);
		}
	}
	va_end(args);
	return (len);
}
