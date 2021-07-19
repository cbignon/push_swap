/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:06 by cbignon           #+#    #+#             */
/*   Updated: 2021/07/16 16:25:27 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*data;

	data = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
		return (0);
	data = init_stack(data, argc - 1);
	check_arg(argv, data);
	if (data->error == 0)
		create_pile(argv, data);
	if (data->error > 0)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	// printf("le plus grand est a[%i]\n", big_in_list(data->a, data->len_a));
	//  printf("le plus petit est a[%i]\n", small_in_list(data->a, data->len_a));
	//else
	// get_chunk(data);
	// printf("is in chunk : a[%d]\n", is_in_chunk(data->a, data->start, data->end, data->len_a));
	push_swap(data);
	//get_chunk(data);
	int i;
	i = 0;
	while (i < data->len_a)
	{
		printf("nb a[%d] = %d\n", i, data->pile_a[i].nbr);
		i++;
	}
	i = 0;
	while (i < data->len_a)
	{
		printf("nb index[%d] = %d\n", i, data->pile_a[i].index);
		i++;
	}
	printf("nb de coups = %d\n", data->count_op);
	printf("len_a = %d\n", data->len_a);
	printf("len_b = %d\n", data->len_b);
	if (is_sorted(data->pile_a, data->count_nb) == 1)
		printf("c'est trié!\n");
	else
		printf("C'est FOIRÉ\n");
	printf("chunk size= %d\n", data->chunk_size);
	free(data->pile_a);
	free(data->pile_b);
	free(data);
	return (0);
}
