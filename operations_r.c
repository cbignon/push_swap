/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:49:21 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/25 13:30:51 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_a[0];
	data->pile_a = shift_up(data->pile_a, data->len_a - 1, data->count_nb);
	data->pile_a[data->len_a - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_b[0];
	data->pile_b = shift_up(data->pile_b, data->len_b - 1, data->count_nb);
	data->pile_b[data->len_b - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rev_rotate_a(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_a[data->len_a - 1];
	data->pile_a = shift_down(data->pile_a, data->len_a - 1, data->count_nb);
	data->pile_a[0] = tmp;
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack *data)
{
	t_nb	tmp;

	tmp = data->pile_b[data->len_b - 1];
	data->pile_b = shift_down(data->pile_b, data->len_b - 1, data->count_nb);
	data->pile_b[0] = tmp;
	write(1, "rrb\n", 4);
}
