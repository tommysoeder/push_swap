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

static void	start_push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_new();
	b = stack_new();
	if (!a || !b)
		ps_error_and_exit(a, b);
	if (!parse_args_into_stack(a, argc, argv))
		ps_error_and_exit(a, b);
	if (!already_sorted(a))
		run_sort(a, b);
	stack_clear(&a);
	stack_clear(&b);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	start_push_swap(argc, argv);
	return (0);
}
