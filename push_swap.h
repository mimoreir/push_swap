/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:24:00 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/23 01:24:02 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct int_list
{
	int				num;
	struct int_list	*next;
}	t_stack;
t_stack		*create_new(int n);
void		lst_add(t_stack *head, t_stack *new);
void		print_lst(t_stack **a, t_stack **b);
void		free_lst(t_stack **head);
t_stack		*init_list(int argc, char const *argv[]);
void		push_swap(int argc, t_stack **a, t_stack **b);
int			is_sorted(t_stack *a);
int			verify_args(int argc, char const *argv[]);
int			is_number(const char *str);
int			no_repeated(t_stack *a);
long int	ft_atol(const char *str);
void		pa(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		ra(t_stack **a);
void		rra(t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		sb(t_stack **b);
void		rb(t_stack **b);
void		rrb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		sorting_3(t_stack **a);
void		sorting_5(t_stack **a, t_stack **b, int argc);
void		push_by_median(t_stack **a, t_stack **b, int med);
void		push_lower(t_stack **a, t_stack **b);
void		push_by_uppermedian(t_stack **a, t_stack **b, int med);
void		rotate_to_fit(t_stack **a, int nb);
void		sorting_large(t_stack **a, t_stack **b);
int			use_max_or_min(t_stack **b, int size);
void		push_by_min(t_stack **a, t_stack **b);
void		push_by_max(t_stack **a, t_stack **b);
void		sorting_above_100(t_stack **a, t_stack **b);
void		sort_last_chunk(t_stack **a, t_stack **b);
int			maximum(t_stack *a);
int			minimum(t_stack *a);
int			get_stack_size(t_stack *a);
int			calculate_op(t_stack *a, int min, int size);
int			get_last(t_stack *a);
int			get_median(t_stack *a);
void		put_in_order(t_stack **a);
int			get_pivots(t_stack *a, int part);
t_stack		*copy_list(t_stack *a);
void		sort_b(t_stack **b);
void		set_list_for_upper(t_stack **a, int med);
int			get_num_index(t_stack *b, int n);
int			max_2(t_stack **a, int max);
int			max_3(t_stack **a, int max, int max2);
int			there_is_below(t_stack **a, int med);

#endif
