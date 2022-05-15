/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:59:23 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 14:20:29 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	make_thread(t_all *all, int flag, int i)
{
	if (all->philos[i].id % 2 == flag)
	{
		all->philos[i].start_time = all->args->time;
		all->philos[i].mutex = malloc(sizeof(t_mutexes));
		if (!all->philos[i].mutex)
			return (FAIL);
		if (pthread_create(&all->philos[i].thread, NULL,
				&routine, &all->philos[i]) != 0)
			return (FAIL);
	}
	usleep(30);
	return (SUCCESS);
}

int	philo_thread(t_all *all)
{
	int	i;

	i = -1;
	all->args->time = get_cur_time();
	while (++i < all->args->philo_num)
	{
		if (!make_thread(all, EVEN, i))
			return (is_error(ERR7));
	}
	i = -1;
	usleep(10);
	while (++i < all->args->philo_num)
	{
		if (!make_thread(all, ODD, i))
			return (is_error(ERR7));
	}
	if (pthread_create(&all->dead, NULL, &check_dead, all) != 0)
		return (is_error(ERR7));
	if (pthread_join(all->dead, NULL) != 0)
		return (is_error(ERR8));
	destroy_and_free(all);
	return (SUCCESS);
}
