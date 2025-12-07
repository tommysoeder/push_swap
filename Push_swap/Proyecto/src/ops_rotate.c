/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:25 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:29:35 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_ra(t_stack *a)
{
	ft_rotate(a);
	ft_putstr("ra\n");
}

void	ft_op_rb(t_stack *b)
{
	ft_rotate(b);
	ft_putstr("rb\n");
}

void	ft_op_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr("rr\n");
}
