/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:04:23 by ppassos           #+#    #+#             */
/*   Updated: 2025/05/27 11:03:15 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philol.h"

void	wait_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		usleep(10);
}

bool	all_threads_running(t_mtx *mutex, long *threads, long p_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex(mutex, LOCK);
	if (*threads == p_nbr)
		ret = true;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mtx *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}

void	the_synchronize(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(30000, philo->table);
	}
	else
	{
		if (philo->id % 2)
			think(philo, true);
	}
}
