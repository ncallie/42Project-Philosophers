/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:03:24 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:45:35 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	return (FAIL);
}

int	ft_atoi(char *str)
{
	unsigned long	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if (nb > INT_MAX)
			return (-1);
	}
	return (nb);
}

long	get_cur_time(void)
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}
