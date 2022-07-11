/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:20:12 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/09 12:23:01 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/* kill function send a signal to a process specified by pid */
/* pid is a file containing the process ID number
 that is stored in a location of the file system 
	this allowing other programs to find out the (pid) of running script. */
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
