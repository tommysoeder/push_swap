/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:00:32 by tomamart          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:34 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *copy_to_array(t_stack *a)
{
    int *arr = (int *)malloc(sizeof(int) * a->size);
    int i = 0;
    if (!arr) return NULL;
    for (t_node *n = a->top; n; n = n->next)
        arr[i++] = n->value;
    return arr;
}

static void iswap(int *x, int *y){ int t=*x; *x=*y; *y=t; }
static int  part(int *a, int l, int r){
    int p=a[r], i=l;
    for (int j=l; j<r; ++j) if (a[j] < p){ iswap(&a[i], &a[j]); i++; }
    iswap(&a[i], &a[r]); return i;
}
static void qsort_int(int *a, int l, int r){
    if (l < r){ int m = part(a, l, r); qsort_int(a, l, m-1); qsort_int(a, m+1, r); }
}

static int bsearch_index(int *sorted, int n, int value)
{
    int lo=0, hi=n-1;
    while (lo <= hi){
        int mid=(lo+hi)/2;
        if (sorted[mid]==value) return mid;
        else if (sorted[mid] < value) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

void index_compress(t_stack *a)
{
    int n = a->size;
    int *arr = copy_to_array(a);
    int *sorted;

    if (!arr) ps_error_and_exit(a, NULL);
    sorted = (int *)malloc(sizeof(int)*n);
    if (!sorted){ free(arr); ps_error_and_exit(a, NULL); }

    for (int i=0;i<n;++i) sorted[i]=arr[i];
    qsort_int(sorted, 0, n-1);

    for (t_node *node = a->top; node; node=node->next)
        node->value = bsearch_index(sorted, n, node->value);

    free(arr);
    free(sorted);
}

static int max_bits(t_stack *a)
{
    int max=0, bits=0;
    for (t_node *n=a->top; n; n=n->next)
        if (n->value > max) max = n->value;
    while ((max >> bits) != 0) bits++;
    return bits;
}

void sort_radix(t_stack *a, t_stack *b)
{
    int bits = max_bits(a);

    for (int i=0; i<bits; ++i)
    {
        int count = a->size;
        while (count--)
        {
            int v = a->top->value;
            if (((v >> i) & 1) == 0)
                op_pb(a, b);
            else
                op_ra(a);
        }
        while (b->size)
            op_pa(a, b);
    }
}
