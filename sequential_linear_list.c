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

typedef struct 
{
    elem_type *elem;
    int length;
    int list_size;
} seq_list;

status init_seq_list(seq_list *list) 
{

    list->elem = (elem_type *)malloc(LIST_INIT_SIZE * sizeof(elem_type));
    if (!list->elem)
    {
        printf("init seq list error: failed to allocate storage\n");
        exit(OVERFLOW);
    }
    list->length = 0;
    list->list_size = LIST_INIT_SIZE;
    return OK;
}

status distroy_seq_list(seq_list *list) 
{

    if (!list->elem) {
        printf("not created seq list\n");
        return ERROR;
    }
    free(list->elem);
    list->elem = NULL;
    list->length = 0;
    list->list_size = 0;
    printf("seq list was destroyed\n");
    return OK;

}

status clear_seq_list(seq_list *list)
{

    if (list->elem) {
        list->length = 0;
        printf("clear seq list\n");
        return OK;
    } else {
        printf("not created seq list\n");
        return ERROR;
    }
    
}

status empty_seq_list(seq_list list) {

    if (list.elem)
    {
        if(list.length != 0){ 
		       printf("seq list is not empty\n");
		       return FALSE; 
			}
			else
			   printf("seq list is empty\n");
		return TRUE;
    } else {
       printf("not created seq list\n"); 
       return ERROR;
    }
    return OK;

}

int seq_list_length(seq_list list) 
{

    if(list.elem) {              
		int length;
		length = list.length;
		return length; 
	} else {
       printf("not created seq list\n");
       return ERROR; 
    }
    return OK;

}

elem_type get_seq_list_elem(seq_list list, int index) 
{

    elem_type elem;
    if(index <= 0 || index > list.length){              
		printf("index overflow");
		return ERROR;
	} else {
        elem = list.elem[index];
        return elem;
    }
    return OK;

}

int get_elem_locate_seq_list(seq_list list, elem_type elem)
{   

    int index = -1;
    for (int i = 0; i < list.length; i++)
    {
        if (list.elem[i] == elem)
        {
            index = i;
        }
    }
    return index;
    
}

status insert_elem_seq_list(seq_list *list, int index, elem_type elem) 
{

    elem_type *new_base;
    int *p, *q;
    if (index < 0 || index > list->length)
    {
        return ERROR;
    }
    if(list->length >= list->list_size){
		new_base = (elem_type *)realloc(list->elem, (list->list_size + LIST_INCREMENT)*sizeof(elem_type));
		if(!new_base)  {                 
			printf("insert elem to seq list error: failed to allocate storage\n");
			exit(OVERFLOW);
		}
		list->elem = new_base;	
		list->list_size += LIST_INCREMENT; 
	}
	q = &(list->elem[index]);
	for(p = &(list->elem[list->length - 1]);p >= q;--p) {
        *(p+1) = *p; 
    }          
	*q = elem;                    
	++list->length;     
	printf("insert elem to seq list success\n");
	return OK;

}


status delete_elem_seq_list(seq_list *list, int index) 
{
    int *p,*q;
	if(index < 0 || index > list->length -1) {
		printf("delete elem error: index overflow"); 
		return ERROR;
	} 
	p = &(list->elem[index]);                 
	q = list->elem + list->length - 1;            
	for(++p; p <= q; p++)
	    *(p - 1) = *p;                
	--list->length;
	printf("delete elem seq list success\n");
	return OK;
}

elem_type prior_elem_seq_list(seq_list list, int index) 
{

    int elem;
    if (list.elem) {   
        if (index == 0) 
        {   
            printf("first element doesn't have a prior\n");
            return NULL;
        }
        
        if (index > 0 || index < list.length - 1)
        {   
            elem = list.elem[index - 1];
            return elem;
        }
        
    } else {
        printf("not created seq list\n");
        return NULL;

    }
    
    return OK;
}

elem_type next_elem_seq_list(seq_list list, int index) 
{

    int elem;
     if (list.elem) {

        if (index == list.length - 1) 
        {   
            printf("final element doesn't have a next\n");
            return NULL;
        }
        
        if (index > 0 || index < list.length - 1)
        {   
            elem = list.elem[index + 1];
            return elem;
        }
        
    } else {
        printf("not created seq list\n");
        return NULL;

    }
    
    return OK;
}

status print_seq_list(seq_list list){
    printf("[");
	for(int i = 0; i < list.length - 1; i++) {
        printf("%d, ",list.elem[i]);
    }
	printf("%d", list.elem[list.length - 1]);
    printf("]");
	printf("\n");                        
	return OK;
}

void merge_seq_list(seq_list *fir_list, seq_list *sed_list, seq_list *result_list) 
{

    elem_type *fp = fir_list->elem;
    elem_type *sp = sed_list->elem;
    result_list->list_size = result_list->length = fir_list->length + sed_list->length;
    elem_type *rp = result_list->elem = (elem_type *)malloc(result_list->list_size * sizeof(elem_type));
    elem_type *fp_last = fir_list->elem + fir_list->length - 1;
    elem_type *sp_last = sed_list->elem + sed_list->length - 1;
    while (fp < fp_last && sp < sp_last) {

        if (*fp <= *sp)
        {
            *rp++ = *fp++;
        } else {
            *rp++ = *sp++;
        }
        
    }
    while(fp <= fp_last) {
        *rp++ = *fp++;
    }
     while(sp <= sp_last) {
        *rp++ = *sp++;
    }
}
