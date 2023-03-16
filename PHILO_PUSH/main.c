#include"philo.h"


int main(int ac, char **av)
{
    t_data *input;

    if(ac != 5)
        msg_error(ARGS_ERROR);
    if(args_parsing(&input,av) != 0)
        msg_error(ARGS_ERROR);
    
    return(0);
}