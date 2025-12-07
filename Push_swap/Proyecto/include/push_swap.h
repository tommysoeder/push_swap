/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:58:47 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 15:58:50 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

t_stack	*ft_stack_new(void);
t_node	*ft_node_new(int v);
void	ft_stack_clear(t_stack **s);
void	ft_push_front(t_stack *s, t_node *n);
void	ft_push_back(t_stack *s, t_node *n);
t_node	*ft_pop_front(t_stack *s);
t_node	*ft_pop_back(t_stack *s);
int		ft_parse_args_into_stack(t_stack *a, int argc, char **argv);
int		ft_already_sorted(t_stack *a);
int		ft_has_duplicates(t_stack *a);
long	ft_ps_atol_strict(const char *s, int *ok);
void	ft_ps_error_and_exit(t_stack *a, t_stack *b);
void	ft_op_sa(t_stack *a);
void	ft_op_sb(t_stack *b);
void	ft_op_ss(t_stack *a, t_stack *b);
void	ft_op_pa(t_stack *a, t_stack *b);
void	ft_op_pb(t_stack *a, t_stack *b);
void	ft_op_ra(t_stack *a);
void	ft_op_rb(t_stack *b);
void	ft_op_rr(t_stack *a, t_stack *b);
void	ft_op_rra(t_stack *a);
void	ft_op_rrb(t_stack *b);
void	ft_op_rrr(t_stack *a, t_stack *b);
void	ft_sort_2(t_stack *a);
void	ft_sort_3(t_stack *a);
void	ft_sort_5(t_stack *a, t_stack *b);
int		ft_find_min_pos(t_stack *a);
void	ft_rotate_pos_to_top(t_stack *a, int pos);
void	ft_index_compress(t_stack *a);
void	ft_sort_radix(t_stack *a, t_stack *b);
char	**ft_split_ws(const char *s, int *count);
void	ft_free_split(char **v);
long	ft_ps_atol_strict(const char *s, int *ok);
void	ft_ps_error_and_exit(t_stack *a, t_stack *b);
void	ft_putstr(const char *s);
void	ft_swap_top(t_stack *s);
void	ft_push_from_to(t_stack *src, t_stack *dst);
void	ft_rotate(t_stack *s);
void	ft_reverse_rotate(t_stack *s);
void	ft_index_compress(t_stack *a);
void	ft_sort_radix(t_stack *a, t_stack *b);

#endif
