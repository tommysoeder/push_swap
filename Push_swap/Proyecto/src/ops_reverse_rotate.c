/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:51:08 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:10 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a)
{
	reverse_rotate(a);
	putstr("rra\n");
}

void	op_rrb(t_stack *b)
{
	reverse_rotate(b);
	putstr("rrb\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	putstr("rrr\n");
}
