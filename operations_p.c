/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:40:39 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/25 13:31:36 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(t_stack *data)
{
	int	i;

	i = 0;
	if (data->len_b == 0)
		return ;
	data->pile_a = shift_down(data->pile_a, data->len_a, data->count_nb);
	data->pile_a[i] = data->pile_b[i];
	data->len_a += 1;
	data->len_b -= 1;
	i = 0;
	while (i < data->len_b)
	{
		data->pile_b[i] = data->pile_b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_stack *data)
{
	int	i;

	i = 0;
	if (data->len_a == 0)
		return ;
	data->pile_b = shift_down(data->pile_b, data->len_b, data->count_nb);
	data->pile_b[i] = data->pile_a[i];
	data->len_b += 1;
	data->len_a -= 1;
	i = 0;
	while (i < data->len_a)
	{
		data->pile_a[i] = data->pile_a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

t_nb	*shift_down(t_nb *s, int size, int max)
{
	int		i;
	t_nb	*shifted;

	i = 0;
	if (!s)
		return (NULL);
	shifted = (t_nb *)malloc(sizeof(t_nb) * max);
	while (i < size)
	{
		shifted[i + 1] = s[i];
		i++;
	}
	free(s);
	s = NULL;
	return (shifted);
}

t_nb	*shift_up(t_nb *s, int size, int max)
{
	int		i;
	int		j;
	t_nb	*shifted;

	i = 1;
	j = 0;
	if (!s)
		return (NULL);
	shifted = (t_nb *)malloc(sizeof(t_nb) * max);
	while (j < size)
	{
		shifted[j] = s[i];
		i++;
		j++;
	}
	free(s);
	s = NULL;
	return (shifted);
}
