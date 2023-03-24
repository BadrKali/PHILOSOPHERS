/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:40:21 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/23 12:25:18 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void philo_is(t_thread *philo,char *str)
{
    pthread_mutex_lock(&(philo->input->state));
    printf("%d %d %s\n",get_time_stamp(philo),philo->index,str);
    pthread_mutex_unlock(&(philo->input->state));
}

void philo_is_eating(t_thread *philo)
{
    pthread_mutex_lock(&(philo->input)->mutex[(philo->index + 1) % philo->input->number_of_philosophers]);
    philo_is(philo,"has taken a fork");
    pthread_mutex_lock(&(philo->input->mutex[philo->index]));
    philo_is(philo,"has taken a fork");
    philo_is(philo,"is eating");
    usleep(philo->input->time_to_eat * 1000);

}

void philo_is_sleeping(t_thread *philo)
{
    philo_is(philo,"is sleeping");
    usleep(philo->input->time_to_sleep * 1000);
}

void the_dinning_room(t_thread *philo)
{
    while(1)
    {
        philo_is_eating(philo);
        pthread_mutex_unlock(&(philo->input->mutex[philo->index]));
        pthread_mutex_unlock(&(philo->input)->mutex[(philo->index + 1) % philo->input->number_of_philosophers]);
        philo_is_sleeping(philo);
        philo_is(philo,"is thinking");
    }
}

void *wait_room(void *args)
{
    t_thread *philo = (t_thread *)args;
    
    if(philo->index % 2 == 0)
        the_dinning_room(philo);
    else if(philo->index % 2 != 0)
    {
        usleep(100);
        the_dinning_room(philo);
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
