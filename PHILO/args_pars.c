/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:25:15 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/18 14:24:28 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"philo.h"


int get_time_stamp(t_thread *threads)
{
    long sec;
    long ms;
    int mlsec;

    gettimeofday(&(threads->input)->end,NULL);
    sec = threads->input->end.tv_sec - threads->input->start.tv_sec;
    ms = ((sec * 1000000) + threads->input->end.tv_usec) - threads->input->start.tv_usec;
    mlsec = ms * 0.001;
    return(mlsec);
}

// int get_time_stamp(t_data *input)
// {
// 	long sec;
// 	long ms;
// 	int mlsec;

// 	gettimeofday(&(input - input->philo.thread_index)->end,NULL);
// 	sec = (input - input->philo.thread_index)->end.tv_sec - 
// 	(input - input->philo.thread_index)->start.tv_sec;
// 	ms = ((sec * 1000000) + (input - input->philo.thread_index)->end.tv_usec) 
// 	- (input - input->philo.thread_index)->start.tv_usec;
// 	mlsec = ms * 0.001;
// 	return(mlsec);
// }

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

void philo_start(t_data *input, t_thread **threads)
{
    int i;

    i = 0;
    *threads = malloc(sizeof(t_thread) * input->number_of_philosophers);
    while(i < input->number_of_philosophers)
    {
        input->forks_state[i] = 0;
        (*threads + i)->index = i;
        (*threads + i)->feed_times = 0;
        (*threads + i)->last_feed = 0;
        (*threads + i)->state = 'T';
        (*threads + i)->input = input;
        i++;
    }
    
}

int args_parsing(t_data **input,t_thread **threads, char **av)
{
    int i;

    i = 1;
    while(av[i] != NULL)
    {
        if(ft_atoi(av[i]) == 0)
            return(1);
        i++;
    }
    *input = malloc(sizeof(t_data));
    (*input)->forks_state = malloc(sizeof(int) * ft_atoi(av[1]));
    (*input)->mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
    (*input)->th = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
    (*input)->number_of_philosophers = ft_atoi(av[1]);
    (*input)->time_to_die = ft_atoi(av[2]);
    (*input)->time_to_eat = ft_atoi(av[3]);
    (*input)->time_to_sleep = ft_atoi(av[4]);
    philo_start(*input,threads);
    return(0);
}