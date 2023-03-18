#include"philo.h"

void *wait_room(void *args)
{
    t_th *philo = (t_th *)args;
    printf("hello %d\n",philo->index);
    return(args);
}


void create_mutex_init_destroy(t_data *input, int n)
{
    int i;

    i = 0;
    if (n == 0)
    {
        input->mutex = malloc(sizeof(pthread_mutex_t) * input->number_of_philosophers);
        while(i < input->number_of_philosophers)
        {
            pthread_mutex_init(&input->mutex[i],NULL);
            i++;
        }
    }
    else if(n == 1)
    {
        while(i < input->number_of_philosophers)
        {
            pthread_mutex_destroy(&input->mutex[i]);
            i++;
        }
    }
}

void create_threads_pool(t_data *input,int n)
{
    int i;

    i = 0;
    if(n == 0)
    {
        while(i < input->number_of_philosophers)
        {
            if(pthread_create(&input->th[i],NULL,&wait_room,&input) != 0)
                msg_error(THREADS_ERROR);
            i++;
        }
    }
    else if(n == 1)
    {
        while(i < input->number_of_philosophers)
        {
            if(pthread_join(input->th[i],NULL) != 0)
                msg_error(THREADS_ERROR);
            i++;
        }
    }
}

void create_threads(t_data *input)
{
    input->th = malloc(sizeof(pthread_t) * input->number_of_philosophers);
    create_mutex_init_destroy(input,0);
    create_threads_pool(input,0);
}