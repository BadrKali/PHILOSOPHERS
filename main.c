/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:27:20 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/11 13:27:22 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void *routine(void *args)
{
    int index = *(int *)args;
    printf("i am a cute thread %d\n",index);
    return(args);
}




int main(int ac, char **av)
{
    t_data *input;

    input = malloc(sizeof(t_data));
    if(ac != 5)
        msg_error(ARGS_ERROR);
    if(args_parsing(input,av) != 0)
        msg_error(ARGS_ERROR);
    input->th = malloc(sizeof(pthread_t) * input->number_of_philosophers);
    create_threads(input);

    return(0);
}