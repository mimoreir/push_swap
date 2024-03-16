/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:23:49 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/23 01:23:50 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, t_stack **a, t_stack **b)
{
	if (argc == 2)
		;
	else if (argc == 3)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
	}
	else if (argc == 4)
		sorting_3(a);
	else if (argc < 7)
		sorting_5(a, b, argc);
	else if (argc < 100)
		sorting_large(a, b);
	else
		sorting_above_100(a, b);
}

int	main(int argc, char const *argv[])
{
	t_stack	**a;
	t_stack	**b;
	t_stack	*a1;
	t_stack	*b1;

	a = NULL;
	b1 = NULL;
	b = &b1;
	if (argc > 1)
	{
		if (!verify_args(argc, argv))
		{
			ft_putstr_fd("Error\n", 2);
		}
		else
		{
			a1 = init_list(argc, argv);
			a = &a1;
			if (no_repeated(a1) && !is_sorted(a1))
				push_swap(argc, a, b);
		}
		free_lst(b);
		free_lst(a);
	}
	return (0);
}
