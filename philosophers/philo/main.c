/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:29:45 by ppassos           #+#    #+#             */
/*   Updated: 2025/05/27 14:55:49 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philol.h"

int	minimal_number(char **av, int i)
{
	long	a;

	a = ft_atol(av[i]);
	if (i == 1)
	{
		if (a == 0)
			return (0);
		return (1);
	}
	else
	{
		if (a < 1 && i != 5)
			return (0);
		if (a > INT_MAX)
			return (0);
		return (1);
	}
}

int	ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}

int	philo_checker(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (av[i])
	{
		j = 0;
		if (!av[i][0])
			return (0);
		while (av[i][j])
		{
			if (!ft_isnum(av[i][j]))
				return (0);
			j++;
		}
		if (!minimal_number(av, i))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	t;

	t = (t_table){0};
	if (philo_checker(av, ac))
	{
		parsing_input(&t, av);
		data_init(&t);
		start_dinner(&t);
		f_free(&t);
		return (0);
	}
	return (printf("Error\n"), 0);
}
