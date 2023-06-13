/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:35:30 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/13 10:34:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_TRUEPHILO - for argument check - a special error message, one from a true 
philosopher...
 */
char	*ft_truephilo(void)
{
	return ("Your arguments are fundamentally flawed in their "
		"logical structure or empirical grounding");
}

/* 
FT_ERROR - prints error message specified, returns error code specified.
 */
int	ft_error(int errorcode, char *message, t_env *env)
{
	if (message)
		printf("%s.\n", message);
	return (ft_exit(env), errorcode);
}
