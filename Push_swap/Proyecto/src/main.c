/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:59:35 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 15:59:37 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_stack *a, t_stack *b)
{
	if (already_sorted(a))
		return ;
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
	{
		index_compress(a);
		sort_radix(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = stack_new();
	b = stack_new();
	if (!a || !b)
		ps_error_and_exit(a, b);
	if (!parse_args_into_stack(a, argc, argv))
		ps_error_and_exit(a, b);
	run_sort(a, b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
