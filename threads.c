/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:27:09 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/11 13:27:12 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int create_threads_pool(pthread_t *th,int num)
{
    int i;
    int *a;

    i = 0;
    printf("i am num %d\n",num);
    while(i < num)
    {
        a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i],NULL,&routine,a) != 0)
            msg_error(THREADS_ERROR);
        i++;
    }
    i = 0;
    while(i < num)
    {
        if(pthread_join(th[i],NULL) != 0)
            msg_error(THREADS_ERROR);
        i++;
    }
    return(0);
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
    if(n == 0)
    {
        while(i < input->number_of_philosophers)
        {
            pthread_mutex_destroy(&input->mutex[i]);
            i++;
        }
    }
}


void create_threads(t_data *input)
{
    create_mutex_init_destroy(input,1);
    create_threads_pool(input->th,input->number_of_philosophers);
    create_mutex_init_destroy(input,0);
}