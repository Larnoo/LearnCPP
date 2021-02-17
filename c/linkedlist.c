#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
void linked_list_add(LinkedList *list, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->next = NULL;
    Node *last = list->head;
    if (last)
    {
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        list->head = p;
    }
}
int linked_list_remove(LinkedList *list, int value)
{
    // 默认没有找到对应元素。
    int ret = 0;
    Node *pre = NULL;
    Node *last = list->head;
    if (last == NULL)
    {
        // 空链表，不做删除操作。
        ret = 0;
    }
    else if (last->value == value)
    {
        list->head = last->next;
        free(last);
        ret = 1;
    }
    else
    {
        for (; last; pre = last, last = last->next)
        {
            if(last->value == value){
                ret = 1;
                break;
            }
        }
        pre->next = last->next;
        free(last);
    }
    return ret;
}
void printLinkedList(LinkedList *list)
{
    for (Node * p = list->head; p; p = p->next)
    {
        printf("%d, next point = %p\n", p->value, p->next);
    }
}