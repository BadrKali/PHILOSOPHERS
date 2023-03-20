/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:40:21 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/20 10:31:03 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void philo_is_sleeping(t_thread *philo)
{
    printf("%d %d is sleeping\n",get_time_stamp(philo),philo->index);
    usleep(philo->input->time_to_sleep * 1000);
}

void philo_is_thinking(t_thread *philo)
{
    printf("%d %d is thinking\n",get_time_stamp(philo),philo->index);
}

void philo_is_eating(t_thread *philo)
{
    printf("%d %d is eating\n",get_time_stamp(philo),philo->index);
    philo->feed_times++;
    usleep(philo->input->time_to_eat * 1000);
}
void pick_up_forks(t_thread *philo)
{
    pthread_mutex_lock(&(philo->input)->mutex[(philo->index + 1) % philo->input->number_of_philosophers]);
    printf("%d %d has taken a fork\n",get_time_stamp(philo),philo->index);
    pthread_mutex_lock(&(philo->input)->mutex[philo->index]);
    printf("%d %d has taken a fork\n",get_time_stamp(philo),philo->index);
}




void *wait_room(void *args)
{
    t_thread *philo = (t_thread *)args;

    if(philo->index % 2 != 0)
        dinning_room(philo);
    if(philo->index % 2 == 0)
    {
        usleep(1000);
        dinning_room(philo);
    }
    return(args);
}

int main(int ac,char **av)
{
    t_data *input;
    t_thread *threads;

    if(ac != 5)
        msg_error(ARGS_ERROR);
    if(args_parsing(&input,&threads,av) != 0)
        msg_error(ARGS_ERROR);
    create_threads(threads);
    return(0);
}