# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:36:23 by bel-kala          #+#    #+#              #
#    Updated: 2023/06/05 11:49:23 by bel-kala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = main.c threads.c utils.c collect_data.c free_resource.c monitoring.c
OBJ = $(SRC:.c=.o)
NAME = philo
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
PHILO = philo.h

all:$(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(PHILO) 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all