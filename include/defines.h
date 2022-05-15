/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:04:39 by ncallie           #+#    #+#             */
/*   Updated: 2022/01/11 12:10:04 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define EVEN 0
# define ODD 1
# define INT_MAX 2147483647
# define SUCCESS 1
# define FAIL 0
# define ERR1 "\033[0;31mError\n\033[0;32m./philo [number_of_philosophers] \
[time_to_die] [time_to_eat] [time_to_sleep] \
[number_of_times_each_philosopher_must_eat]\n"
# define ERR2 "\033[0;31mError\n\
\033[0;32mThe argument must be a positive integer\n"
# define ERR3 "\033[0;31mError allocating memory\n"
# define ERR4 "\033[0;31mNumber is greater MAX_INT value\n"
# define ERR5 "\033[0;31mThe number must not be 0\n"
# define ERR6 "\033[0;31mMutex init error\n"
# define ERR7 "\033[0;31mThread can't be created\n"
# define ERR8 "\033[0;31mThread can't be joined\n"

#endif