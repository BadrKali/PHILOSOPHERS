/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:38:24 by bel-kala          #+#    #+#             */
/*   Updated: 2023/06/05 10:21:19 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	philo_is_eating(t_thread *philo)
{
	pthread_mutex_lock(&(philo->input)->print);
	printf("%d %d is eating\n", get_time_stamp(philo), philo->index + 1);
	pthread_mutex_unlock(&(philo->input)->print);
	pthread_mutex_lock(&philo->mutex_check);
	philo->lmeal_time = get_time_stamp(philo);
	pthread_mutex_unlock(&philo->mutex_check);
	my_usleep(philo->input->time_to_eat, philo);
	pthread_mutex_lock(&philo->mutex_count);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->mutex_count);
	pthread_mutex_unlock(&(philo->input)->mutex[(philo->index + 1)
		% philo->input->philo_num]);
	pthread_mutex_unlock(&(philo->input)->mutex[philo->index]);
}

void	fork_pick_up(t_thread *philo)
{
	pthread_mutex_lock(&(philo->input)->mutex[philo->index]);
	pthread_mutex_lock(&(philo->input)->print);
	printf("%d %d has taken a fork\n", get_time_stamp(philo), philo->index + 1);
	pthread_mutex_unlock(&(philo->input)->print);
	pthread_mutex_lock(&(philo->input)->mutex[(philo->index + 1)
		% philo->input->philo_num]);
	pthread_mutex_lock(&(philo->input)->print);
	printf("%d %d has taken a fork\n", get_time_stamp(philo), philo->index + 1);
	pthread_mutex_unlock(&(philo->input)->print);
}

void	*the_room(void *args)
{
	t_thread	*philo;

	philo = (t_thread *)args;
	while (1)
	{
		fork_pick_up(philo);
		philo_is_eating(philo);
		pthread_mutex_lock(&philo->mutex_count);
		if (philo->input->meals_num != -1
			&& philo->meals_count >= philo->input->meals_num)
		{
			pthread_mutex_unlock(&philo->mutex_count);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex_count);
		pthread_mutex_lock(&(philo->input)->print);
		printf("%d %d is sleeping\n", get_time_stamp(philo), philo->index + 1);
		pthread_mutex_unlock(&(philo->input)->print);
		my_usleep(philo->input->time_to_sleep, philo);
		pthread_mutex_lock(&philo->input->print);
		printf("%d %d is thinking\n", get_time_stamp(philo), philo->index + 1);
		pthread_mutex_unlock(&philo->input->print);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		*input;
	t_thread	*threads;

	input = NULL;
	threads = NULL;
	if (ac >= 5 && ac <= 6)
	{
		if (data_entry(&input, av) == 1)
			return (msg_error(ARGS_ERROR));
		if (init_philos(&input, &threads) == 1)
		{
			free(input);
			return (1);
		}
		start_simulation(input, threads);
		free_resources(input, threads);
	}
	else
		return (msg_error(ARGS_ERROR));
	return (0);
}
