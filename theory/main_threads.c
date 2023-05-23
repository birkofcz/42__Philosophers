/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:09:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/23 15:43:42 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/* Processes can cobtain multiple threads - you can have multiple threads inside 
teh single process - when printind the process id here, it will be the same number 

Also, all threads can access all variables - common memory adresses. If we try to increment
x in only one of the threads, it will increment in the memory, so is will have same value
even when incremented only in one thread.
*/

int x = 2; // global variable to ilustrate

void *routine(void)
{
	printf("Hello from threads\n");
	printf("Process id: %d\n", getpid());
	x++;
	sleep(2);
	printf("Value of x: %d\n", x);
}

void *routine2(void)
{
	printf("Hello from threads\n");
	printf("Process id: %d\n", getpid());
	sleep(2);
	printf("Value of x: %d\n", x);
}

int main(void)
{
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
