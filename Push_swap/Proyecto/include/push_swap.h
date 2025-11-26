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

#endif
