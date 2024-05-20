/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:33 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/18 18:33:45 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*new;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	new = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	new->next = (*stack);
	*stack = new;
}

void	push(t_list	**stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	*stack_b = (*stack_a);
	*stack_a = tmp;
}

void	rotate(t_list	**stack)
{
	t_list	*tmp;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	reverse_rotate(t_list	**stack)
{
	t_list	*tmp;
	t_list	*prev;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	tmp = ft_lstlast(*stack);
	prev = ft_lstprev(*stack);
	tmp->next = (*stack);
	*stack = tmp;
	prev->next = NULL;
}

//int main(void)
//{
//	t_list	*stack;
//	//t_list	*stack_b;
//	t_list	*temp;
//	t_list	*new;
//	int		i;

//	void	leaks()
//	{
//		system("leaks push_swap.a");
//	}
//	atexit(leaks);	
//	stack = NULL;
//	//stack_b = NULL;
//	i = 0;
//	while (i < 5)
//	{
//		new = ft_lstnew(i);
//		ft_lstadd_back(&stack, new);
//		i++;
//	}

//	temp = stack;
//	while (temp)
//	{
//		printf("%d\n", temp->content);
//		temp = temp->next;
//	}
//	//push(&stack, &stack_b);
//	//swap(stack);
//	//rotate(&stack);
//	//reverse_rotate(&stack);

//	printf("---------------\n");

//	temp = stack;
//	while (temp)
//	{
//		printf("%d\n", temp->content);
//		temp = temp->next;
//	}
//	return (0);
//}