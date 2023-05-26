/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/26 10:37:36 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_environment	env;

	if (ac < 5 || ac > 6)
		return (ft_error(1, ft_truephilo()));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (ft_error(1, ft_truephilo()));
	ft_cleaninit(&env);
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	ft_printenv(&env);
	printf("\n");
	ft_runtheshow(&env);
	return (0);
}
