#ifndef PHILO_H
#define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define ARGS_ERROR 1
#define THREADS_ERROR 2

typedef struct s_th
{
    int index;
    int last_feed;
    char state;
    int feed_times;
}t_th;

typedef struct s_data 
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    pthread_t *th;
    pthread_mutex_t *mutex;
    t_th *ph;
} t_data;

void msg_error(int num);
int	ft_atoi(const char *str);
int args_parsing(t_data **input,char **av);
void create_threads(t_data *input);

#endif