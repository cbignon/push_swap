/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:01:12 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/24 16:25:59 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_nb *pile, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (pile[i].nbr > pile[i + 1].nbr)
			return (-1);
		i++;
	}
	return (1);
}

int	is_sorted_reverse(t_nb *pile, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (1);
	while (i + 1 < size)
	{
		if (pile[i].nbr < pile[i + 1].nbr)
			return (-1);
		i++;
	}
	return (1);
}
