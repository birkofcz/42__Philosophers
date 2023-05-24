/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:35:30 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/24 12:44:56 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_ERROR - prints error message specified, returns error code specified.
 */
int	ft_error(int errorcode, char *message)
{
	if (message)
		printf("%s.\n", message);
	return (errorcode);
}
