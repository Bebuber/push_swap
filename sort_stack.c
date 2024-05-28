/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:05:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/28 22:23:28 by bebuber          ###   ########.fr       */
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
	if (if_sorted(stack_a) == 1)
		exit (1);
	while (i < ft_lstsize(*stack_a) - 2)
	{
		first_pour(stack_a, stack_b, mid);
		if ((*stack_b)->content < premid)
			rotate(stack_b, "rb");
		i++;
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		first_pour(stack_a, stack_b, find_max(stack_a));
		if ((*stack_b)->content < postmid)
			rotate(stack_b, "rb");
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_a(stack_a);
	while (*stack_b)
		pour_back_from_stack_b(stack_a, stack_b);
	while (if_sorted(stack_a) == 0)
		reverse_rotate(stack_a, "rra");
	test(stack_a, 'a');
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

void	first_pour(t_list **stack_a, t_list **stack_b, int mid)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = ft_lstlast(*stack_a)->content;
	ft_printf("test%d - %d - %d - %d\n", a, b, c, mid);
	test(stack_a, 'a');
	test(stack_b, 'b');
	if (a < b && a < c && a < mid)
		push(stack_a, stack_b, "pb");
	else if (b < a && b < c && b < mid)
	{
		rotate(stack_a, "ra");
		push(stack_a, stack_b, "pb");
	}
	else if (c < a && c < b && c < mid)
	{
		reverse_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
	}
	else
	{
		rotate(stack_a, "ra");
		first_pour(stack_a, stack_b, mid);
	}
	return ;
}

void	pour_back_from_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_b)->content;
	b = a;
	c = b;
	if (ft_lstsize(*stack_b) > 2)
	{
		b = (*stack_b)->next->content;
		c = ft_lstlast(*stack_b)->content;
		if (b > a && b > c)
			rotate(stack_b, "rb");
		else if (c > a && c > b)
			reverse_rotate(stack_b, "rrb");
	}
	a = (*stack_b)->content;
	if (a < (*stack_a)->content && (*stack_a)->content < ft_lstlast(*stack_a)->content)
		push(stack_b, stack_a, "pa");
	else if (a < (*stack_a)->content && (*stack_a)->content > ft_lstlast(*stack_a)->content)
	{
		while ((*stack_a)->content > ft_lstlast(*stack_a)->content && ft_lstlast(*stack_a)->content > a)
			reverse_rotate(stack_a, "rra");
		push(stack_b, stack_a, "pa");
	}
	else if (a > (*stack_a)->content)
	{
		while (a > (*stack_a)->content)
			rotate(stack_a, "ra");
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