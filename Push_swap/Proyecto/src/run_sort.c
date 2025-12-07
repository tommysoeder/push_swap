/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:02:11 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:28:54 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_run_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_sort_2(a);
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size <= 5)
		ft_sort_5(a, b);
	else
	{
		ft_index_compress(a);
		ft_sort_radix(a, b);
	}
}
