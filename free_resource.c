/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:07:36 by bel-kala          #+#    #+#             */
/*   Updated: 2023/06/12 10:37:56 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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
	my_usleep(threads->input->time_to_eat, threads);
	destroy_mutex(threads);
	free(input->mutex);
	free(input->th);
	free(input);
	free(threads);
}
