/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:46:35 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/20 10:43:21 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"


void philo_start(t_data *input,t_thread **threads)
{
    int i;

    i = 0;
    *threads = malloc(sizeof(t_thread) * input->number_of_philosophers);
    while(i < input->number_of_philosophers)
    {
        (*threads + i)->index = i + 1;
        (*threads + i)->feed_times = 0;
        (*threads + i)->input = input;
        i++;
    }
}

int args_parsing(t_data **input,t_thread **threads,char **av)
{
    int i;

    i = 1;
    while(av[i] != 0)
    {
        if(ft_atoi(av[1]) == 0)
            return(1);
        i++;
    }
    *input = malloc(sizeof(t_data));
    (*input)->th = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
    if((*input)->th == NULL)
        return(1); //make protection for those cases free and stuf
    (*input)->mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
    (*input)->number_of_philosophers = ft_atoi(av[1]);
    (*input)->time_to_die = ft_atoi(av[2]);
    (*input)->time_to_eat = ft_atoi(av[3]);
    (*input)->time_to_sleep = ft_atoi(av[4]);
    philo_start(*input,threads);
    return(0);
}