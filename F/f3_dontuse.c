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
    struct Node *appNode = (struct Node *)malloc(sizeof(struct Node));

    appNode->value = value;
    appNode->next = NULL;

    if (pList->size == 0) {
        pList->first = appNode;
        pList->last = appNode;
    } else {
        pList->last->next = appNode;
        pList->last = appNode;
    }
    pList->size++;
}

void delete(struct List *pList) { //удаляет все
    struct Node *current = pList->first;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    pList->size = 0;
    pList->last = NULL;
    pList->first = NULL;
}

void swap(struct List *pList) {
    if (pList->size <= 1) 
        return;

    struct Node* last = pList->last;
    struct Node* secondLast = pList->first;

    while (secondLast->next != last) {
        secondLast = secondLast->next;
    }
        
    secondLast->next = pList->first;
    last->next = pList->first->next;
    pList->first->next = NULL;
    pList->first = last;
    pList->last = secondLast;
}


void print(const struct List *pList) {
    printf("length = %lu\n", pList->size);
    struct Node *current = pList->first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}



int main() {
    struct List list = { NULL, NULL, 0 };
    int value;

    for (int i = 0; i < 5; i++){
        scanf("%d", &value);
        append(&list, value);
    }

    // while (scanf("%d", &value) == 1) {
    //     append(&list, value);
    // }

    print(&list);

    delete(&list);
    print(&list);
    return 0;
}
