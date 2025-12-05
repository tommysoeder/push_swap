/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:00 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/05 17:52:03 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	swap_top(t_stack *s)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (!s || s->size < 2)
		return ;
	a = s->top;
	b = a->next;
	c = b->next;
	s->top = b;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
	else
		s->bottom = a;
}

void	push_from_to(t_stack *src, t_stack *dst)
{
	t_node	*n;

	n = pop_front(src);
	if (n)
		push_front(dst, n);
}

void	rotate(t_stack *s)
{
	t_node	*n;

	n = pop_front(s);
	if (n)
		push_back(s, n);
}

void	reverse_rotate(t_stack *s)
{
	t_node	*n;

	n = pop_back(s);
	if (n)
		push_front(s, n);
}
