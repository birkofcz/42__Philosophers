/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/07 13:44:53 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* int	ft_one_philo(t_env *env)
{
	env->time_born = get_time();
	if (pthread_create(&env->tid[0], NULL, &routine, &env->philos[0]))
		return (error(TH_ERR, data));
	pthread_detach(env->tid[0]);
	while (env->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}
 */

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 5 || ac > 6)
		return (ft_error(1, ft_truephilo()));
	//put this check into some init. Add conditon for > 200 philos.
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (ft_error(1, ft_truephilo()));
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	ft_printenv(&env);
	ft_initphilos(&env);
	//init everything and run the show/..
	return (0);
}
