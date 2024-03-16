/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:43 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:54:45 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivots(t_stack *a, int part)
{
	int		index;
	int		i;
	int		size;
	int		num;
	t_stack	*it;

	i = 0;
	size = get_stack_size(a);
	index = size - ((size / 11) * part);
	it = a;
	while (i <= index)
	{
		i++;
		it = it->next;
	}
	num = it->num;
	return (num);
}

int	get_num_index(t_stack *b, int n)
{
	int		i;
	t_stack	*it;

	i = 0;
	it = b;
	while (it != NULL)
	{
		i++;
		if (it->num == n)
			break ;
		it = it->next;
	}
	return (i);
}

int	there_is_below(t_stack **a, int med)
{
	t_stack	*it;

	it = (*a);
	while (it != NULL)
	{
		if (it->num <= med)
			return (1);
		it = it->next;
	}
	return (0);
}
