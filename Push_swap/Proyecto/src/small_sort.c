/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:00:19 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:22 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_stack *a)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
	ft_op_sa(a);
}

void	ft_sort_3(t_stack *a)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = a->top->value;
	v2 = a->top->next->value;
	v3 = a->bottom->value;
	if (v1 < v2 && v2 < v3)
		return ;
	if (v1 > v2 && v2 < v3 && v1 < v3)
		ft_op_sa(a);
	else if (v1 > v2 && v2 > v3)
	{
		ft_op_sa(a);
		ft_op_rra(a);
	}
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		ft_op_ra(a);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		ft_op_sa(a);
		ft_op_ra(a);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		ft_op_rra(a);
}

int	ft_find_min_pos(t_stack *a)
{
	int		pos;
	int		best_pos;
	int		best;
	t_node	*node;

	pos = 0;
	best_pos = 0;
	node = a->top;
	best = node->value;
	while (node)
	{
		if (node->value < best)
		{
			best = node->value;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (best_pos);
}

void	ft_rotate_pos_to_top(t_stack *a, int pos)
{
	int	steps;

	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ft_op_ra(a);
			pos--;
		}
	}
	else
	{
		steps = a->size - pos;
		while (steps > 0)
		{
			ft_op_rra(a);
			steps--;
		}
	}
}

void	ft_sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	if (a->size == 4)
	{
		pos = ft_find_min_pos(a);
		ft_rotate_pos_to_top(a, pos);
		ft_op_pb(a, b);
		ft_sort_3(a);
		ft_op_pa(a, b);
	}
	else if (a->size == 5)
	{
		pos = ft_find_min_pos(a);
		ft_rotate_pos_to_top(a, pos);
		ft_op_pb(a, b);
		pos = ft_find_min_pos(a);
		ft_rotate_pos_to_top(a, pos);
		ft_op_pb(a, b);
		ft_sort_3(a);
		if (b->size == 2 && b->top->value < b->top->next->value)
			ft_op_sb(b);
		ft_op_pa(a, b);
		ft_op_pa(a, b);
	}
}
