/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:04:21 by cbignon           #+#    #+#             */
/*   Updated: 2021/07/16 15:43:40 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_swap(t_stack *data)
{
	if (is_sorted(data->pile_a, data->len_a) == 0)
		return ;
	if (data->count_nb <= 3)
		ft_sort_3(data);
	else if (data->count_nb <= 5)
		ft_sort_5(data);
	else if (data->count_nb > 5)
		ft_sort_100(data);
}

void	ft_sort_5(t_stack *data)
{
	int	i;

	i = 0;
	while (data->len_a > 2)
	{
		i = small_in_list(data->pile_a, data->len_a);
		if (i > data->len_a / 2)
		{
			while (i++ < data->len_a)
				rev_rotate_a(data);
			push_b(data);
			i = small_in_list(data->pile_a, data->len_a);
		}
		else
		{
			while (i-- > 0)
				rotate_a(data);
			push_b(data);
			i = small_in_list(data->pile_a, data->len_a);
		}
	}
	if (is_sorted(data->pile_a, data->len_a) == -1)
		swap_a(data);
	while (data->len_b > 0)
		push_a(data);
}

void	ft_sort_3(t_stack *data)
{
	while (is_sorted(data->pile_a, data->len_a) == -1)
	{
		if (data->pile_a[0].index == data->max)
			rotate_a(data);
		else if (data->pile_a[1].index == data->max)
			rev_rotate_a(data);
		else if (data->pile_a[2].index == data->min)
			rev_rotate_a(data);
		else if (data->pile_a[0].index > data->pile_a[1].index)
			swap_a(data);
	}
}

void	ft_sort_100(t_stack *data)
{
	int	i;

	get_chunk(data);
	while (data->chunk_nb > 0)
	{
		i = is_in_chunk(data->pile_a, data->start, data->end, data->len_a);
		while (i > -1)
		{
			if (i < (data->len_a / 2))
				while (i-- > 0)
					rotate_a(data);
			else if (i >= (data->len_a / 2))
				while (i++ < data->len_a)
					rev_rotate_a(data);
			push_b(data);
			i = is_in_chunk(data->pile_a, data->start, data->end, data->len_a);
		}
		if (i == -1)
			next_chunk(data);
	}
	fill_a(data);
}

void	fill_a(t_stack *data)
{
	int	i;

	while (data->len_a < data->count_nb)
	{
		i = big_in_list(data->pile_b, data->len_b);
		if (i == 1)
		{
			swap_b(data);
			push_a(data);
		}
		else if (i < data->len_b / 2)
		{
			while (i-- > 0)
				rotate_b(data);
			push_a(data);
		}
		else if (i >= data->len_b / 2)
		{
			while (i++ < data->len_b)
				rev_rotate_b(data);
			push_a(data);
		}
	}
}
