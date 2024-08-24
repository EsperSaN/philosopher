/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:31:14 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 18:20:39 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_checker(char **arg)
{
	long	res;

	if (!arg)
		return (0);
	while (*arg)
	{
		if (!is_all_num(*arg))
			return (0);
		res = ft_atoi(*arg);
		if (res == 0 || res < 0 || res > INT_MAX || res < INT_MIN)
			return (0);
		arg++;
	}
	return (1);
}

int	give_philo_life(t_var *v)
{
	int	i;

	i = -1;
	while (++i < v->philo_num)
	{
		if (pthread_create(&v->philo[i].philo, NULL, \
			&rout, (void *)&v->philo[i]) != 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_var	v;
	int		i;

	if (ac < 5 || ac > 6)
		return (printf(ER_MSG), 1);
	if (!input_checker(av + 1))
		return (printf(INP_MSG), 1);
	if (!init_var(&v, av, ac))
	{
		let_em_free(&v);
		return (printf(FAIL_INIT), 1);
	}
	if (!give_philo_life(&v))
	{
		let_em_free(&v);
		return (printf(FAIL_THREAD), 1);
	}
	usleep(10);
	mammy_thread_takking_care_of_all_philo(&v);
	i = -1;
	while (++i < v.philo_num)
		pthread_join(v.philo[i].philo, NULL);
	let_em_free(&v);
	return (1);
}
