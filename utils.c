/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:38:51 by bel-kala          #+#    #+#             */
/*   Updated: 2023/06/04 12:48:15 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long int	ft_atoi(char *str)
{
	size_t	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str [i] == '-')
		sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str [i] != '\0')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

int	msg_error(int num)
{
	if (num == 15)
		ft_putstr_fd("ARGS ERROR\n", 2);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}
