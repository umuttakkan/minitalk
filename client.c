/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:58:02 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/28 19:13:32 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h" 

void	signalcheck(int pid, char *data)
{
	int				i;
	int				j;
	unsigned char	bit;

	j = 0;
	while (data[j])
	{
		i = 7;
		bit = data[j];
		while (i >= 0)
		{
			if ((bit >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		j++;
	}	
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*data;

	data = argv[2];
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signalcheck(pid, data);
	}
}
