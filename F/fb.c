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

void append_otriz(struct List *pList, struct List *otriz) {
    struct Node *current = otriz->first;

    while (current != NULL) {
        append(pList, current->value);
        current = current->next;
    }
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


void print(const struct List *pList) {
    struct Node *current = pList->first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}



int main(void) {
    struct List spisok = { NULL, NULL, 0 };
    struct List otriz = { NULL, NULL, 0 };
    int value;

    while (scanf("%d", &value) == 1) {
        append(&spisok, value);
        if (value < 0)
            append(&otriz, value);
    }

    append_otriz(&spisok, &otriz);
    print(&spisok);
    delete(&spisok);
    delete(&otriz);
    return 0;
}
