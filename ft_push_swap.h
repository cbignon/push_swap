/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:43:46 by cbignon           #+#    #+#             */
/*   Updated: 2021/07/16 16:09:39 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "struct.h"

typedef struct s_check
{
	long long	nb;
	int			is_int;
	int			final;
}				t_check;

typedef struct s_nb
{
	int			nbr;
	int			index;
}				t_nb;

typedef struct s_stack
{
	t_nb		*pile_a;
	t_nb		*pile_b;
	int			min;
	int			max;
	int			count_nb;
	int			len_a;
	int			len_b;
	int			count_op;
	int			error;
	int			chunk_nb;
	int			chunk_size;
	int			start;
	int			end;
}				t_stack;

int		ft_isdigit(int c);
int		ft_isspace(char c);
int		is_sorted(t_nb *pile, int size);
int		is_sorted_reverse(t_nb *pile, int size);
int		ft_check_double(t_nb *list, int size);
void	*init_stack(t_stack *data, int args);
void	push_swap(t_stack *data);
t_stack	*create_stack(char **argv, t_stack *data);
t_stack	*create_pile(char **argv, t_stack *data);
void	check_arg(char **argv, t_stack *data);
t_check	*is_int(t_check *nb, t_stack *data);
size_t	ft_strlen(const char *str);
int		ft_isspace(char c);
int		ft_pow(int a, int b);
long	ft_strtol_dec(char *str);
int		ft_find_it(int *s, int it, int last);
t_nb	*shift_down(t_nb *s, int size, int max);
t_nb	*shift_up(t_nb *s, int size, int max);
void	swap_a(t_stack *data);
void	swap_b(t_stack *data);
void	push_b(t_stack *data);
void	push_a(t_stack *data);
void	rotate_a(t_stack *data);
void	rotate_b(t_stack *data);
void	rotate_a_b(t_stack *data);
void	rev_rotate_a(t_stack *data);
void	rev_rotate_b(t_stack *data);
void	rev_rotate_ab(t_stack *data);
void	ft_sort_3(t_stack *data);
void	ft_sort_5(t_stack *data);
void	ft_sort_100(t_stack *data);
int		big_in_list(t_nb *list, int size);
int		small_in_list(t_nb *list, int size);
void	get_chunk(t_stack *data);
void	next_chunk(t_stack *data);
int		is_in_chunk(t_nb *list, int start, int end, int len);
void	fill_a(t_stack *data);
void	sort_last_chunk(t_stack *data);
void	ft_correspond_id(t_stack *data);
#endif