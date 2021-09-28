/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:08:14 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/28 12:33:57 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*check_sign(char *str, t_stack *data)
{
	if (ft_isdigit(*str) == 0)
	{
		data->error += 1;
		str++;
	}
	if (*str == ' ')
		str++;
	if (*str == '+')
	{
		if (ft_isdigit(*str) == 0)
		{
			data->error += 1;
			str++;
		}
	}
	return (str);
}

int	ft_nb_len(const char *str, t_stack	*data)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] >= '0' && str[len] <= '9')
		len++;
	if (len <= 0 || len > 10)
		data->error += 1;
	return (len);
}

long	ft_pow(long nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
