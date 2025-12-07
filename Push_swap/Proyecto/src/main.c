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

static void	ft_run_sort(t_stack *a, t_stack *b)
{
	if (ft_already_sorted(a))
		return ;
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = ft_stack_new();
	b = ft_stack_new();
	if (!a || !b)
		ft_ps_error_and_exit(a, b);
	if (!ft_parse_args_into_stack(a, argc, argv))
		ft_ps_error_and_exit(a, b);
	ft_run_sort(a, b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
