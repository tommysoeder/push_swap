/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:01:14 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:01:16 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
	}
	else
	{
		n->next = s->top;
		s->top->prev = n;
		s->top = n;
	}
	s->size++;
}

void	push_back(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
	}
	else
	{
		n->prev = s->bottom;
		s->bottom->next = n;
		s->bottom = n;
	}
	s->size++;
}

t_node	*pop_front(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}

t_node	*pop_back(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->bottom;
	s->bottom = n->prev;
	if (s->bottom)
		s->bottom->next = NULL;
	else
		s->top = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}
