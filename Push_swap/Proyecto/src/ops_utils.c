/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:00 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:28:58 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_swap_top(t_stack *s)
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

void	ft_push_from_to(t_stack *src, t_stack *dst)
{
	t_node	*n;

	n = ft_pop_front(src);
	if (n)
		ft_push_front(dst, n);
}

void	ft_rotate(t_stack *s)
{
	t_node	*n;

	n = ft_pop_front(s);
	if (n)
		ft_push_back(s, n);
}

void	ft_reverse_rotate(t_stack *s)
{
	t_node	*n;

	n = ft_pop_back(s);
	if (n)
		ft_push_front(s, n);
}
