/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:09:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/23 15:35:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Whe using forks ([processes, we are duplicating all the variables - each process 
has its own set of variables. Threads are sharing the same memory space so they have 
the same variables. 

Here we can make example where we increment a variable in oe of the processess. 

Also there will be two different PIDs.
 */
int	main(void)
{
	int x = 2;
	int pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0)
		x++;
	printf("Hello from processes\n");
	printf("Process id: %d\n", getpid());
	sleep(2);
	printf("Value of x: %d\n", x);
	if (pid != 0)
		wait(NULL);
	return 0;
}