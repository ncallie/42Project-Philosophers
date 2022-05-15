/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:53:38 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:47:55 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (is_error(ERR1));
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!is_digit(argv[i][j]))
				return (is_error(ERR2));
	}
	return (SUCCESS);
}

int	parse_argv(t_data *args, char **argv, int argc)
{
	args->philo_num = ft_atoi(argv[1]);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	args->num_of_meals = -1;
	args->flag = 0;
	if (argc == 6)
		args->num_of_meals = ft_atoi(argv[5]);
	if ((args->philo_num == -1 || args->t_die == -1
			|| args->t_eat == -1 || args->t_sleep == -1)
		|| (argc == 6 && args->num_of_meals == -1))
		return (is_error(ERR4));
	return (SUCCESS);
}
