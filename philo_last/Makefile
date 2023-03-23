# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 11:02:45 by bel-kala          #+#    #+#              #
#    Updated: 2023/03/23 10:29:18 by bel-kala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -pthread
SRC = main.c pars_args.c gen_tools.c threads.c
BONUS = 
OBJ = $(SRC:.c=.o)
NAME = philo
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PHILO = philo.h

all:$(NAME)
$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o : %.c $(PHILO)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all