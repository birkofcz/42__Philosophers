/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:42:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/23 16:27:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Theory experiments for threads */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


/* To illustrate the race condition, simulate the mailbox. X = 0, when threads increment it x++, we will get 2.
When we try to loop this may times, say 100 000, we start to get strange values. That is because of the overllaping values 
regstered in the memory, thread 2 might get older values than thread 1 etc.

It doesnt happen when we increment like 100 times, because that is usually done sooner than
the second thread is even created.

 */
int mails = 0;

void	*routine()
{
	for (int i = 0; i < 50000; i++)
	{
		mails++;
	}

		// read the value in mails
		// increment by one
		// wrute back to memory, write mails
}

int main(void) 
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	pthread_join(t1, NULL); //wait for the thread, join is ending the execution
	pthread_join(t2, NULL); //wait for the thread, join is ending the execution
	printf("Number of mails: %d\n", mails);
	return 0;
}