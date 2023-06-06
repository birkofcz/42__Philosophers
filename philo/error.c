/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:35:30 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/06 16:41:47 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_TRUEPHILO - this just deserved a special error message, one from a true 
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
int	ft_error(int errorcode, char *message)
{
	if (message)
		printf("%s.\n", message);
	return (errorcode);
}
