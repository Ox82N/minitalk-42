/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:20:16 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/09 12:24:30 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/* SIGUSR1 / SIGUSR2 : there are two signals. so that you can have two 
				different signals to communicate between processes.*/
void	handle(int signal)
{
	static int	i;
	static char	j;

	j = (j << 1) | (signal & 1);
	i++;
	if (i == 8)
	{
		ft_putchar(j);
		j = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
	return (0);
}
