/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:11:01 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/11 13:19:58 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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

int args_parsing(t_data *input,char **av)
{
    int i;

    i = 1;
    while(av[i] != NULL)
    {
        if(check_if_numb(av[i]) != 0)
            return(1);
        i++;
    }
    input->number_of_philosophers = ft_atoi(av[1]);
    input->time_to_die = ft_atoi(av[2]);
    input->time_to_eat = ft_atoi(av[3]);
    input->time_to_sleep = ft_atoi(av[4]);
    return(0);
}