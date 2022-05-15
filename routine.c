/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:01:34 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:03:14 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	philo_sleep(long time_wait)
{
	long	cur_t;
	long	period;

	cur_t = get_cur_time();
	period = get_cur_time() + time_wait;
	while (period > cur_t)
	{
		usleep(100);
		cur_t = get_cur_time();
	}
}

void	ft_output(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->mutex->output);
	if (philo->args->flag == 1)
		return ;
	else if (philo->args->flag == 0)
	{
		printf("%ld The philo %d %s\n",
			get_cur_time() - philo->start_time, philo->id, str);
		pthread_mutex_unlock(&philo->mutex->output);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_output(philo, "has taken a right fork");
	pthread_mutex_lock(philo->l_fork);
	ft_output(philo, "has taken a left fork");
	ft_output(philo, "is eating");
}

void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	philo->last_meal = get_cur_time();
	pthread_detach(philo->thread);
	while (1)
	{
		if (philo->eat_count != 0)
		{
			eating(philo);
			philo->last_meal = get_cur_time();
			philo->eat_count--;
			philo_sleep(philo->args->t_eat);
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
			ft_output(philo, "is sleeping");
			philo_sleep(philo->args->t_sleep);
			ft_output(philo, "is thinking");
		}
		else
			break ;
	}
	return (NULL);
}
