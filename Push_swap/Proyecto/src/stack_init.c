/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:00:55 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:58 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	return (s);
}

t_node	*node_new(int v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = v;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

void	stack_clear(t_stack **s)
{
	t_node	*cur;
	t_node	*next;

	if (!s || !*s)
		return ;
	cur = (*s)->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(*s);
	*s = NULL;
}
