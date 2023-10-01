#include "sort.h"

/**
  * insertion_sort_list - Sort the elements of the list and call print_list.
  * @list: The list to be sorted.
  */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *next;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (current = (*list)->next; current != NULL; current = next)
{
next = current->next;
prev = current->prev;
while (prev && prev->n > current->n)
{
prev->next = current->next;
if (current->next)
current->next->prev = prev;
current->next = prev;
current->prev = prev->prev;
prev->prev = current;
if (current->prev)
current->prev->next = current;
else
*list = current;
prev = current->prev;
print_list(*list);
}
}
}
