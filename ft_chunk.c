/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:20:16 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/28 12:14:20 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	get_chunk(t_stack *data)
{
	if (data->count_nb < 100)
		data->chunk_nb = 4;
	else if (data->count_nb >= 500)
		data->chunk_nb = 15;
	else if (data->count_nb >= 300)
		data->chunk_nb = 10;
	else if (data->count_nb >= 100)
		data->chunk_nb = 5;
	data->chunk_size = (data->count_nb / data->chunk_nb);
	if (data->count_nb % data->chunk_nb != 0)
		data->chunk_nb += 1;
	data->start = 1;
	data->end = data->chunk_size;
}

int	is_in_chunk(t_nb *list, int start, int end, int len)
{
	int	i;
	int	j;

	i = -1;
	j = len;
	while (i++ < len)
		if (list[i].index >= start && list[i].index <= end)
			break ;
	if (i == len)
		return (-1);
	while (j-- >= 0)
		if (list[j].index >= start && list[j].index <= end)
			break ;
	if (j < 0)
		return (-1);
	if (i < (len - j))
		return (i);
	else if ((len - j) <= i)
		return (j);
	return (-1);
}

void	next_chunk(t_stack *data)
{
	if (data->start < data->count_nb)
		data->start = data->end + 1;
	data->end += data->chunk_size;
	if (data->end > data->count_nb)
		data->end = data->count_nb;
	if (data->chunk_nb == 1 && data->end < data->count_nb)
		data->chunk_nb++;
	else
		data->chunk_nb--;
}
