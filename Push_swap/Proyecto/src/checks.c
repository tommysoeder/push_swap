/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:50:36 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:29:34 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_has_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (j->value == i->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_already_sorted(t_stack *a)
{
	t_node	*n;

	n = a->top;
	while (n && n->next)
	{
		if (n->value > n->next->value)
			return (0);
		n = n->next;
	}
	return (1);
}
