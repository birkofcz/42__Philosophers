/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/24 13:04:19 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_environment	env;

	if (ac < 5 || ac > 6)
		return (ft_error(1, "Bad arguments"));
	ft_cleaninit(&env);
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	ft_printenv(&env);
	return (0);
}
