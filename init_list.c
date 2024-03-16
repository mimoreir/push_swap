/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:21:58 by mimoreir          #+#    #+#             */
/*   Updated: 2022/12/23 01:22:29 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new(int n)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	tmp->num = n;
	tmp->next = NULL;
	return (tmp);
}

void	lst_add(t_stack *head, t_stack *new)
{
	if (!head)
	{
		head = new;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
}

void	print_lst(t_stack **a, t_stack **b)
{
	t_stack	*it_a;
	t_stack	*it_b;

	it_a = *a;
	it_b = *b;
	ft_printf("---------------------\n");
	while (it_a != NULL || it_b != NULL)
	{
		if (it_a == NULL)
			ft_printf("             ");
		else
		{
			ft_printf("%d         ", it_a->num);
			it_a = it_a->next;
		}
		if (it_b == NULL)
			ft_printf(" \n");
		else
		{
			ft_printf("%d\n", it_b->num);
			it_b = it_b->next;
		}
	}
	ft_printf("^         ^\na         b\n-----------\n");
}

void	free_lst(t_stack **head)
{
	t_stack	*it;

	if (!head)
		return ;
	it = *head;
	while (it)
	{
		*head = (*head)->next;
		free(it);
		it = *head;
	}
}

t_stack	*init_list(int argc, char const *argv[])
{
	t_stack	*head;
	t_stack	*tmp;
	int		i;

	i = 1;
	head = create_new(ft_atoi(argv[i++]));
	while (i < argc)
	{
		tmp = create_new(ft_atoi(argv[i]));
		lst_add(head, tmp);
		i++;
	}
	return (head);
}
