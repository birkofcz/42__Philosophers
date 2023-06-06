/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:25:22 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/06 16:43:25 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_cleaninit(t_env *env)
{
	env->n_philo = 0;
	env->time_die = 0;
	env->time_eat = 0;
	env->time_sleep = 0;
	env->meals = -1;
	env->dead = 0;
	env->finished = 0;
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

int	ft_arguments(int ac, char **av, t_env *env)
{	
	ft_cleaninit(env);
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
			env->meals = ft_atoi(av[5]);
		else
			return (ft_error(1, ft_truephilo()));
	}
	return (0);
}

/* void	ft_init(t_env *env)
{
	
}
 */