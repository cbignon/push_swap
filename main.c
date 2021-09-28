/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:06 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/24 14:51:22 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*data;

	data = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
		return (0);
	init_stack(data, argc - 1);
	check_arg(argv, data);
	if (data->error == 0)
		create_pile(argv, data);
	if (data->error > 0)
	{
		write(2, "Error\n", 7);
		free(data->pile_a);
		free(data->pile_b);
		free(data);
		return (-1);
	}
	push_swap(data);
	free(data->pile_b);
	data->pile_b = NULL;
	free(data);
	data = NULL;
	return (0);
}
