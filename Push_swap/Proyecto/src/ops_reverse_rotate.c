/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:08 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:29:36 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_putstr("rra\n");
}

void	ft_op_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	ft_op_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr("rrr\n");
}
