/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:04 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/12 10:50:31 by sbenes           ###   ########.fr       */
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
# include <stdint.h>
# include <sys/types.h>

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
	struct s_env	*env;
	pthread_t		t1;
	int				id;
	int				meals_eaten;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_env
{
	pthread_t		*tid;
	int				n_philo;
	int				meals_to_eat;
	int				dead;
	int				finished_eating;
	t_philo			*philos;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	uint64_t		time_born;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_env;


/* init.c */
int		ft_init(t_env *env);
void	ft_init_philos(t_env *env);
int		ft_init_forks(t_env *env);
int		ft_init_arrays(t_env *env);

/* error.c */
char	*ft_truephilo(void);
int		ft_error(int errorcode, char *message);

/* utils.c - helper functions */
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_printenv(t_env *env);

/* utils_time.c - time measure utility functions*/
uint64_t		ft_gettime(void);
int			ft_usleep(uint64_t time);

/* args.c */
void	ft_cleaninit(t_env *env);
int		ft_arguments(int ac, char **av, t_env *env);

/* init.c */
int		ft_init(t_env *env);
void	ft_init_philos(t_env *env);
int		ft_init_forks(t_env *env);
int		ft_init_arrays(t_env *env);

/* main.c*/
int		case_one(t_env *env);
void	ft_exit(t_env *env);
void	clear_env(t_env*env);


/* actions.c */
void	eat(t_philo *philo);
void	drop_forks(t_philo *philo);
void	take_forks(t_philo *philo);
void	messages(char *str, t_philo *philo);

/* routine.c */
int		thread_init(t_env *env);
void	*routine(void *philo_pointer);
void	*supervisor(void *philo_pointer);
void	*monitor(void *env_pointer);


#endif