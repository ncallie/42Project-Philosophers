/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:57:29 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 14:41:38 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	init_mutex(t_all *all)
{
	int	i;

	all->mutexes = malloc(sizeof(t_mutexes));
	if (!all->mutexes)
		return (is_error(ERR3));
	all->mutexes->forks = malloc(sizeof(pthread_mutex_t)
			* all->args->philo_num);
	if (!all->mutexes->forks)
		return (is_error(ERR3));
	if (pthread_mutex_init(&all->mutexes->output, NULL))
		return (is_error(ERR5));
	i = -1;
	while (++i < all->args->philo_num)
		if (pthread_mutex_init(&all->mutexes->forks[i], NULL))
			return (is_error(ERR5));
	return (SUCCESS);
}

int	init_phil(t_all *all)
{
	int	i;

	all->philos = malloc(sizeof(t_philo) * all->args->philo_num);
	if (!all->philos)
		return (is_error(ERR3));
	i = -1;
	while (++i < all->args->philo_num)
	{
		all->philos[i].id = i + 1;
		all->philos[i].last_meal = 0;
		all->philos[i].eat_count = all->args->num_of_meals;
		all->philos[i].args = all->args;
		all->philos[i].mutex = all->mutexes;
		all->philos[i].r_fork = &all->mutexes->forks[i];
		if ((i + 1) == all->args->philo_num)
			all->philos[i].l_fork = &all->mutexes->forks[0];
		else
			all->philos[i].l_fork = &all->mutexes->forks[i + 1];
	}
	return (SUCCESS);
}
