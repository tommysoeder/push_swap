#include "push_swap.h"

static void putstr(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void swap_top(t_stack *s)
{
	t_node *a, *b, *c;

	if (!s || s->size < 2)
		return;
	a = s->top;
	b = a->next;
	c = b->next;
	s->top = b;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
	else
		s->bottom = a;
}

static void push_from_to(t_stack *src, t_stack *dst)
{
	t_node *n = pop_front(src);
	if (n)
		push_front(dst, n);
}

static void rotate(t_stack *s)
{
	t_node *n = pop_front(s);
	if (n)
		push_back(s, n);
}

static void reverse_rotate(t_stack *s)
{
	t_node *n = pop_back(s);
	if (n)
		push_front(s, n);
}

void op_sa(t_stack *a) { swap_top(a); putstr("sa\n"); }
void op_sb(t_stack *b) { swap_top(b); putstr("sb\n"); }
void op_ss(t_stack *a, t_stack *b) { swap_top(a); swap_top(b); putstr("ss\n"); }

void op_pa(t_stack *a, t_stack *b) { push_from_to(b, a); putstr("pa\n"); }
void op_pb(t_stack *a, t_stack *b) { push_from_to(a, b); putstr("pb\n"); }

void op_ra(t_stack *a) { rotate(a); putstr("ra\n"); }
void op_rb(t_stack *b) { rotate(b); putstr("rb\n"); }
void op_rr(t_stack *a, t_stack *b) { rotate(a); rotate(b); putstr("rr\n"); }

void op_rra(t_stack *a) { reverse_rotate(a); putstr("rra\n"); }
void op_rrb(t_stack *b) { reverse_rotate(b); putstr("rrb\n"); }
void op_rrr(t_stack *a, t_stack *b) { reverse_rotate(a); reverse_rotate(b); putstr("rrr\n"); }
