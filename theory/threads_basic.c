/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:42:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/21 16:58:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Theory experiments for threads */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/* This will run two threads at the same time - constructed so that we see two "Test"
messages at once, sleep(1), then we see two "Ending" messages at once == threads
runned sat the same time */
void	*routine()
{
	printf("Test from threads\n");
	sleep(1);
	printf("Ending thread\n");	
}

int main(void)
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	pthread_join(t1, NULL); //wait for the thread
	pthread_join(t1, NULL); //wait for the thread
	return 0;
}