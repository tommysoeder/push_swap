/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:59:52 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:47:08 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_copy_to_array(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*n;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	i = 0;
	n = a->top;
	while (n)
	{
		arr[i] = n->value;
		n = n->next;
		i++;
	}
	return (arr);
}

static void	ft_sort_int_array(int *arr, int n)
{
	int	i;
	int	j;
	int	min_idx;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
		}
		i++;
	}
}

static int	ft_find_index(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	*ft_build_sorted_array(t_stack *a, int *n)
{
	int		*arr;
	int		*sorted;
	int		i;

	*n = a->size;
	arr = ft_copy_to_array(a);
	if (!arr)
		ft_ps_error_and_exit(a, NULL);
	sorted = malloc(sizeof(int) * (*n));
	if (!sorted)
	{
		free(arr);
	ft_ps_error_and_exit(a, NULL);
	}
	i = 0;
	while (i < *n)
	{
		sorted[i] = arr[i];
		i++;
	}
	free(arr);
	ft_sort_int_array(sorted, *n);
	return (sorted);
}

void	ft_index_compress(t_stack *a)
{
	int		n;
	int		*sorted;
	t_node	*node;

	sorted = ft_build_sorted_array(a, &n);
	node = a->top;
	while (node)
	{
		node->value = ft_find_index(sorted, n, node->value);
		node = node->next;
	}
	free(sorted);
}
