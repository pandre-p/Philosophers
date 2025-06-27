/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:45:46 by ppassos           #+#    #+#             */
/*   Updated: 2025/05/26 18:15:45 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philol.h"

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if ((TAKE_F_FORK == status || TAKE_S_FORK == status)
		&& !s_finish(philo->table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !s_finish(philo->table))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (SPLEEPING == status && !s_finish(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !s_finish(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf("%-6ld %d died\n", elapsed, philo->id);
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}
