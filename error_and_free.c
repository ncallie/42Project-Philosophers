/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:56:41 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 11:57:17 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	is_error(char *str)
{
	printf ("%s", str);
	return (FAIL);
}

void	destroy_and_free(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->args->philo_num)
	{
		pthread_mutex_destroy(all->philos[i].l_fork);
		pthread_mutex_destroy(all->philos[i].r_fork);
		free(all->philos[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&all->mutexes->output);
	free(all->mutexes->forks);
	free(all->mutexes);
	free(all->philos);
	free(all->args);
}
