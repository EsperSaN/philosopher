/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:31:56 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 22:08:41 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_ms(t_philo *p, long ms)
{
	long	dif;

	p->p_time = get_time();
	dif = 0;
	if (*p->status == DIE)
		return ;
	while (dif < ms)
	{
		usleep(1);
		dif = dif_current_time(p->p_time);
	}
}

void	report(t_philo *p, char *report)
{
	pthread_mutex_lock(p->print_lock);
	if (*p->status == ALIVE)
		printf("%lu    %d    %s\n", dif_current_time(p->begin_time), \
		p->no, report);
	pthread_mutex_unlock(p->print_lock);
}

void	eat_now(t_philo	*philo)
{
	if (*philo->status == DIE)
		return ;
	if (philo->no % 2 == 0)
	{
		pthread_mutex_lock(philo->spoon_right);
		pthread_mutex_lock(philo->spoon_left);
	}
	else
	{
		pthread_mutex_lock(philo->spoon_left);
		pthread_mutex_lock(philo->spoon_right);
	}
	report(philo, "has taken a fork");
	report(philo, "is eating");
	philo->last_eat_time = get_time();
	sleep_ms(philo, philo->eat_time);
	pthread_mutex_unlock(philo->spoon_left);
	pthread_mutex_unlock(philo->spoon_right);
}

void	*rout(void *av)
{
	int		count;
	long	st_time;
	t_philo	*philo;

	philo = (t_philo *) av;
	if (philo->no % 2 == 0)
		usleep(7);
	count = 0;
	st_time = get_time();
	philo->last_eat_time = st_time;
	while (*philo->status == ALIVE)
	{
		report(philo, "is thinking");
		while (philo->spoon_left == NULL && philo->spoon_right == NULL \
				&& *philo->status == ALIVE)
			sleep_ms(philo, philo->die_time);
		eat_now(philo);
		count++;
		if (count == philo->eat_count)
			philo->full = 1;
		report(philo, "is sleeping");
		sleep_ms(philo, philo->sleep_time);
	}
	return (0);
}
