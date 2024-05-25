/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:05:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/25 18:15:52 by bebuber          ###   ########.fr       */
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
	int	mid;

	mid = find_mid(stack_a);
	if (if_sorted(stack_a) == 1)
		exit (1);
	while (ft_lstsize(*stack_a) > 3)
		first_pour(stack_a, stack_b, mid);
	//test(stack_a, 'a');
	//ft_printf("test\n");
	if (ft_lstsize(*stack_a) == 3)
		sort_stack_a(stack_a);
	//test(stack_a, 'a');
	//test(stack_b, 'b');
	while (*stack_b)
		pour_back_from_stack_b(stack_a, stack_b);
	//test(stack_a, 'a');
	while (if_sorted(stack_a) == 0)
		reverse_rotate(stack_a, "rra");
	test(stack_a, 'a');
}

int	find_mid(t_list **list)
{
	t_list	*copy;
	int		max;
	int		min;
	int		mid;

	copy = (*list);
	max = 0;
	min = copy->content;
	while (copy)
	{
		if (copy->content > max)
			max = copy->content;
		if (copy->content < min)
			min = copy->content;
		copy = copy->next;
	}
	mid = (max + min) / 2;
	return (mid);
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
		if(a > b && a > c)
			rotate(stack_a, "ra");
		else if(b > a && b > c)
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
	if (a < b && a < c)
		push(stack_a, stack_b, "pb");
	else if (b < a && b < c)
	{
		rotate(stack_a, "ra");
		push(stack_a, stack_b, "pb");
	}
	else
	{
		reverse_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
	}
	//push(stack_a, stack_b, "pb");
	if ((*stack_b)->content < mid)
		rotate(stack_b, "rb");
}

//void	pour_stack_a(t_list **stack_a, t_list **stack_b)
//{
//	if ((*stack_a)->content < (*stack_a)->next->content && \
//	(*stack_a)->content < ft_lstlast(*stack_a)->content)
//		push(stack_a, stack_b, "pb");
//	else if ((*stack_a)->next->content < (*stack_a)->content && \
//	(*stack_a)->next->content < ft_lstlast(*stack_a)->content)
//	{
//		if (((*stack_b)->next) && \
//		(*stack_b)->next->content > (*stack_b)->content)
//		{
//			swap(stack_b, "ss");
//			swap(stack_a, NULL);
//		}
//		else
//			swap(stack_a, "sa");
//		push(stack_a, stack_b, "pb");
//	}
//	else
//	{
//		if (ft_lstlast(*stack_b)->content > (*stack_b)->content)
//		{
//			reverse_rotate(stack_b, "rrr");
//			reverse_rotate(stack_a, NULL);
//		}
//		else
//			reverse_rotate(stack_a, "rra");
//		push(stack_a, stack_b, "pb");
//	}
//}

void	pour_back_from_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	a;
	//int	b;
	//int	c;

	a = (*stack_b)->content;
	//b = (*stack_b)->next->content;
	//c = ft_lstlast(*stack_b)->content;
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
