/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:57:00 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/11 13:26:20 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
#define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define ARGS_ERROR 1
#define THREADS_ERROR 2

typedef struct s_data
{   
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    pthread_t *th;
    pthread_mutex_t *mutex;
} t_data;


void msg_error(int n);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int args_parsing(t_data *input,char **av);
void create_threads(t_data *input);
void *routine(void *args);

#endif