/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:25:22 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/25 11:04:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_truephilo(void)
{
	return ("Your arguments are fundamentally flawed in their "
		"logical structure or empirical grounding");
}

void	ft_cleaninit(t_environment *env)
{
	env->n_philo = 0;
	env->time_die = 0;
	env->time_eat = 0;
	env->time_sleep = 0;
	env->n_meals_opt = 0;
	env->n_forks = 0;
}

/* 
FT_ISDIGIT - edited function from my libft, checks the whole argument.
returns 1 if char is not digit.
 */
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

int	ft_arguments(int ac, char **av, t_environment *env)
{	
	if ((ft_isdigit(av[1])) == 0)
		env->n_philo = ft_atoi(av[1]);
	else
		return (ft_error(1, ft_truephilo()));
	if ((ft_isdigit(av[2])) == 0)
		env->time_die = ft_atoi(av[2]);
	else
		return (ft_error(1, ft_truephilo()));
	if ((ft_isdigit(av[3])) == 0)
		env->time_eat = ft_atoi(av[3]);
	else
		return (ft_error(1, ft_truephilo()));
	if ((ft_isdigit(av[4])) == 0)
		env->time_sleep = ft_atoi(av[4]);
	else
		return (ft_error(1, ft_truephilo()));
	if (ac == 6)
	{
		if ((ft_isdigit(av[5])) == 0)
			env->n_meals_opt = ft_atoi(av[5]);
		else
			return (ft_error(1, ft_truephilo()));
	}
	env->n_forks = env->n_philo;
	return (0);
}
