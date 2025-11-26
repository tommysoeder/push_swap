#include "push_swap.h"

long ps_atol_strict(const char *s, int *ok)
{
    long sign = 1;
    long res = 0;
    int  i = 0;

    *ok = 0;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-') sign = -1;
        i++;
    }
    if (s[i] == '\0')
        return 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        res = res * 10 + (s[i] - '0');
        if (sign == 1 && res > (long)INT_MAX) return 0;
        if (sign == -1 && -res < (long)INT_MIN) return 0;
        i++;
    }
    *ok = 1;
    return res * sign;
}

void ps_error_and_exit(t_stack *a, t_stack *b)
{
    if (a) stack_clear(&a);
    if (b) stack_clear(&b);
    write(2, "Error\n", 6);
    _exit(1);
}

int has_duplicates(t_stack *a)
{
    for (t_node *i = a->top; i; i = i->next)
        for (t_node *j = i->next; j; j = j->next)
            if (j->value == i->value)
                return 1;
    return 0;
}

int already_sorted(t_stack *a)
{
    for (t_node *n = a->top; n && n->next; n = n->next)
        if (n->value > n->next->value)
            return 0;
    return 1;
}

static int is_space(char c)
{
    return (c==' '||c=='\t'||c=='\n'||c=='\r'||c=='\v'||c=='\f');
}

static char *substr_dup(const char *s, int start, int len)
{
    char *out = (char *)malloc(len + 1);
    if (!out) return NULL;
    for (int i=0; i<len; ++i) out[i] = s[start + i];
    out[len] = '\0';
    return out;
}

static char **split_ws(const char *s, int *count)
{
    int i = 0, n = 0, cap = 8;
    char **vec = (char **)malloc(sizeof(char*) * cap);
    if (!vec) return NULL;

    while (s[i])
    {
        while (s[i] && is_space(s[i])) i++;
        if (!s[i]) break;
        int start = i;
        while (s[i] && !is_space(s[i])) i++;
        int len = i - start;

        char *tok = substr_dup(s, start, len);
        if (!tok) { for (int k=0;k<n;++k) free(vec[k]); free(vec); return NULL; }

        if (n == cap) {
            cap *= 2;
            char **tmp = (char **)realloc(vec, sizeof(char*) * cap);
            if (!tmp) { for (int k=0;k<n;++k) free(vec[k]); free(vec); free(tok); return NULL; }
            vec = tmp;
        }
        vec[n++] = tok;
    }
    char **res = (char **)realloc(vec, sizeof(char*) * (n + 1));
    if (!res) { vec[n] = NULL; if (count) *count = n; return vec; }
    res[n] = NULL;
    if (count) *count = n;
    return res;
}

static void free_split(char **v)
{
    if (!v) return;
    for (int i=0; v[i]; ++i) free(v[i]);
    free(v);
}

int parse_args_into_stack(t_stack *a, int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int tokc = 0, ok;
        char **toks = split_ws(argv[i], &tokc);
        if (!toks) return 0;
        if (tokc == 0) { free_split(toks); return 0; }

        for (int t = 0; t < tokc; ++t)
        {
            long num = ps_atol_strict(toks[t], &ok);
            if (!ok) { free_split(toks); return 0; }
            t_node *n = node_new((int)num);
            if (!n) { free_split(toks); return 0; }
            push_back(a, n);
        }
        free_split(toks);
    }
    if (has_duplicates(a)) return 0;
    return 1;
}
