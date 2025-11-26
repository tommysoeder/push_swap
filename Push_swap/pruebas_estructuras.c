#include <stdio.h>
#include <stdlib.h>
// typedef struct s_jugadora
// {
//     char *name;
//     char *shoots;
//     int age;
//     int jersey_number;
// }t_jugadora;

// int main(void)
// {
//     t_jugadora vega;
//     t_jugadora vega_loven = {"Vega Muñoz", "Left", 24, 32};

//     vega.name = "Vega Muñoz";
//     vega.shoots = "Left";
//     vega.age = 26;
//     vega.jersey_number = 7;

//     printf("Name: %s\n", vega.name);
//     printf("Shoots: %s\n", vega.shoots);
//     printf("Age: %d\n", vega.age);
//     printf("Jersey nummber: %d\n", vega.jersey_number);
//     printf("Age in Björklöven: %d\n", vega_loven.age);
//     printf("Jersey nummber in Björklöven: %d\n", vega_loven.jersey_number);
//     return 0;
// }

typedef struct s_node{
    int value;
    struct s_node *prev;
    struct s_node *next;
}t_node;

typedef struct mi_stack{
    t_node *top;
    t_node *bottom;
    int size;
}t_stack;

t_stack *init_stack(void){
    t_stack *s = malloc(sizeof(t_stack));
    if(!s)
        return NULL;
    s->top = NULL;
    s->bottom = NULL;
    s->size = 0;
    return s;
}

t_node *new_node(int v)
{
    t_node *n = malloc(sizeof(t_node));
    if (!n)
        return NULL;
    n->value = v;
    n->next = NULL;
    n->prev = NULL;
    return n;
}



int main(void)
{
    t_stack *a = init_stack();
    t_node *n1 = new_node(97);
    t_node *n2 = new_node(32);
    t_node *n3 = new_node(92);

    a->top = n1;
    a->bottom = n3;
    a->size = 3;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    // t_stack *stack = init_stack();
    if(!a)
        return 1;
    printf("Stack initialized. Size: %d\n", a->size);
    printf("Top: %d\n", a->top->value);
    printf("Middle: %d\n", a->top->next->value);
    printf("Bottom: %d\n", a->bottom->value);
    return 0;
}