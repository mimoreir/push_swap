/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:03 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:54:05 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_printf("pa\n");
}

void	sa(t_stack **a)
{
	t_stack	*tmp;
	int		n;

	if ((*a)->next == NULL)
		;
	tmp = (*a)->next;
	n = tmp->num;
	tmp->num = (*a)->num;
	(*a)->num = n;
	ft_printf("sa\n");
}

void	ra(t_stack **a)
{
	t_stack	*it;
	t_stack	*tmp;

	tmp = (*a);
	it = (*a)->next;
	tmp->next = NULL;
	(*a) = it;
	while (it->next != NULL)
		it = it->next;
	it->next = tmp;
	ft_printf("ra\n");
}

void	rra(t_stack **a)
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
	ft_printf("rra\n");
}
