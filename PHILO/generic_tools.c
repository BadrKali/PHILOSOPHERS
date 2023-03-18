#include"philo.h"

int	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str [i] == 32 || (str [i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str [i] == '-')
	sign = sign * (-1);
	if (str [i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str [i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}

void msg_error(int num)
{
    if(num == 1)
        write(2,"ARGS_ERROR\n",11);
	else if(num == 2)
		write(2,"THREADS_ERROR\n",14);
    exit(1);
}

void philo_start(t_data *input)
{
    int i;

    while(i < input->number_of_philosophers)
    {
        input->ph[i].index = i;
        input->ph[i].last_feed = 0;
        input->ph[i].state = 'T';
        input->ph[i].feed_times = 0;
        i++;
    }
    input->mutex = malloc(sizeof(pthread_mutex_t) * input->number_of_philosophers);
    
}

int args_parsing(t_data **input,char **av)
{
    int i;

    i = 0;
    while(av[i] != NULL)
    {
        if(ft_atoi(av[i]) == 1)
            return(1);
        i++;
    }
    *input = malloc(sizeof(t_data));
    (*input)->ph = malloc(sizeof(t_th) * ft_atoi(av[1]));
    (*input)->number_of_philosophers = ft_atoi(av[1]);
    (*input)->time_to_die = ft_atoi(av[2]);
    (*input)->time_to_eat = ft_atoi(av[3]);
    (*input)->time_to_sleep = ft_atoi(av[4]);
    philo_start(*input);
    i = 0;
    return(0);
}