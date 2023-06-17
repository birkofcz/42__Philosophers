/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:35:30 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 13:58:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_TRUEPHILO - for argument check - a special error message, one from a true 
philosopher...
 */
char	*ft_truephilo(void)
{
	return ("\033[1;93;40mYour arguments are fundamentally flawed in their "
		"logical structure or empirical grounding\033[0m");
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
