/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:09 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:54:11 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_printf("pb\n");
}

void	sb(t_stack **b)
{
	t_stack	*tmp;
	int		n;

	if ((*b)->next == NULL)
		;
	tmp = (*b)->next;
	n = tmp->num;
	tmp->num = (*b)->num;
	(*b)->num = n;
	ft_printf("sb\n");
}

void	rb(t_stack **b)
{
	t_stack	*it;
	t_stack	*tmp;

	if ((*b)->next != NULL)
	{
		tmp = (*b);
		it = (*b)->next;
		tmp->next = NULL;
		(*b) = it;
		while (it->next != NULL)
			it = it->next;
		it->next = tmp;
	}
	ft_printf("rb\n");
}

void	rrb(t_stack **b)
{
	t_stack	*it;
	t_stack	*prev;

	it = (*b);
	while (it->next != NULL)
	{
		prev = it;
		it = it->next;
	}
	prev->next = NULL;
	it->next = (*b);
	(*b) = it;
	ft_printf("rrb\n");
}
