#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

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
    int philo_index;
    pthread_t *th;
    pthread_mutex_t *mutex;

} t_data;


int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void msg_error(int num);
int args_parsing(t_data **input,char **av);
void create_threads(t_data *input);

#endif