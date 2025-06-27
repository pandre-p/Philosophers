/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philol.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:18:36 by ppassos           #+#    #+#             */
/*   Updated: 2025/05/27 15:09:05 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOL_H
# define PHILOL_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

# define INT_MAX 2147483647

typedef struct s_table	t_table;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef enum e_status
{
	EATING,
	SPLEEPING,
	THINKING,
	TAKE_F_FORK,
	TAKE_S_FORK,
	DIED,
}	t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}	t_philo;

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_simulation;
	bool		end_simulation;
	bool		all_threads_ready;
	long		t_running_nbr;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
};

long	ft_atol(const char *str);
void	parsing_input(t_table	*table, char **av);
void	data_init(t_table *table);
void	*safe_malloc(size_t bytes);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	error_exit(const char	*error);
void	safe_thread(pthread_t *thread,
			void *(*foo)(void *), void *data, t_opcode opcode);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_bool(t_mtx *mute, bool *dest, bool value);
long	get_long(t_mtx *mutex, long *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	gettime(t_time time_code);
bool	s_finish(t_table *table);
void	precise_usleep(long usec, t_table *table);
void	start_dinner(t_table *table);
void	write_status(t_philo_status status, t_philo *philo);
bool	all_threads_running(t_mtx *mutex, long *threads, long p_nbr);
void	increase_long(t_mtx *mutex, long *value);
void	*monitor_dinner(void *data);
void	f_free(t_table	*table);
void	think(t_philo *philo, bool pre_s);
void	the_synchronize(t_philo *philo);
void	wait_threads(t_table *table);

#endif