/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:26 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/15 14:46:44 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

int fork_state[6] = {0,0,0,0,0,0};


void sleep_phase(t_data *philo)
{
    printf("philo %d is sleeping\n",philo->philo_index);
    sleep(3);
}

void eating_phase(t_data *philo)
{
    printf("philo %d is eating\n",philo->philo_index);
    sleep(2);
    pthread_mutex_unlock(&(philo - philo->philo_index)->mutex[philo->philo_index]);
    fork_state[philo->philo_index] = 0;
    pthread_mutex_unlock(&(philo - philo->philo_index)->mutex[(philo->philo_index + 1) % philo->number_of_philosophers]);
    fork_state[(philo->philo_index + 1) % philo->number_of_philosophers] = 0;
    sleep_phase(philo);
}

void pick_a_fork(t_data *philo)
{
    if(fork_state[philo->philo_index] == 0)
    {
        pthread_mutex_lock(&(philo - philo->philo_index)->mutex[philo->philo_index]);
        fork_state[philo->philo_index] = 1;
    }
        
    if(fork_state[philo->philo_index] == 0)
    {
        pthread_mutex_lock(&(philo - philo->philo_index)->mutex[(philo->philo_index + 1) % philo->number_of_philosophers]);
        fork_state[(philo->philo_index + 1) % philo->number_of_philosophers] = 1;
    }
    eating_phase(philo);
}

int check_fork(t_data *philo)
{
    if(fork_state[philo->philo_index] == 0 && fork_state[(philo->philo_index + 1) % philo->number_of_philosophers] == 0)
        return(0);
    return(1);
}

void keep_thinking(t_data *philo)
{
    printf("philo %d is thinking\n",philo->philo_index);
    while(check_fork(philo) != 0)
    {
        
    }
    pick_a_fork(philo);
}

void *the_wait_room(void *args)
{
    t_data *philo = (t_data *)args;
    while(1)
    {
    if(philo->philo_index % 2 == 0)
        pick_a_fork(philo);
    if(philo->philo_index % 2 != 0)
        keep_thinking(philo);
    }
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
        if(pthread_create(&input->th[i],NULL,&the_wait_room,&input[i]) != 0)
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