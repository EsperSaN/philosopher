/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:31:35 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 22:08:20 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# define ER_MSG "This program accept only 4 to 5 argument\n"
# define INP_MSG "Please put the correct argument [ONLY POSITIVE INT NUMBER]\n"
# define FAIL_INIT "Fail to init the value SRY\n"
# define INIT_S_ER "Fail to init the main struct\n"
# define FAIL_THREAD "Fail to create the Thread Philo\n"
# define MUTEX_FAIL "Fail to init the MUTEX variable\n"
# define ALIVE 0
# define DIE 1

typedef struct s_philo {
	pthread_t		philo;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*spoon_left;
	pthread_mutex_t	*spoon_right;
	int				no;
	int				*status;
	long			begin_time;
	long			last_eat_time;
	long			p_time;
	long			die_time;
	long			eat_time;
	long			eat_count;
	long			full;
	long			sleep_time;
}	t_philo;

typedef struct s_variable {
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*all_spoon;
	struct s_philo		*philo;
	long				philo_num;
	long				die_time;
	long				eat_time;
	long				think_time;
	long				sleep_time;
	long				eat_count;
	long				begin_epoch_time;
	int					*status;
}	t_var;

/* FREE.C */
void	let_em_free(t_var *v);
void	nfree(void *p);
/* INIT.C */
int		init_data(t_var *var);
int		init_var(t_var *var, char **av, int ac);
void	init_argument(t_var *var, char **av, int ac);
int		allocate_data(t_var *var);
void	assign_philo_data(t_var *var);
/* MAIN.C */
int		input_checker(char **arg);
int		give_philo_life(t_var *v);
/* MONITOR.C */
size_t	get_time(void);
long	dif_current_time(long time);
void	die_check(t_philo *p);
void	die_check(t_philo *p);
void	mammy_thread_takking_care_of_all_philo(t_var *v);
/* ROUTINE.C */
void	sleep_ms(t_philo *p, long ms);
void	report(t_philo *p, char *report);
void	eat_now(t_philo	*philo);
void	*rout(void *av);
/* UTIL.C */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		is_num(char c);
int		is_all_num(char *str);
long	ft_atoi(const char *str);
#endif