/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:57:39 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:57:40 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_fit(t_stack **a, int nb)
{
	t_stack	*it;
	int		i;
	int		last;

	last = get_last(*a);
	it = (*a);
	i = -1;
	if (nb < minimum(*a) || nb > maximum(*a))
	{
		put_in_order(a);
		return ;
	}
	while (it != NULL)
	{
		i++;
		if (last < nb && nb < it->num)
			break ;
		last = it->num;
		it = it->next;
	}
	if (i <= (get_stack_size(*a) / 2))
		ra(a);
	else
		rra(a);
}

void	sorting_3(t_stack **a)
{
	int	y;
	int	z;

	y = (*a)->next->num;
	z = (*a)->next->next->num;
	if ((*a)->num > y && y < z && z > (*a)->num)
		sa(a);
	else if ((*a)->num > y && y > z && z < (*a)->num)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->num > y && (*a)->num > z && y < z)
		ra(a);
	else if ((*a)->num < y && y > z && z > (*a)->num)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->num < y && (*a)->num > z && y > z)
		rra(a);
}

void	sorting_5(t_stack **a, t_stack **b, int argc)
{
	int	max;

	max = maximum(*a);
	pb(a, b);
	if (argc == 6)
	{
		pb(a, b);
		if ((*b)->num < (*b)->next->num)
			sb(b);
	}
	sorting_3(a);
	while ((*b) != NULL)
	{
		if ((*b) != NULL && (*b)->num < minimum((*a)))
			pa(a, b);
		if ((*b) != NULL && (*b)->num == max)
			pa(a, b);
		if ((*b) != NULL && (*b)->num > get_last(*a) && (*b)->num < (*a)->num)
			pa(a, b);
		if ((*b) != NULL)
			rotate_to_fit(a, (*b)->num);
	}
	put_in_order(a);
}

void	put_in_order(t_stack **a)
{
	int		size;
	int		i;
	int		min;
	t_stack	*it;

	size = get_stack_size((*a));
	min = minimum((*a));
	it = (*a);
	i = 0;
	while (it->num != min)
	{
		i++;
		it = it->next;
	}
	if (i < (size / 2))
		while (!is_sorted(*a))
			ra(a);
	else
		while (!is_sorted(*a))
			rra(a);
}

void	set_list_for_upper(t_stack **a, int med)
{
	while ((*a)->num <= med)
	{
		ra(a);
	}
}
