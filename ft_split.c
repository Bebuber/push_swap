/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:17:33 by bebuber           #+#    #+#             */
/*   Updated: 2024/05/20 17:39:47 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_cols(const char *s, char c, int n)
{
	int	size;

	size = 0;
	while (s[n] != c && s[n])
	{
		size ++;
		n++;
	}
	return (size);
}

int	ft_count_rows(const char *s, char c)
{
	int	rows;
	int	n;

	n = 0;
	rows = 0;
	while (s[n] != '\0')
	{
		if (n == 0 && s[n] != c && s[n] != 0)
		{
			rows++;
			n++;
		}
		else if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
		{
			rows++;
			n++;
		}
		else
			n++;
	}
	return (rows);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c1;
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	if (len == 0 || start >= n)
	{
		c1 = (char *)malloc(1);
		if (c1 == NULL)
			return (NULL);
		c1[0] = '\0';
		return (c1);
	}
	if (n - start < len)
		len = n - start;
	c1 = (char *)malloc(len + 1);
	if (c1 == NULL)
		return (NULL);
	s = s + start;
	if (len != 0)
		ft_strlcpy(c1, s, len + 1);
	return (c1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (src[i] != 0)
		i++;
	if (dest == 0 || size == 0)
		return (i);
	while ((s < size - 1) && (src[s] != 0))
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = 0;
	return (i);
}

t_list	*ft_split(char const *s, char c)
{
	char		**arr;
	int			rows;
	long int	size;
	int			n;
	int			p;

	n = 0;
	p = 0;
	rows = ft_count_rows(s, c);
	arr = (char **)malloc((rows + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (p < rows)
	{
		while (s[n] == c)
			n++;
		size = ft_size_cols(s, c, n);
		arr[p] = ft_substr(s, n, size);
		n += size;
		p++;
	}
	arr[p] = 0;
	return (create_stack_a(rows, arr));
}

//int	main(void)
//{
//	char	**arr;
//	int		n;
//	int		i;
//	char	const *s = "hello!zzzzzzzz";
//	char	c = 'z';

//	n = 0;
//	i = 0;
//	arr = ft_split(s, c);
//	while (arr[n])
//	{
//		while (arr[n][i])
//		{
//			printf ("arr[%d] [%d] = %c \n",n,i, arr[n][i]);
//			i++;
//		}
//		n++;
//		i = 0;
//	}
//	return (0);
//}
