#include <stdio.h>
#include <assert.h>

#define STACK_CAPACITY 8

static char stack[STACK_CAPACITY];
static int size = 0;

int st_isempty(void){
    return size == 0 ? 1 : 0;
}

int st_size(void){
    return size;
}

int st_push(char c){
    if (size >= STACK_CAPACITY){
        return -1;
    }
    stack[size] = c;
    size ++;
    return 0;
}

void st_print(void){
    printf("size = %d : [", size);
    for (int i = 0; i < size; i++){
        printf(" %c", stack[i]);
    }
    printf("\n");
}

int st_pop(char *pc){
    if (size == 0){
        return -1;
    }
    *pc = stack[size - 1];
    size--;
    stack[size] = 0;
    return 0;
}
