/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:04 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/06 16:42:23 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/* Struct with argument values - setting the environment */

/* typedef struct s_environment
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		n_meals_opt;
}	t_env; */

struct	s_env;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	int				time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_env
{
	pthread_t		*tid;
	int				n_philo;
	int				meals;
	int				dead;
	int				finished;
	t_philo			*philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_born;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_env;


/* init.c */
int					ft_arguments(int ac, char **av, t_env *env);
void				ft_cleaninit(t_env *env);

/* error.c */
char				*ft_truephilo(void);
int					ft_error(int errorcode, char *message);

/* utils.c - helper functions */
int					ft_atoi(const char *str);
void				ft_printenv(t_env *env);

/* utils_time.c - time measure utility functions*/


/* main.c*/

/* actions.c */

/* routine.c */


#endif