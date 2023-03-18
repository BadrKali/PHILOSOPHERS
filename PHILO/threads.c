#include"philo.h"

void create_mutex_init_destroy(t_data *input ,int n)
{
    
}

void create_threads(t_data *input)
{
    input->th = malloc(sizeof(pthread_t) * input->number_of_philosophers);
    create_mutex_init_destroy(input,0);
}