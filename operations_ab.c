/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:22 by cbignon           #+#    #+#             */
/*   Updated: 2021/07/16 15:27:56 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rev_rotate_ab(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_a[data->len_a - 1];
	data->pile_a = shift_down(data->pile_a, data->len_a - 1, data->count_nb);
	data->pile_a[0] = tmp;
	tmp = data->pile_b[data->len_b - 1];
	data->pile_b = shift_down(data->pile_b, data->len_b - 1, data->count_nb);
	data->pile_b[0] = tmp;
	write(1, "rrr\n", 4);
	data->count_op += 1;
}

void	rotate_a_b(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_a[0];
	data->pile_a = shift_up(data->pile_a, data->len_a - 1, data->count_nb);
	data->pile_a[data->len_a - 1] = tmp;
	tmp = data->pile_b[0];
	data->pile_b = shift_up(data->pile_b, data->len_b - 1, data->count_nb);
	data->pile_b[data->len_b - 1] = tmp;
	write(1, "rr\n", 3);
	data->count_op += 1;
}

void	swap_ab(t_stack *data)
{
	t_nb	tmp;

	if (data->len_a > 1)
	{
		tmp = data->pile_a[0];
		data->pile_a[0] = data->pile_a[1];
		data->pile_a[1] = tmp;
	}
	if (data->len_b > 1)
	{
		tmp = data->pile_b[0];
		data->pile_b[0] = data->pile_b[1];
		data->pile_b[1] = tmp;
	}
	data->count_op += 1;
	write(1, "ss\n", 3);
}
