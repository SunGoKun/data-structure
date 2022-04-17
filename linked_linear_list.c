#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE     1     
#define FALSE    0     
#define OK       1 
#define ERROR    0
#define INFEASIBLE    -1
#define OVERFLOW      -2 
#define LIST_INIT_SIZE  100
#define LIST_INCREMENT  10

typedef int status;
typedef int elem_type;

typedef struct linked_node 
{
    elem_type data;
    struct linked_node *next;
} linked_node, *linked_list;

void create_head_linked_list(linked_node *head) 
{

    head = (linked_node *)malloc(sizeof(linked_node));
    head->next = NULL;
    
}

status insert_elem_linked_list(linked_node *head, int index, elem_type elem) 
{

    linked_node *temp = head;
    int i = 0;
    while (temp && i < index)
    {
        temp = temp->next;
        ++i;
    }
    if (!temp || i > index)
    {
        return ERROR;
    }

    linked_node *node = (linked_node *)malloc(sizeof(linked_node));
    node->data = elem;
    node->next = temp->next;
    temp->next = node;
    return OK;

}

int get_elem_locate_linked_list(linked_node *head,elem_type elem){
    
    linked_node *temp = head;
    int i = 0;
    while (temp->next) {
        temp = temp->next;
        if (temp->data == elem) {
            return i;
        }
        i++;
    }
    return -1;

}

status delete_elem_linked_list(linked_node *head, int index){

    linked_node *temp = head;
    for (int i = 0; i < index; i++) {
        temp=temp->next;
    }
    linked_node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return OK;
    
}

int main(int argc, char const *argv[])
{
    linked_node head;
    linked_list list = &head;
    create_head_linked_list(list);
    insert_elem_linked_list(list, 0, 1);
    insert_elem_linked_list(list, 1, 2);
    linked_list list = &head;
}
