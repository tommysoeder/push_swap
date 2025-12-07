/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:20 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:47:08 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_init_sign(const char *s, int *i, long *sign)
{
	*sign = 1;
	*i = 0;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (s[*i] == '\0')
		return (0);
	return (1);
}

static int	ft_check_overflow(long res, long sign)
{
	if (sign == 1 && res > (long)INT_MAX)
		return (0);
	if (sign == -1 && res < (long)INT_MIN)
		return (0);
	return (1);
}

long	ft_ps_atol_strict(const char *s, int *ok)
{
	long	sign;
	long	res;
	int		i;

	*ok = 0;
	res = 0;
	if (!ft_init_sign(s, &i, &sign))
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		res = res * 10 + (s[i] - '0');
	if (!ft_check_overflow(res, sign))
			return (0);
		i++;
	}
	*ok = 1;
	return (res * sign);
}

void	ft_ps_error_and_exit(t_stack *a, t_stack *b)
{
	if (a)
	ft_stack_clear(&a);
	if (b)
	ft_stack_clear(&b);
	write(2, "Error\n", 6);
	_exit(1);
}
