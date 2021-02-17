#ifndef _linkedlist_
#define _linkedlist_
struct _node
{
    int value;
    struct _node *next;
};
typedef struct _node Node;
typedef struct
{
    Node *head;
} LinkedList;
void linked_list_add(LinkedList *list, int value);
int linked_list_remove(LinkedList *list, int value);
void printLinkedList(LinkedList *list);
#endif