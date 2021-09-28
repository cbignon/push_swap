/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:52:42 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/25 13:31:05 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(t_stack *data)
{
	t_nb	tmp;

	if (data->len_a <= 1)
		return ;
	else if (data->len_a > 1)
	{
		tmp = data->pile_a[0];
		data->pile_a[0] = data->pile_a[1];
		data->pile_a[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *data)
{
	t_nb	tmp;

	if (data->len_b <= 1)
		return ;
	else if (data->len_b > 1)
	{
		tmp = data->pile_b[0];
		data->pile_b[0] = data->pile_b[1];
		data->pile_b[1] = tmp;
	}
	write(1, "sb\n", 3);
}
