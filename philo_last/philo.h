/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:40:56 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/20 10:29:58 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/time.h>

#define ARGS_ERROR 1
#define THREADS_ERROR 2

typedef struct s_data 
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    pthread_mutex_t *mutex;
    pthread_t *th;
    struct timeval start;
    struct timeval end;
    
}t_data;

typedef struct s_thread
{
    int index;
    int feed_times;
    t_data *input;
    
} t_thread;


int args_parsing(t_data **inputs,t_thread **threads,char **av);
int	ft_atoi(const char *str);
void create_threads(t_thread *threads);
void *wait_room(void *args);
void msg_error(int num);
#endif