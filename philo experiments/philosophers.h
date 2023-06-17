/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:04 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 11:51:30 by sbenes           ###   ########.fr       */
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

/* Definitions for colored messages */
# define EATING 	"\033[32mis eating   🍝\033[0m"
# define SLEEPING	"\033[36mis sleeping 💤\033[0m"
# define THINKING 	"\033[35mis thinking 🧠\033[0m"
# define DIED 		"\033[31mdied    🪦\033[0m"
# define FORK		"\033[33mhas taken a fork 🍴\033[0m"

/* Struct with argument values - setting the environment */
struct	s_env;

typedef struct s_philo
{
	struct s_env	*env;
	pthread_t		t1;
	int				id;
	int				meals_eaten;
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
	uint64_t		simulation_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_env;

/* init.c */
int			ft_init(t_env *env);
void		ft_init_philos(t_env *env);
int			ft_init_forks(t_env *env);
int			ft_init_arrays(t_env *env);

/* error.c */
char		*ft_truephilo(void);
int			ft_error(int errorcode, char *message, t_env *env);

/* utils.c - helper functions */
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
void		ft_printenv(t_env *env);

/* utils_time.c - time measure utility functions*/
uint64_t	ft_gettime(void);
int			ft_usleep(uint64_t time);

/* args.c */
void		ft_cleaninit(t_env *env);
int			ft_arguments(int ac, char **av, t_env *env);

/* init.c */
int			ft_init(t_env *env);
void		ft_init_philos(t_env *env);
int			ft_init_forks(t_env *env);
int			ft_init_arrays(t_env *env);

/* main.c*/
int			ft_onephilo(t_env *env);
void		ft_exit(t_env *env);
void		ft_sweep_env(t_env*env);

/* actions.c */
void		ft_eat(t_philo *philo);
void		ft_forks_up(t_philo *philo);
void		ft_forks_down(t_philo *philo);
void		ft_message(char *str, t_philo *philo);

/* routine.c */
int			ft_thread_init(t_env *env);
void		*ft_routine(void *philo_pointer);
void		*ft_supervisor(void *philo_pointer);
void		*ft_monitor(void *env_pointer);

#endif