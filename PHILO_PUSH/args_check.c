#include"philo.h"


int args_parsing(t_data **input,char **av)
{
    int i ;

    i = 1;
    while(av[i] != NULL)
    {
        if(ft_atoi(av[i]) == 0)
            return(1);
        i++;
    }
    *input = malloc(sizeof(t_data) * ft_atoi(av[1]));
    i = 0;
    while(i < ft_atoi(av[1]))
    {
        ((*input)+i)->philo.thread_index = i;
        ((*input)+i)->number_of_philosophers = ft_atoi(av[1]);
        ((*input)+i)->time_to_die = ft_atoi(av[2]);
        ((*input)+i)->time_to_eat = ft_atoi(av[3]);
        ((*input)+i)->time_to_sleep = ft_atoi(av[4]);
        i++;
    }
    return(0);
}