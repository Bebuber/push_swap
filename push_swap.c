/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:05:33 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/20 17:46:54 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		printf("%s\n", argv[0]);
	else if (argc == 2)
		stack_a = ft_split(argv[1], ' ');
	else
		stack_a = create_stack_a((--argc), (++argv));
	test(&stack_a);
	return (0);
}

int	ft_isdigit(const char *str)
{
	int	i;
	int	n;
	int	if_true;

	i = 0;
	if_true = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	n = i;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '\0' && (i - n <= 10))
			if_true = 1;
	}
	return (if_true);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			ngt;
	long int	numb;

	i = 0;
	ngt = 1;
	numb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ngt = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = numb * 10;
		numb = numb + (str[i] - '0');
		i++;
	}
	return (numb * ngt);
}

t_list	*create_stack_a(int argc, char **argv)
{
	t_list		*list;
	t_list		*new_node;
	long int	number;
	int			i;

	i = 0;
	number = 0;
	list = NULL;
	while (i < argc)
	{
		if (ft_isdigit(argv[i]) == -1)
			free_n_exit(&list);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_n_exit(&list);
		new_node = ft_lstnew(number);
		ft_lstadd_back(&list, new_node);
		i++;
	}
	return (list);
}

void	free_n_exit(t_list **lst)
{
	t_list	*temp;

	printf ("Error\n");
	while (*lst)
	{
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	*lst = NULL;
	exit (1);
}

//void	test(t_list **list)
//{
//	t_list	*tmp;

//	while (*list)
//	{
//		tmp = (*list);
//		printf("%d\n", (*list)->content);
//		*list = tmp->next;
//	}
//}