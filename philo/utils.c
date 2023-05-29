/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:55:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/29 13:33:29 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	ft_printenv(t_env *env)
{
	printf("number_of_philosophers: %d\n", env->n_philo);
	printf("time_to_die: %d\n", env->time_die);
	printf("time_to_eat: %d\n", env->time_eat);
	printf("time_to_sleep: %d\n", env->time_sleep);
	printf("opt_n_meals_philo: %d\n", env->n_meals_opt);
}