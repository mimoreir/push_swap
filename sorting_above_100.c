/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_above_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:57:16 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:57:18 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_partitions(t_stack **a, t_stack **b)
{
	t_stack	*k;
	int		pivot;
	int		i;

	i = 10;
	k = copy_list(*a);
	sort_b(&k);
	while (i > 0)
	{
		pivot = get_pivots(k, i);
		push_by_median(a, b, pivot);
		i--;
	}
	free_lst(&k);
}

int	max_2(t_stack **a, int max)
{
	t_stack	*it;
	int		nb;

	it = (*a);
	if (it->num != max)
		nb = it->num;
	else
		nb = -2147483648;
	while (it != NULL)
	{
		if (it->num > nb && it->num != max)
			nb = it->num;
		it = it->next;
	}
	return (nb);
}

int	max_3(t_stack **a, int max, int max2)
{
	t_stack	*it;
	int		nb;

	it = (*a);
	if (it->num != max && it->num != max2)
		nb = it->num;
	else
		nb = -2147483648;
	while (it != NULL)
	{
		if (it->num > nb && it->num != max && it->num != max2)
			nb = it->num;
		it = it->next;
	}
	return (nb);
}

void	sort_last_chunk(t_stack **a, t_stack **b)
{
	int	max;
	int	max2;
	int	max3;

	max = maximum(*a);
	max2 = max_2(a, max);
	max3 = max_3(a, max, max2);
	while (get_stack_size(*a) > 3)
	{
		if ((*a)->num == max || (*a)->num == max2 || (*a)->num == max3)
			ra(a);
		else if ((*a)-> num != max)
		{
			pb(a, b);
		}
	}
	sorting_3(a);
}

void	sorting_above_100(t_stack **a, t_stack **b)
{
	do_partitions(a, b);
	sort_last_chunk(a, b);
	push_lower(a, b);
	put_in_order(a);
}
