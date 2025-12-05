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
	int             value;
	struct s_node  *next;
	struct s_node  *prev;
}	t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int     size;
}	t_stack;

t_stack *stack_new(void);
t_node  *node_new(int v);
void     stack_clear(t_stack **s);
void push_front(t_stack *s, t_node *n);
void push_back(t_stack *s, t_node *n);
t_node *pop_front(t_stack *s);
t_node *pop_back(t_stack *s);
int   parse_args_into_stack(t_stack *a, int argc, char **argv);
int   already_sorted(t_stack *a);
int   has_duplicates(t_stack *a);
long  ps_atol_strict(const char *s, int *ok);
void  ps_error_and_exit(t_stack *a, t_stack *b);
void op_sa(t_stack *a);
void op_sb(t_stack *b);
void op_ss(t_stack *a, t_stack *b);
void op_pa(t_stack *a, t_stack *b);
void op_pb(t_stack *a, t_stack *b);
void op_ra(t_stack *a);
void op_rb(t_stack *b);
void op_rr(t_stack *a, t_stack *b);
void op_rra(t_stack *a);
void op_rrb(t_stack *b);
void op_rrr(t_stack *a, t_stack *b);
void sort_2(t_stack *a);
void sort_3(t_stack *a);
void sort_5(t_stack *a, t_stack *b);
int  find_min_pos(t_stack *a);
void rotate_pos_to_top(t_stack *a, int pos);
void index_compress(t_stack *a);
void sort_radix(t_stack *a, t_stack *b);
char **split_ws(const char *s, int *count);
void free_split(char **v);
long	ps_atol_strict(const char *s, int *ok);
void	ps_error_and_exit(t_stack *a, t_stack *b);
void    putstr(const char *s);
void    swap_top(t_stack *s);
void    push_from_to(t_stack *src, t_stack *dst);
void    rotate(t_stack *s);
void    reverse_rotate(t_stack *s);
void	run_sort(t_stack *a, t_stack *b);

#endif
