/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:21:05 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/09 12:27:22 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int i)
{
	long long	j;

	j = i;
	if (j >= 10)
		ft_putnbr(j / 10);
	ft_putchar((j % 10) + 48);
}

int	ft_atoi(char *str)
{
	int		i;
	int		ishara;
	int		res;

	i = 0;
	ishara = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ishara *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647 && ishara == 1)
			return (-1);
		if (res > 2147483647 && ishara == -1)
			return (0);
		i++;
	}
	return ((int)(res * ishara));
}
