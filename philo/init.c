/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:25:22 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/24 11:38:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_ISDIGIT - edited function from my libft, checks the whole argument.
returns 1 if char is not digit.
 */

int	ft_atoi(const char *str)
{
	int	sign;
	int	output;

	sign = 1;
	output = 0;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output * sign);
}

static int	ft_isdigit(char *arg)
{
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (1);
		arg++;
	}
	return (0);
}

int	ft_error(int errorcode, char *message)
{
	if (message)
		printf("%s.\n", message);
	return (errorcode);
}

int	ft_arguments(int ac, char **av, t_environment *env)
{
	if (ac < 5 || ac > 6)
		return (ft_error(1, "Not enough / Too much arguments"));
	if ((ft_isdigit(av[1])) == 0)
		env->n_philo = ft_atoi(av[1]);
	else
		return (ft_error(1, "Bad argument"));
	if ((ft_isdigit(av[2])) == 0)
		env->time_die = ft_atoi(av[2]);
	else
		return (ft_error(1, "Bad argument"));
	if ((ft_isdigit(av[3])) == 0)
		env->time_eat = ft_atoi(av[3]);
	else
		return (ft_error(1, "Bad argument"));
	if ((ft_isdigit(av[4])) == 0)
		env->time_sleep = ft_atoi(av[4]);
	else
		return (ft_error(1, "Bad argument"));
	if (ac == 6)
	{
		if ((ft_isdigit(av[5])) == 0)
			env->n_meals_opt = ft_atoi(av[5]);
		else
			return (ft_error(1, "Bad argument"));
	}
	else
		env->n_meals_opt = 0;
	return (0);
}
