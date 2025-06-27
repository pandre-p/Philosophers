/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_setters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:04:55 by ppassos           #+#    #+#             */
/*   Updated: 2025/05/26 18:02:34 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philol.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	safe_mutex(mutex, LOCK);
	ret = *value;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	safe_mutex(mutex, LOCK);
	ret = *value;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

bool	s_finish(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
