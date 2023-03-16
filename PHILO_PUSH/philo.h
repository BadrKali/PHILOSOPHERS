#ifndef PHILO_H
#define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define ARGS_ERROR 1

typedef struct s_ph 
{
    int thread_index;

} t_ph;

typedef struct s_data 
{
    t_ph philo;
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    pthread_t *th;
    pthread_mutex_t *mutex;
} t_data;


void msg_error(int num);
int	ft_atoi(const char *str);
int args_parsing(t_data **input,char **av);

#endif