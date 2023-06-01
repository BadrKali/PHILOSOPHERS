/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:38:38 by bel-kala          #+#    #+#             */
/*   Updated: 2023/05/31 12:34:52 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_check(t_thread *philo, int flag)
{
	int	time;
	int	count;

	count = 0;
	if (flag == 1)
	{
		pthread_mutex_lock(&((philo)->mutex_check));
		time = get_time_stamp(philo) - (philo)->lmeal_time;
		pthread_mutex_unlock(&((philo)->mutex_check));
		return (time);
	}
	if (flag == 2)
	{
		pthread_mutex_lock(&(philo)->mutex_count);
		if ((philo)->meals_count >= (philo)->input->meals_num
			&& philo->done == 0)
		{
			philo->done = 1;
			count = count + 1;
		}
		pthread_mutex_unlock(&(philo)->mutex_count);
		if (count == 1)
			return (1);
	}
	return (0);
}

int	get_time_stamp(t_thread *threads)
{
	int		sec;
	long	micro_sec;
	long	mili_sec;

	gettimeofday(&(threads->input)->end, NULL);
	sec = threads->input->end.tv_sec
		- threads->input->start.tv_sec;
	micro_sec = (sec * 1000000) + (threads->input->end.tv_usec
			- threads->input->start.tv_usec);
	mili_sec = micro_sec * 0.001;
	return (mili_sec);
}

int	mutex_init(t_data *input, t_thread *thread)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&input->print, NULL) != 0)
		return (1);
	while (i < input->philo_num)
	{
		pthread_mutex_init(&(thread + i)->mutex_check, NULL);
		pthread_mutex_init(&(thread + i)->mutex_count, NULL);
		if (pthread_mutex_init(&input->mutex[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	create_philos(t_thread *thread, t_data *input)
{
	int	i;

	i = 0;
	gettimeofday(&input->start, NULL);
	while (i < input->philo_num)
	{
		pthread_create(&thread->input->th[i], NULL, &dinning_room, &thread[i]);
		pthread_detach(input->th[i]);
		usleep(100);
		i++;
	}
	if (the_monitore(thread) == NULL)
		return ;
}

void	start_simulation(t_data *input, t_thread *threads)
{
	mutex_init(input, threads);
	create_philos(threads, input);
}
