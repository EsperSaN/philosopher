/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:32:02 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 17:32:09 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(unsigned char *)s = 0;
		s++;
		n--;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*malzero;
	size_t	len;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	len = size * count;
	malzero = malloc(len);
	if (malzero == NULL)
		return (NULL);
	ft_bzero(malzero, len);
	return (malzero);
}

int	is_num(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	is_all_num(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (!is_num(*str))
			return (0);
		str++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int				len;
	int				lob;
	unsigned long	result;

	len = 0;
	result = 0;
	lob = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'\
				|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			lob = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		len++;
	}
	return ((result * lob));
}
