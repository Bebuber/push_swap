/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:22:10 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/31 17:02:27 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_pour(t_list **stack_a, t_list **stack_b, int mid, int check)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = ft_lstlast(*stack_a)->content;
	if (a < b && a < c && a < mid)
	{
		if ((*stack_b) && (*stack_b)->content < check)
			rotate(stack_b, "rb");
		push(stack_a, stack_b, "pb");
	}
	else if (b < a && b < c && b < mid)
		division1(stack_a, stack_b, mid, check);
	else if (c < a && c < b && c < mid)
	{
		if ((*stack_b) && (*stack_b)->content < check)
			rotate(stack_b, "rb");
		reverse_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
	}
	else
		division2(stack_a, stack_b, mid, check);
	return ;
}

void	division1(t_list **stack_a, t_list **stack_b, int mid, int check)
{
	int	a;

	a = (*stack_a)->content;
	if (ft_lstsize(*stack_b) < ft_lstsize(*stack_a) && (a < mid))
	{
		if ((*stack_b) && (*stack_b)->content < check)
			rotate(stack_b, "rb");
		swap(stack_a, "sa");
	}
	else if ((*stack_b) && (*stack_b)->content < check)
	{
		rotate(stack_b, NULL);
		rotate(stack_a, "rr");
	}
	else
		rotate(stack_a, "ra");
	push(stack_a, stack_b, "pb");
	return ;
}

void	division2(t_list **stack_a, t_list **stack_b, int mid, int check)
{
	if ((*stack_b) && (*stack_b)->content < check)
	{
		rotate(stack_b, NULL );
		rotate(stack_a, "rr");
	}
	else
		rotate(stack_a, "ra");
	first_pour(stack_a, stack_b, mid, check);
	return ;
}

void	arange_stack_b(t_list **stack_b)
{
	while ((*stack_b)->next->content > (*stack_b)->content && \
		(*stack_b)->next->content > ft_lstlast(*stack_b)->content)
	{
		if ((*stack_b)->content > (*stack_b)->next->next->content)
		{
			swap(stack_b, "sb");
			break ;
		}
		rotate(stack_b, "rb");
	}
	while (ft_lstlast(*stack_b)->content > (*stack_b)->content && \
	ft_lstlast(*stack_b)->content > (*stack_b)->next->content)
		reverse_rotate(stack_b, "rrb");
}

void	pour_back_from_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	a;

	if (ft_lstsize(*stack_b) > 2)
		arange_stack_b(stack_b);
	a = (*stack_b)->content;
	if (a < (*stack_a)->content && \
	(*stack_a)->content < ft_lstlast(*stack_a)->content)
		push(stack_b, stack_a, "pa");
	else if (a < (*stack_a)->content && \
	(*stack_a)->content > ft_lstlast(*stack_a)->content)
	{
		while ((*stack_a)->content > ft_lstlast(*stack_a)->content && \
		ft_lstlast(*stack_a)->content > a)
			reverse_rotate(stack_a, "rra");
		push(stack_b, stack_a, "pa");
	}
	else if (a > (*stack_a)->content)
	{
		while (a > (*stack_a)->content)
			rotate(stack_a, "ra");
		push(stack_b, stack_a, "pa");
	}
	return ;
}
