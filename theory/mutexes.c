/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:42:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/26 14:40:28 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Theory experiments for threads */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


/* Mutexes:
That is the solution to the data race ilustrated in race_condition.c
MUTEX (mutual exeption) is the lock around the section of the code - simply said.
Locking and unlocking with a mutex will work to get the right result - it will
lock the resource to be used by one thread, so the other thread will not be able to use
it at the same time - til it is unlocked.
 */
int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	for (int i = 0; i < 50000; i++)
	{
		pthread_mutex_lock(&mutex);
		
		mails++;
		pthread_mutex_unlock(&mutex);
	}

		// read the value in mails
		// increment by one
		// wrute back to memory, write mails
}

int main(void) 
{
	pthread_t t1;
	pthread_t t2;
	
	pthread_mutex_init(&mutex, NULL);
	
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	pthread_join(t1, NULL); //wait for the thread, join is ending the execution
	pthread_join(t2, NULL); //wait for the thread, join is ending the execution

	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return 0;
}