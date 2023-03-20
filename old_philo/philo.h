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
    int *forks_state;
    struct timeval start;
    struct timeval end;
    int *philos_last_eat;
    pthread_mutex_t meal;
    char *state;

} t_data;

typedef struct s_thread
{
    int index;
    int last_feed;
    int state;
    int feed_times;
    t_data *input;
} t_thread;



int args_parsing(t_data **input,t_thread **threads, char **av);
void msg_error(int num);
void create_threads(t_thread *threads);
void *wait_room(void *args);
int get_time_stamp(t_thread *threads);
int get_time_stamp_data(t_data *threads);
void the_monitore(t_data *input);

#endif