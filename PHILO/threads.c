/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:45:24 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/18 13:18:04 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"


void create_mutex_init_destroy(t_thread *threads, int n)
{
    int i;

    i = 0;
    if (n == 0)
    {
        while(i < threads->input->number_of_philosophers)
        {
            pthread_mutex_init(&threads->input->mutex[i],NULL);
            i++;
        }
    }
    else if(n == 1)
    {
        while(i < threads->input->number_of_philosophers)
        {
            pthread_mutex_destroy(&threads->input->mutex[i]);
            i++;
        }
    }
}

void create_threads_pool(t_thread *threads,int n)
{
    int i;

    i = 0;
    if(n == 0)
    {
        gettimeofday(&(threads->input)->start,NULL);
        while(i < threads->input->number_of_philosophers)
        {
            if(pthread_create(&threads->input->th[i],NULL,&wait_room,&threads[i]) != 0)
                msg_error(THREADS_ERROR);
            i++;
        }
    }
    else if(n == 1)
    {
        while(i < threads->input->number_of_philosophers)
        {
            if(pthread_join(threads->input->th[i],NULL) != 0)
                msg_error(THREADS_ERROR);
            i++;
        }
    }
}

void create_threads(t_thread *threads)
{
    create_mutex_init_destroy(threads,0);
    create_threads_pool(threads,0);
    create_threads_pool(threads,1);
    create_mutex_init_destroy(threads,1);   
}


