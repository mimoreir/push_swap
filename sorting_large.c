/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:56:56 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:56:57 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last(t_stack *a)
{
	int	last;

	last = 0;
	while (a->next != NULL)
		a = a->next;
	return (last = a->num);
}

void	push_by_median(t_stack **a, t_stack **b, int med)
{
	while (there_is_below(a, med))
	{
		if ((*a)->num <= med)
			pb(a, b);
		else
		{
			if ((*b) != NULL && (*b)->next != NULL)
			{
				if ((*b)->num == minimum(*b))
					rr(a, b);
				else
					ra(a);
			}
			else
				ra(a);
		}
	}
}

void	push_lower(t_stack **a, t_stack **b)
{
	if ((*b) == NULL)
		return ;
	while ((*b)->next != NULL)
	{
		if (!use_max_or_min(b, get_stack_size(*b)))
			push_by_min(a, b);
		else
			push_by_max(a, b);
	}
	pa(a, b);
	ra(a);
}

void	push_by_uppermedian(t_stack **a, t_stack **b, int med)
{
	int	max;

	max = maximum(*a);
	while (1)
	{
		if ((*a)->num == max)
			ra(a);
		else
			pb(a, b);
		if ((*a) != NULL && (*a)->num <= med)
			break ;
	}
	rra(a);
}

void	sorting_large(t_stack **a, t_stack **b)
{
	int	med;

	med = get_median(*a);
	push_by_median(a, b, med);
	push_lower(a, b);
	set_list_for_upper(a, med);
	push_by_uppermedian(a, b, med);
	push_lower(a, b);
	put_in_order(a);
}
