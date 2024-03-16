/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:53:25 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:53:28 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		n;

	if ((*a)->next != NULL)
	{
		tmp = (*a)->next;
		n = tmp->num;
		tmp->num = (*a)->num;
		(*a)->num = n;
	}
	if ((*b)->next != NULL)
	{
		tmp = (*b)->next;
		n = tmp->num;
		tmp->num = (*b)->num;
		(*b)->num = n;
	}
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*it;
	t_stack	*tmp;

	tmp = *a;
	it = (*a)->next;
	tmp->next = NULL;
	*a = it;
	while (it->next != NULL)
		it = it->next;
	it->next = tmp;
	tmp = *b;
	if (tmp->next != NULL)
	{
		it = (*b)->next;
		tmp->next = NULL;
		*b = it;
		while (it->next != NULL)
			it = it->next;
		it->next = tmp;
	}
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*it;
	t_stack	*prev;

	it = (*a);
	while (it->next != NULL)
	{
		prev = it;
		it = it->next;
	}
	prev->next = NULL;
	it->next = (*a);
	(*a) = it;
	it = (*b);
	while (it->next != NULL)
	{
		prev = it;
		it = it->next;
	}
	prev->next = NULL;
	it->next = (*b);
	(*b) = it;
	ft_printf("rrr\n");
}
