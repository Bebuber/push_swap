/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:59:08 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/20 17:39:28 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//operations.c
void		swap(t_list **stack);
void		push(t_list	**stack_a, t_list **stack_b);
void		rotate(t_list	**stack);
void		reverse_rotate(t_list	**stack);
void		*ft_calloc(size_t count, size_t size);

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
void		test(t_list **list);
int			ft_isdigit(const char *str);
long int	ft_atoi(const char *str);

#endif