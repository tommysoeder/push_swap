/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:44 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:46 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a)
{
	swap_top(a);
	putstr("sa\n");
}

void	op_sb(t_stack *b)
{
	swap_top(b);
	putstr("sb\n");
}

void	op_ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	putstr("ss\n");
}

void	op_pa(t_stack *a, t_stack *b)
{
	push_from_to(b, a);
	putstr("pa\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	push_from_to(a, b);
	putstr("pb\n");
}
