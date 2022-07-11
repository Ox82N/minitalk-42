/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:23:06 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/09 12:24:19 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
