CC = CC
SRC = main.c args_parsing.c generic_tools.c threads.c
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