/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:07:03 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 13:41:09 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_mutexes
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
}t_mutexes;

typedef struct s_data
{
	int		philo_num;
	int		t_sleep;
	int		t_eat;
	int		t_die;
	int		num_of_meals;
	int		flag;
	long	time;
}t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			start_time;
	long			last_meal;
	t_data			*args;
	t_mutexes		*mutex;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}t_philo;

typedef struct s_all
{
	pthread_t	dead;
	t_data		*args;
	t_mutexes	*mutexes;
	t_philo		*philos;
}t_all;

#endif