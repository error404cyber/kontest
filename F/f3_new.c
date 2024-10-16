#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int value;
};

struct List {
    struct Node *first;
    struct Node *last;
    size_t size;
};


void append(struct List *pList, int value) {
    struct Node *appendNode = (struct Node *)malloc(sizeof(struct Node));

    appendNode->value = value;
    appendNode->next = NULL;

    if (pList->size == 0) {
        pList->first = appendNode;
        pList->last = appendNode;
    } else {
        pList->last->next = appendNode;
        pList->last = appendNode;
    }

    pList->size++;
}

void delete(struct List *pList) {
    struct Node *current = pList->first;
    struct Node *next_current;

    while (current != NULL) {
        next_current = current->next;
        free(current);
        current = next_current;
    }

    pList->size = 0;
    pList->last = NULL;
    pList->first = NULL;
}

void swap(struct List *pList) {
    if (pList->size <= 1) 
        return;

    int first_val = pList->first->value;
    pList->first->value = pList->last->value;
    pList->last->value = first_val;
}


void print(const struct List *pList) {
    printf("length = %lu\n", pList->size);

    struct Node *current = pList->first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}



int main(void) {
    struct List spisok = { NULL, NULL, 0 };
    int value;

    // for (int i = 0; i < 2; i++){
    //     scanf("%d", &value);
    //     append(&spisok, value);
    // }

    while (scanf("%d", &value) == 1) {
        append(&spisok, value);
    }

    swap(&spisok);
    print(&spisok);
    delete(&spisok);
    return 0;
}
