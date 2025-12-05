/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:25 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:29 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a)
{
	rotate(a);
	putstr("ra\n");
}

void	op_rb(t_stack *b)
{
	rotate(b);
	putstr("rb\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	putstr("rr\n");
}
