/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:59:08 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/29 18:21:53 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
//# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//operations.c
void		swap(t_list **stack, char *str);
void		push(t_list	**source, t_list **target, char *str);
void		rotate(t_list	**stack, char *str);
void		reverse_rotate(t_list	**stack, char *str);
void		check_duplicates(t_list **list);
//void		*ft_calloc(size_t count, size_t size);

//lists.c
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstprev(t_list *lst);

//ft_split.c
t_list		*ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_size_cols(const char *s, char c, int n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_count_rows(const char *s, char c);

//push_swap.c
int			main(int argc, char **argv);
void		free_n_exit(t_list **lst);
t_list		*create_stack_a(int argc, char **argv);
int			ft_isdigit(const char *str);
long int	ft_atoi(const char *str);
void		test(t_list **list, char c);

//sort_stack_a.c
void		sort_stack(t_list **stack_a, t_list **stack_b);
int			if_sorted(t_list **list);
void		pour_back_from_stack_b(t_list **stack_a, t_list **stack_b);
void		first_pour(t_list **stack_a, t_list **stack_b, int mid, int check);
int			find_mid(t_list **list);
void		sort_stack_a(t_list **stack_a);
int			find_min(t_list **list);
int			find_max(t_list **list);

//ft_printf.c
int			ft_printf(const char *c, ...);

#endif