#include"philo.h"


void msg_error(int num)
{
    if(num == 1)
        write(2,"ARGS_ERROR\n",11);
	else if(num == 2)
		write(2,"THREADS_ERROR\n",14);
    exit(1);
}

int	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str [i] == 32 || (str [i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str [i] == '-')
	sign = sign * (-1);
	if (str [i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str [i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}