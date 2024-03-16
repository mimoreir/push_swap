/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:56:36 by mimoreir          #+#    #+#             */
/*   Updated: 2023/04/24 12:56:38 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	calculate_op(t_stack *a, int min, int size)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (a->num == min)
			break ;
		i++;
		a = a->next;
	}
	if (i <= (size / 2))
		return (0);
	return (1);
}

int	get_median(t_stack *a)
{
	t_stack	*b;
	t_stack	*it;
	int		size;
	int		i;

	i = 0;
	b = copy_list(a);
	size = get_stack_size(b);
	sort_b(&b);
	it = b;
	while (i < (size / 2))
	{
		it = it->next;
		i++;
	}
	i = it->num;
	free_lst(&b);
	return (i);
}

int	maximum(t_stack *a)
{
	int	max;

	max = a->num;
	while (a != NULL)
	{
		if (a->num > max)
		{
			max = a->num;
		}
		a = a->next;
	}
	return (max);
}

int	minimum(t_stack *a)
{
	int	min;

	min = 2147483647;
	while (a != NULL)
	{
		if (a->num < min)
		{
			min = a->num;
		}
		a = a->next;
	}
	return (min);
}
