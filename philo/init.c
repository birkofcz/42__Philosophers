/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:03:17 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/07 13:49:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	printf("Hello from philo %d\n", philos->id);
	sleep(2);
	printf("Bye from philo %d\n", philos->id);
	return (NULL);

}

void	ft_initphilos(t_env *env)
{
	int		id;

	id = 0;
	env->philos = malloc(env->n_philo * sizeof(t_philo));
	if (!env->philos)
	{
		ft_error(1, "Failed to allocate memory");
		return ;
	}
	while (id < env->n_philo)
	{
		env->philos[id].id = id;
		pthread_create(&env->philos[id].t1, NULL, &ft_routine,
			&env->philos[id]);
		id++;
	}
	while (id != 0)
	{
		id--;
		pthread_join(env->philos[id].t1, NULL);
	}
	free(env->philos);
}
