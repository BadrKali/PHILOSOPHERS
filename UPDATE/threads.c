/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:26 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/13 12:30:13 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

void *waiter(void *args)
{
    t_data *philo = (t_data *)args;
    printf("philo index %d\n",philo->number_of_philosophers);
    
     pthread_mutex_lock(&philo->mutex[philo->philo_index]);
     printf("philo %d take the fork\n",philo->philo_index);
     pthread_mutex_lock(&philo->mutex[(philo->philo_index + 1) % philo->number_of_philosophers]);
     printf("philo %d take the fork\n",philo->philo_index);
     printf("Philo %d is eating \n",philo->philo_index);
     //leep(2);
     pthread_mutex_unlock(&philo->mutex[philo->philo_index]);
     pthread_mutex_unlock(&philo->mutex[(philo->philo_index + 1) % philo->number_of_philosophers]);
     return(args);
    
}

void create_mutex_init_destroy(t_data *input,int n)
{
    int i = 0;

    if(n == 1)
    {
        input->mutex = malloc(sizeof(pthread_mutex_t) * input->number_of_philosophers);
        while(i < input->number_of_philosophers)
        {
            pthread_mutex_init(&input->mutex[i],NULL);
            i++;
        }
    }
    else if(n == 0)
    {
        while(i < input->number_of_philosophers)
        {
            pthread_mutex_destroy(&input->mutex[i]);
            i++;
        }
    }
}

void create_threads_pool(t_data *input)
{
    int i;

    i = 0;
    while(i < input->number_of_philosophers)
    {
        if(pthread_create(&input->th[i],NULL,&waiter,&input[i]) != 0)
            msg_error(THREADS_ERROR);
        i++;
    }
    i = 0;
    while(i < input->number_of_philosophers)
    {
        if(pthread_join(input->th[i],NULL) != 0)
            msg_error(THREADS_ERROR);
        i++;
    }
}

void create_threads(t_data *input)
{
    create_mutex_init_destroy(input,1);
    create_threads_pool(input);   
    create_mutex_init_destroy(input,0);
}