/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:41 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/07 17:47:07 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static int	ft_count_tokens(const char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && ft_is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		n++;
		while (s[i] && !ft_is_space(s[i]))
			i++;
	}
	return (n);
}

static char	*ft_substr_dup(const char *s, int start, int len)
{
	char	*out;
	int		i;

	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[len] = '\0';
	return (out);
}

static int	ft_fill_tokens(const char *s, char **vec)
{
	int		i;
	int		tok_i;
	int		start;
	char	*tok;

	i = 0;
	tok_i = 0;
	while (s[i])
	{
		while (s[i] && ft_is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !ft_is_space(s[i]))
			i++;
		tok = ft_substr_dup(s, start, i - start);
		if (!tok)
			return (0);
		vec[tok_i] = tok;
		tok_i++;
	}
	vec[tok_i] = NULL;
	return (1);
}

char	**ft_split_ws(const char *s, int *count)
{
	int		n;
	char	**vec;

	n = ft_count_tokens(s);
	vec = malloc(sizeof(char *) * (n + 1));
	if (!vec)
		return (NULL);
	if (!ft_fill_tokens(s, vec))
	{
		ft_free_split(vec);
		return (NULL);
	}
	if (count)
		*count = n;
	return (vec);
}
