/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:59:26 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/28 10:06:38 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	big_in_list(t_nb *s, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (size < 2)
		return (0);
	else if (size == 2)
	{
		if (s[0].index > s[1].index)
			return (0);
		else
			return (1);
	}
	while (j < size)
	{
		while (s[i].index > s[j].index && j < size)
			j++;
		if (s[i].index < s[j].index && j < size)
		{
			i = j;
			j++;
		}
	}
	return (i);
}

int	small_in_list(t_nb *list, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (size < 2)
		return (0);
	else if (size == 2)
	{
		if (list[0].index > list[1].index)
			return (1);
		else
			return (0);
	}
	while (j < size)
	{
		if (list[i].index < list[j].index && j < size)
			j++;
		if (list[i].index > list[j].index && j < size)
		{
			i = j;
			j++;
		}
	}
	return (i);
}
