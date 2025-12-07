/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:44 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:29:35 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_sa(t_stack *a)
{
	ft_swap_top(a);
	ft_putstr("sa\n");
}

void	ft_op_sb(t_stack *b)
{
	ft_swap_top(b);
	ft_putstr("sb\n");
}

void	ft_op_ss(t_stack *a, t_stack *b)
{
	ft_swap_top(a);
	ft_swap_top(b);
	ft_putstr("ss\n");
}

void	ft_op_pa(t_stack *a, t_stack *b)
{
	ft_push_from_to(b, a);
	ft_putstr("pa\n");
}

void	ft_op_pb(t_stack *a, t_stack *b)
{
	ft_push_from_to(a, b);
	ft_putstr("pb\n");
}
