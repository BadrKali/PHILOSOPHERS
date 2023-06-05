/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:52:11 by bel-kala          #+#    #+#             */
/*   Updated: 2023/06/04 12:45:31 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define ARGS_ERROR 15

typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_num;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	pthread_t		*th;
	struct timeval	start;
	struct timeval	end;
}	t_data;

typedef struct s_thread
{
	int				index;
	int				lmeal_time;
	int				meals_count;
	t_data			*input;
	pthread_mutex_t	mutex_check;
	pthread_mutex_t	mutex_count;
	int				done;
}	t_thread;

int			msg_error(int num);
int			ft_isdigit(int c);
int			data_entry(t_data **input, char **av);
size_t		ft_strlen(const char *str);
long int	ft_atoi(char *str);
int			init_philos(t_data **input, t_thread **thread);
void		start_simulation(t_data *input, t_thread *threads);
int			get_time_stamp(t_thread *threads);
void		my_usleep(size_t value, t_thread *philo);
char		*the_monitore(t_thread *philo);
void		*the_room(void *args);
int			ft_check(t_thread *philo, int flag);
void		free_resources(t_data *input, t_thread *threads);
char		*the_master_monitore(t_thread *philo);

#endif