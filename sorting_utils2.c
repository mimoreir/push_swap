/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:53:42 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:53:45 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_list(t_stack *a)
{
	t_stack	*b;
	t_stack	*ita;

	ita = a;
	b = create_new(ita->num);
	ita = ita->next;
	while (ita != NULL)
	{
		lst_add(b, create_new(ita->num));
		ita = ita->next;
	}
	return (b);
}

void	sort_b(t_stack **b)
{
	t_stack	*it;
	int		tmp;

	it = (*b);
	while (it->next != NULL)
	{
		if (it->num > it->next->num)
		{
			tmp = it->num;
			it->num = it->next->num;
			it->next->num = tmp;
			it = (*b);
		}
		else
			it = it->next;
	}
}

int	use_max_or_min(t_stack **b, int size)
{
	int		max;
	int		min;
	int		i;
	int		j;

	i = 0;
	j = 0;
	max = maximum((*b));
	min = minimum((*b));
	i = get_num_index(*b, min);
	j = get_num_index(*b, max);
	if (i <= j && i <= (size / 2))
		return (0);
	if (j <= i && j <= (size / 2))
		return (1);
	if (i > j && i > (size / 2))
		return (0);
	if (j > i && j > (size / 2))
		return (1);
	return (0);
}

void	push_by_min(t_stack **a, t_stack **b)
{
	int	min;
	int	op;

	min = minimum(*b);
	op = calculate_op(*b, min, get_stack_size(*b));
	while ((*b)->num != min)
	{
		if (op == 0)
			rb(b);
		else
			rrb(b);
	}
	pa(a, b);
	if (!use_max_or_min(b, get_stack_size(*b)))
	{
		min = minimum(*b);
		op = calculate_op(*b, min, get_stack_size(*b));
		if (op == 0 && (*b)->num != min && (*a)->num > (*b)-> num)
			rr(a, b);
		else
			ra(a);
	}
	else
		ra(a);
}

void	push_by_max(t_stack **a, t_stack **b)
{
	int	max;
	int	op;

	max = maximum(*b);
	op = calculate_op(*b, max, get_stack_size(*b));
	while (1)
	{
		if ((*b)->num == max)
		{
			pa(a, b);
			break ;
		}
		else
		{
			if (op == 0)
				rb(b);
			else
				rrb(b);
		}
	}
}
