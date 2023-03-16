#include"philo.h"


void msg_error(int num)
{
    if(num == 1)
        write(2,"ARGS_ERROR\n",11);
	if(num == 2)
		write(2,"THREADS_ERROR\n",14);
    exit(1);
}