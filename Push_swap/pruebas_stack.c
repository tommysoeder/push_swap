#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

int main(void)
{
   t_node *n1 = malloc(sizeof(t_node));
   t_node *n2 = malloc(sizeof(t_node));
   t_node *n3 = malloc(sizeof(t_node));

   n1->value = 10;
   n2->value = 20;
   n3->value = 30;

   n1->next = n2; // el primero apunta al segundo
   n2->next = n3; // el segundo apunta al tercero
   n3->next = NULL; // el tercero apunta a NULL (es el final de la lista)

   // Recorrer l lista
   t_node *tmp = n1;
   while (tmp != NULL)
   {
       printf("Valor: %d\n", tmp->value);
       tmp = tmp->next; // avanzar al siguiente nodo
   }
   return 0;
}

