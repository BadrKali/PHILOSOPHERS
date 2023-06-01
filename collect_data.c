/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:48:07 by bel-kala          #+#    #+#             */
/*   Updated: 2023/05/31 12:27:48 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	my_usleep(size_t value, t_thread *philo)
{
	size_t	i;

	i = get_time_stamp(philo);
	while (1)
	{
		if (get_time_stamp(philo) - i >= value)
			break ;
		usleep(50);
	}
}

int	check_numeric(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) != 1)
			return (1);
		i++;
	}
	if (ft_atoi(arg) > 2147483647 || ft_atoi(arg) < -2147483648)
		return (1);
	if (ft_atoi(arg) <= 0)
		return (1);
	return (0);
}

int	check_data(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (check_numeric(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	data_entry(t_data **input, char **av)
{
	if (check_data(av) == 1)
		return (1);
	*input = malloc(sizeof(t_data));
	if (*input == NULL)
		return (1);
	(*input)->philo_num = ft_atoi(av[1]);
	(*input)->time_to_die = ft_atoi(av[2]);
	(*input)->time_to_eat = ft_atoi(av[3]);
	(*input)->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		(*input)->meals_num = ft_atoi(av[5]);
	if (av[5] == NULL)
		(*input)->meals_num = -1;
	return (0);
}

int	init_philos(t_data **input, t_thread **thread)
{
	int	i;

	i = 0;
	(*input)->th = malloc(sizeof(pthread_t) * (*input)->philo_num);
	if ((*input)->th == NULL)
		return (1);
	(*input)->mutex = malloc(sizeof(pthread_mutex_t) * (*input)->philo_num);
	if ((*input)->mutex == NULL)
		return (1);
	*thread = malloc(sizeof(t_thread) * (*input)->philo_num);
	if (*thread == NULL)
		return (1);
	while (i < (*input)->philo_num)
	{
		(*thread + i)->index = i;
		(*thread + i)->meals_count = 0;
		(*thread + i)->lmeal_time = 0;
		(*thread + i)->input = *input;
		(*thread + i)->done = 0;
		i++;
	}
	return (0);
}
