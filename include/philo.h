/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:05:54 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:06:41 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "defines.h"
# include "structs.h"

int		is_error(char *str);
int		is_digit(char c);
int		ft_atoi(char *str);
int		check_arg(int argc, char **argv);
int		parse_argv(t_data *args, char **argv, int argc);
int		init_mutex(t_all *all);
int		main(int argc, char *argv[]);
int		init_phil(t_all *all);
long	get_cur_time(void);
void	*check_dead(void *all_data);
int		philo_thread(t_all *all);
int		make_thread(t_all *all, int flag, int i);
void	destroy_and_free(t_all *all);
void	*routine(void *philo_void);
int		death_checker(t_philo *philos);
void	destroy_mutexes(t_all *all);

#endif