/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:05:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/02 23:14:51 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	mid;
	int	premid;
	int	postmid;
	int	i;

	i = 1;
	mid = (find_max(stack_a) + find_min(stack_a)) / 2;
	premid = (mid + find_min(stack_a)) / 2;
	postmid = (mid + find_max(stack_a)) / 2;
	while (ft_lstsize(*stack_b) < ft_lstsize(*stack_a) - 2 \
	&& ft_lstsize(*stack_a) > 3)
		first_pour(stack_a, stack_b, mid, premid);
	while (ft_lstsize(*stack_b) / 3 + 2 < \
	ft_lstsize(*stack_a) && ft_lstsize(*stack_a) > 3)
		first_pour(stack_a, stack_b, postmid, find_min(stack_b));
	while (ft_lstsize(*stack_a) > 3)
		first_pour(stack_a, stack_b, find_max(stack_a), find_min(stack_b));
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_a(stack_a);
	while (*stack_b)
		pour_back_from_stack_b(stack_a, stack_b);
	while (if_sorted(stack_a) == 0)
		reverse_rotate(stack_a, "rra");
}

void	sort_stack_a(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (if_sorted(stack_a) == 0)
	{
		if (a > b && a > c)
			rotate(stack_a, "ra");
		else if (b > a && b > c)
			reverse_rotate(stack_a, "rra");
		else if (c > b && c > a)
			swap(stack_a, "sa");
		sort_stack_a(stack_a);
	}
	return ;
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

int	find_min(t_list **list)
{
	t_list	*copy;
	int		min;

	copy = (*list);
	min = copy->content;
	while (copy)
	{
		if (copy->content < min)
			min = copy->content;
		copy = copy->next;
	}
	return (min);
}

int	find_max(t_list **list)
{
	t_list	*copy;
	int		max;

	copy = (*list);
	max = copy->content;
	while (copy)
	{
		if (copy->content > max)
			max = copy->content;
		copy = copy->next;
	}
	return (max);
}
