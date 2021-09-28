/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:53:06 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/25 13:29:48 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_stack(t_stack *data, int args)
{
	data->count_nb = 0;
	data->chunk_nb = 1;
	data->chunk_size = 0;
	data->len_a = args;
	data->max = data->len_a;
	data->min = 1;
	data->len_b = 0;
	data->error = 0;
	data->pile_a = (t_nb *)malloc(sizeof(t_nb) * data->len_a);
	data->pile_b = (t_nb *)malloc(sizeof(t_nb) * data->len_a);
	if (data->pile_a == NULL || data->pile_b == NULL)
		data->error += 1;
}

t_stack	*create_pile(char **argv, t_stack *data)
{
	int		i;
	t_check	nb;

	i = 0;
	while (i < data->len_a)
	{
		if (argv[i + 1][0] == '\0')
			i++;
		else
		{
			nb.nb = ft_strtol_dec(argv[i + 1], data);
			is_int(&nb, data);
			if (nb.is_int == 1)
			{
				data->pile_a[i].nbr = nb.final;
				data->count_nb++;
			}
			i++;
		}
	}
	data->len_a = data->count_nb;
	if (ft_check_double(data->pile_a, data->len_a) == -1)
		data->error += 1;
	ft_correspond_id(data);
	return (data);
}
