/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:23:02 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/09 12:23:43 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((c >> i) & 1));
		i--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
		ft_putstr("invalid PID AND MESSAGE");
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
			send(pid, argv[2][i++]);
	}
	return (0);
}
