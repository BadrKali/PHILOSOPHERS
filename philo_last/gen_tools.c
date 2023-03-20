/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:43:52 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/20 10:28:45 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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