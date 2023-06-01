/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:07:36 by bel-kala          #+#    #+#             */
/*   Updated: 2023/05/31 12:35:44 by bel-kala         ###   ########.fr       */
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

void	lock_mutexes(t_thread *threads)
{
	int	i;

	i = 0;
	while (i < threads->input->philo_num)
	{
		pthread_mutex_lock(&((threads + i)->mutex_check));
		pthread_mutex_lock(&((threads + i)->mutex_count));
		i++;
	}
}

void	destroy_mutex(t_thread *threads)
{
	int	i;

	i = 0;
	while (i < threads->input->philo_num)
	{
		pthread_mutex_destroy(&(threads + i)->mutex_check);
		pthread_mutex_destroy(&(threads + i)->mutex_count);
		pthread_mutex_destroy(&threads->input->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&threads->input->print);
}

void	free_resources(t_data *input, t_thread *threads)
{
	lock_mutexes(threads);
	destroy_mutex(threads);
	free(input);
	free(threads);
}
