/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:55:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/24 11:02:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_printenv(t_environment *env)
{
	printf("number_of_philosophers: %d\n", env->n_philo);
	printf("time_to_die: %d\n", env->time_die);
	printf("time_to_eat: %d\n", env->time_eat);
	printf("time_to_sleep: %d\n", env->time_sleep);
	printf("opt_n_meals_philo: %d\n", env->n_meals_opt);
}