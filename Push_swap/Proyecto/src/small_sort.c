#include "push_swap.h"

static int top_v(t_stack *a) { return a->top->value; }
static int mid_v(t_stack *a) { return a->top->next->value; }
static int bot_v(t_stack *a) { return a->bottom->value; }

void sort_2(t_stack *a)
{
	if (a->size == 2 && top_v(a) > mid_v(a))
		op_sa(a);
}

void sort_3(t_stack *a)
{
	int A = top_v(a), B = mid_v(a), C = bot_v(a);

	if (A < B && B < C) return;
	if (A > B && B < C && A < C) op_sa(a);                
	else if (A > B && B > C) { op_sa(a); op_rra(a); }     
	else if (A > B && B < C && A > C) op_ra(a);           
	else if (A < B && B > C && A < C) { op_sa(a); op_ra(a);} 
	else if (A < B && B > C && A > C) op_rra(a);           
}

int find_min_pos(t_stack *a)
{
	int pos = 0, best_pos = 0;
	int best = a->top->value;
	for (t_node *n = a->top; n; n = n->next, ++pos)
	{
		if (n->value < best) { best = n->value; best_pos = pos; }
	}
	return best_pos;
}

void rotate_pos_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos-- > 0) op_ra(a);
	else
	{
		int steps = a->size - pos;
		while (steps-- > 0) op_rra(a);
	}
}

void sort_5(t_stack *a, t_stack *b)
{
	int pos;

	pos = find_min_pos(a);
	rotate_pos_to_top(a, pos);
	op_pb(a, b);

	pos = find_min_pos(a);
	rotate_pos_to_top(a, pos);
	op_pb(a, b);


	sort_3(a);

	if (b->size == 2 && b->top->value < b->top->next->value)
		op_sb(b);

	op_pa(a, b);
	op_pa(a, b);
}
