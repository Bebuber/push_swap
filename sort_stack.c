/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:05:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/21 16:58:05 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_list **list)
{
	t_list	*copy;
	t_list	*node;

	copy = (*list);
	node = copy;
	while (node)
	{
		copy = node->next;
		while (copy)
		{
			if (node->content == copy->content)
				free_n_exit(&(*list));
			copy = copy->next;
		}
		node = node->next;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		first_pour(stack_a, stack_b);
	while ((*stack_a)->next)
		pour_stack_a(stack_a, stack_b);
	while ((*stack_b)->next)
		pour_back_from_stack_b(stack_a, stack_b);
	if (if_sorted(stack_a) == 1)
	{
		push(stack_b, stack_a, "pa");
		test(stack_a, '0');
		return ;
	}
	if (if_sorted(stack_a) == 0)
		sort_stack(stack_a, stack_b);
}

void	first_pour(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = ft_lstlast(*stack_a)->content;
	if (a < b && a < c)
		push(stack_a, stack_b, "pb");
	else if (b < a && b < c)
	{
		swap(stack_a, "sa");
		push(stack_a, stack_b, "pb");
	}
	else
	{
		reverse_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
	}
}

void	pour_stack_a(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content < (*stack_a)->next->content && \
	(*stack_a)->content < ft_lstlast(*stack_a)->content)
		push(stack_a, stack_b, "pb");
	else if ((*stack_a)->next->content < (*stack_a)->content && \
	(*stack_a)->next->content < ft_lstlast(*stack_a)->content)
	{
		if (((*stack_b)->next) && \
		(*stack_b)->next->content > (*stack_b)->content)
		{
			swap(stack_b, "ss");
			swap(stack_a, NULL);
		}
		else
			swap(stack_a, "sa");
		push(stack_a, stack_b, "pb");
	}
	else
	{
		if (ft_lstlast(*stack_b)->content > (*stack_b)->content)
		{
			reverse_rotate(stack_b, "rrr");
			reverse_rotate(stack_a, NULL);
		}
		else
			reverse_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
	}
}

void	pour_back_from_stack_b(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->content > (*stack_b)->next->content && \
	(*stack_b)->content > ft_lstlast(*stack_b)->content)
		push(stack_b, stack_a, "pa");
	else if ((*stack_b)->next->content > (*stack_b)->content && \
	(*stack_b)->next->content > ft_lstlast(*stack_b)->content)
	{
		if (((*stack_a)->next) && \
		(*stack_a)->next->content < (*stack_a)->content)
		{
			swap(stack_a, "ss");
			swap(stack_b, NULL);
		}
		else
			swap(stack_b, "sb");
		push(stack_b, stack_a, "pa");
	}
	else
	{
		if (ft_lstlast(*stack_a)->content < (*stack_a)->content)
		{
			reverse_rotate(stack_a, "rrr");
			reverse_rotate(stack_b, NULL);
		}
		else
			reverse_rotate(stack_b, "rrb");
		push(stack_b, stack_a, "pa");
	}
}

int	if_sorted(t_list **list)
{
	t_list	*copy;
	t_list	*node;
	int		sorted;

	sorted = 1;
	copy = (*list);
	node = copy->next;
	while (node)
	{
		if (node->content < copy->content)
		{
			sorted = 0;
			break ;
		}
		copy = copy->next;
		node = copy->next;
	}
	return (sorted);
}
