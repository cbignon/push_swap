/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:03:27 by cbignon           #+#    #+#             */
/*   Updated: 2021/07/16 17:00:48 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_arg(char **argv, t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]) == 0 && ft_isdigit(argv[i][j]) == 0
				&& (argv[i][j] != '-' && (argv[i][j] != '+')))
			{
				data->error += 1;
				return ;
			}
			j++;
		}
	}
}

t_check	*is_int(t_check *nb, t_stack *data)
{
	nb->is_int = -1;
	if (nb->nb >= INT32_MIN && nb->nb <= INT32_MAX)
	{
		nb->final = nb->nb;
		nb->is_int = 1;
	}
	else
		data->error += 1;
	return (nb);
}

long	ft_strtol_dec(char *str)
{
	long long	nb;
	int			sign;
	int			len;

	nb = 0;
	sign = 1;
	while (!(*str >= '0' && *str <= '9'))
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		if (ft_isspace(*str) || *str == '+')
			str++;
	}
	len = ft_strlen(str);
	while (len >= 0 && *str >= '0' && *str <= '9')
	{
		nb += (*str - '0') * ft_pow(10, len - 1);
		len--;
		str++;
	}
	return (nb * sign);
}

int	ft_check_double(t_nb *list, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size && j < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (list[i].nbr != list[j].nbr)
				j++;
			if (list[i].nbr == list[j].nbr)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_correspond_id(t_stack *data)
{
	int	i;
	int	j;
	int	smaller;

	i = -1;
	j = 0;
	smaller = 1;
	while (i++ < data->len_a)
	{
		j = -1;
		smaller = 1;
		while (j++ < data->len_a)
		{
			if (data->pile_a[i].nbr > data->pile_a[j].nbr)
				smaller++;
		}
		data->pile_a[i].index = smaller;
	}
}
