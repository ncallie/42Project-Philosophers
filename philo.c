/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:01:01 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:01:19 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int argc, char *argv[])
{
	t_all	all;

	if (!check_arg(argc, argv))
		return (FAIL);
	all.args = malloc(sizeof(t_data));
	if (!all.args)
		return (is_error(ERR3));
	if (!parse_argv(all.args, argv, argc))
		return (FAIL);
	if (!init_mutex(&all) || !init_phil(&all))
		return (FAIL);
	if (!philo_thread(&all))
		return (FAIL);
	return (SUCCESS);
}
