#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE     1     
#define FALSE    0     
#define OK       1 
#define ERROR    0
#define INFEASIBLE    -1
#define OVERFLOW      -2 

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int status;
typedef int elem_type;

typedef struct {
    elem_type *base;
    elem_type *top;
    int stack_size;
} seq_stack;

status init_stack(seq_stack *stack) 
{

    stack->base = (elem_type *)malloc(STACK_INIT_SIZE * sizeof(elem_type));
    if (!stack->base){
        return ERROR;
    }
    
    stack->top = stack->base;
    stack->stack_size = STACK_INIT_SIZE;
    return OK;

}

status stack_empty(seq_stack *stack) 
{
    return stack->top == stack->base;
}

status stack_full(seq_stack *stack)
{
    return ((stack->top - stack->base) == stack->stack_size);
}

status destory_stack(seq_stack *stack)
{
    for (int i = 0; i < stack->stack_size; i++)
    {
        free(stack->base);
        stack->base++;
    }
    stack->base=stack->top = NULL;
    stack->stack_size = 0;
    return OK;
}

status get_top(seq_stack *stack, elem_type *e)
{
    if (stack->top == stack->base) {
        printf("stack is empty");
        return ERROR;
    }
    *e = *(stack->top - 1);
    return OK;

}

status push(seq_stack *stack, elem_type e) 
{

    if (stack->top - stack->base >= stack->stack_size) {
        stack->base = (elem_type *)realloc(stack->base, (stack->stack_size + STACK_INCREMENT) * sizeof(elem_type));
        if (!stack->base) {
            exit(OVERFLOW);
        }
        stack->top = stack->base + stack->stack_size;
    }
    *stack->top++ = e;
    return OK;
}



status pop(seq_stack *stack, elem_type *e)  
{

    if (stack->top == stack->base) {
        printf("stack is empty");
        return ERROR;
    }
    *e = *--(stack->top);
    return OK;

}



