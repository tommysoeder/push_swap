/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:00:32 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:34 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(t_stack *a)
{
	t_node	*n;
	int		max;
	int		bits;

	max = 0;
	n = a->top;
	while (n)
	{
		if (n->value > max)
			max = n->value;
		n = n->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	bits;
	int	count;
	int	value;

	bits = ft_max_bits(a);
	i = 0;
	while (i < bits)
	{
		count = a->size;
		while (count > 0)
		{
			value = a->top->value;
			if (((value >> i) & 1) == 0)
				ft_op_pb(a, b);
			else
				ft_op_ra(a);
			count--;
		}
		while (b->size > 0)
			ft_op_pa(a, b);
		i++;
	}
}
