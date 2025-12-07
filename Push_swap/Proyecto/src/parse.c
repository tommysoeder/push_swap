/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:00:04 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:06 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_process_tokens(t_stack *a, char **toks, int tokc)
{
	int		t;
	int		ok;
	long	num;
	t_node	*n;

	t = 0;
	while (t < tokc)
	{
	num = ft_ps_atol_strict(toks[t], &ok);
		if (!ok)
			return (0);
	n = ft_node_new((int)num);
		if (!n)
			return (0);
	ft_push_back(a, n);
		t++;
	}
	return (1);
}

int	ft_parse_args_into_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	int		tokc;
	char	**toks;

	i = 1;
	while (i < argc)
	{
		toks = ft_split_ws(argv[i], &tokc);
		if (!toks || tokc == 0)
		{
			ft_free_split(toks);
			return (0);
		}
		if (!ft_process_tokens(a, toks, tokc))
		{
			ft_free_split(toks);
			return (0);
		}
		ft_free_split(toks);
		i++;
	}
	if (ft_has_duplicates(a))
		return (0);
	return (1);
}
