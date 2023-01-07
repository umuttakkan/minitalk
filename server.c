/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:58:05 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/28 19:11:39 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	bitstorage(int poolsignal)
{
	static unsigned char	x;
	static int				i;

	if (poolsignal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_printf("Server started with PID: %d\n ", getpid());
	signal (SIGUSR1, bitstorage);
	signal (SIGUSR2, bitstorage);
	while (1)
		pause();
	return (0);
}
