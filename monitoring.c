/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:56:13 by bel-kala          #+#    #+#             */
/*   Updated: 2023/06/11 10:17:31 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

char	*the_master_monitore(t_thread *philo)
{
	int	i;
	int	time;
	int	count;

	count = 0;
	i = 0;
	while (1)
	{
		time = ft_check((philo + i), 1);
		count = count + ft_check((philo + i), 2);
		if (count == ((philo + i)->input->philo_num))
		{
			pthread_mutex_lock(&(philo->input)->print);
			return (NULL);
		}
		if (time >= philo->input->time_to_die)
			break ;
		i++;
		if (i == philo->input->philo_num)
			i = 0;
		usleep(1500);
	}
	pthread_mutex_lock(&(philo->input)->print);
	printf("%d %d is dead\n", get_time_stamp(philo), (philo + i)->index + 1);
	return (NULL);
}

char	*the_monitore(t_thread *philo)
{
	int	i;
	int	time;

	if (philo->input->meals_num != -1)
		return (the_master_monitore(philo));
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&((philo + i)->mutex_check));
		time = get_time_stamp(philo) - (philo + i)->lmeal_time;
		pthread_mutex_unlock(&((philo + i)->mutex_check));
		if (time >= philo->input->time_to_die)
		{
			pthread_mutex_lock(&(philo->input)->print);
			printf("%d %d is dead\n", get_time_stamp(philo),
				(philo + i)->index + 1);
			return (NULL);
		}
		i++;
		if (i == philo->input->philo_num)
			i = 0;
		usleep(1500);
	}
}
