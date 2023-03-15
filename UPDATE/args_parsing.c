/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:37:56 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/14 09:29:52 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

int check_if_numb(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(ft_isdigit(str[i]) != 1)
            return(1);
        i++;
    }
    return(0);
}

int args_parsing(t_data **input,char **av)
{
    int i;

    i = 1;
    while(av[i] != NULL)
    {
        if(check_if_numb(av[i]) != 0)
            return(1);
        i++;
    }
    *input = malloc(sizeof(t_data) * ft_atoi(av[1]));
    i = 0;
    while(i < ft_atoi(av[1]))
    {
        ((*input)+i)->philo_index = i;
        ((*input)+i)->number_of_philosophers = ft_atoi(av[1]);
        ((*input)+i)->time_to_die = ft_atoi(av[2]);
        ((*input)+i)->time_to_eat = ft_atoi(av[3]);
        ((*input)+i)->time_to_sleep = ft_atoi(av[4]);
        ((*input)+i)->eat_counter = 0;
        i++;
    }
    return(0);
}