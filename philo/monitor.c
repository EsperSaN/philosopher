/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:31:28 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 21:44:20 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	dif_current_time(long time)
{
	return (get_time() - time);
}

void	die_check(t_philo *p)
{
	if (dif_current_time(p->last_eat_time) > p->die_time)
	{
		pthread_mutex_lock(p->print_lock);
		if (*p->status == ALIVE)
			printf("%lu    %d  died\n", dif_current_time(p->begin_time), p->no);
		*p->status = DIE;
		pthread_mutex_unlock(p->print_lock);
	}
}

int	is_all_eaten(t_var *v)
{
	int		i;
	int		eatten_p;

	i = 0;
	eatten_p = 0;
	while (i < v->philo_num)
	{
		if (v->philo[i].full == 1)
			eatten_p++;
		i++;
	}
	if (eatten_p == v->philo_num)
	{
		*v->status = DIE;
		return (1);
	}
	else
		return (0);
}

void	mammy_thread_takking_care_of_all_philo(t_var *v)
{
	int	i;

	i = 0;
	while (*v->status == ALIVE)
	{
		usleep(1);
		if (i == v->philo_num)
			i = 0;
		die_check(&v->philo[i]);
		is_all_eaten(v);
		i++;
	}
}
