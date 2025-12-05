/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:52:41 by tomamart          #+#    #+#             */
/*   Updated: 2025/12/05 17:52:44 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_split
{
	int		i;
	int		count;
	int		start;
	char	**vec;
}	t_split;

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static char	*substr_dup(const char *s, int start, int len)
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

void	free_split(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

static int	add_token(t_split *st, const char *s)
{
	char	*tok;
	char	**tmp;
	int		len;
	int		j;

	len = st->i - st->start;
	tok = substr_dup(s, st->start, len);
	if (!tok)
		return (0);
	tmp = malloc(sizeof(char *) * (st->count + 2));
	if (!tmp)
	{
		free(tok);
		return (0);
	}
	j = 0;
	while (j < st->count)
	{
		tmp[j] = st->vec[j];
		j++;
	}
	tmp[st->count] = tok;
	tmp[st->count + 1] = NULL;
	free(st->vec);
	st->vec = tmp;
	st->count++;
	return (1);
}

char	**split_ws(const char *s, int *count)
{
	t_split	st;

	st.i = 0;
	st.count = 0;
	st.vec = NULL;
	while (s[st.i])
	{
		while (s[st.i] && is_space(s[st.i]))
			st.i++;
		if (!s[st.i])
			break ;
		st.start = st.i;
		while (s[st.i] && !is_space(s[st.i]))
			st.i++;
		if (!add_token(&st, s))
		{
			free_split(st.vec);
			return (NULL);
		}
	}
	if (!st.vec)
	{
		st.vec = malloc(sizeof(char *));
		if (!st.vec)
			return (NULL);
		st.vec[0] = NULL;
	}
	if (count)
		*count = st.count;
	return (st.vec);
}
