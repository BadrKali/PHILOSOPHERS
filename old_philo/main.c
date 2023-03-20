/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:17:29 by bel-kala          #+#    #+#             */
/*   Updated: 2023/03/20 09:38:23 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void philo_is_eating(t_thread *philo)
{
    philo->input->state[philo->index] = 'E';
    //pthread_mutex_lock(&(philo->input->meal));
    //philo->input->philos_last_eat[philo->index] = get_time_stamp(philo);
    //pthread_mutex_unlock(&(philo->input->meal));
    printf("%d %d is eating\n",get_time_stamp(philo),philo->index);
    philo->feed_times++;
    //philo->input->philos_last_eat[philo->index] = get_time_stamp(philo);
    usleep(philo->input->time_to_eat * 1000);
    philo->input->philos_last_eat[philo->index] = get_time_stamp(philo);
    // pthread_mutex_lock(&(philo->input->meal));
    // philo->input->philos_last_eat[philo->index] = get_time_stamp(philo);
    // pthread_mutex_unlock(&(philo->input->meal));
    //printf("last eat : %d\n",philo->input->philos_last_eat[philo->index]);
}

void philo_is_sleeping(t_thread *philo)
{
    philo->input->state[philo->index] = 'S';
    printf("%d %d is sleeping\n",get_time_stamp(philo),philo->index);
    usleep(philo->input->time_to_sleep * 1000);
}

void philo_is_thinking(t_thread *philo)
{
    philo->input->state[philo->index] = 'T';
    printf("%d %d is thinking\n",get_time_stamp(philo),philo->index);
    //while(check_forks(philo) != 0)
    
}
void dinning_room(t_thread *philo)
{
    while(1)
    {
        pthread_mutex_lock(&(philo->input)->mutex[(philo->index + 1) % philo->input->number_of_philosophers]);
        printf("%d %d has taken a fork\n",get_time_stamp(philo),philo->index);
        pthread_mutex_lock(&(philo->input)->mutex[philo->index]);
        printf("%d %d has taken a fork\n",get_time_stamp(philo),philo->index);
        philo_is_eating(philo);
        pthread_mutex_unlock(&(philo->input)->mutex[philo->index]);
        pthread_mutex_unlock(&(philo->input)->mutex[(philo->index + 1) % philo->input->number_of_philosophers]);
        philo_is_sleeping(philo);
        philo_is_thinking(philo);
    }
}

void the_monitore(t_data *input)
{
    int i;
    int time;
    
    i = 0;
    time  = 0;
    while(1)
    {
        time = get_time_stamp_data(input) - input->philos_last_eat[i];
        //printf("philo %d and time %d\n",i,input->philos_last_eat[i]);
        //printf("%d\n",input->philos_last_eat[i]);
        if(time > input->time_to_die && input->state[i] != 'E')
        {
            //printf("state %c \n",input->state[i]);
            //printf("time : %d\n",input->philos_last_eat[i]);
            //printf("when died %d \n",time);
            printf("%d %d philo died bro\n",get_time_stamp_data(input),i);
            exit(1);
        }
        i++;
        if(i == 4)
            i = 0;
    }
}

void *wait_room(void *args)
{
    t_thread *philo = (t_thread *)args;
    
    if(philo->index % 2 != 0)
        dinning_room(philo);
    if(philo->index % 2 == 0)
    {
        usleep(1000);
        dinning_room(philo);
    }
    return(args);
}


int main(int ac ,char **av)
{
    t_data *input;
    t_thread *threads;

    if(ac != 5)
        msg_error(ARGS_ERROR);
    if(args_parsing(&input,&threads,av) != 0)
        msg_error(ARGS_ERROR);
    create_threads(threads);
    return(0);
}