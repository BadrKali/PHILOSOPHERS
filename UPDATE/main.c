/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:09:21 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/13 11:10:43 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"




int main(int ac,char **av)
{
   t_data *input;

   if(ac != 5)
        msg_error(ARGS_ERROR);
    if(args_parsing(&input,av) != 0)
        msg_error(ARGS_ERROR);
    input->th = malloc(sizeof(pthread_t) * (input->number_of_philosophers));
    create_threads(input);
    return(0);
}