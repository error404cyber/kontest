// Типы данных для организации динамического списка чисел типа int и некоторые функции уже определены в файле t02.c. 
// Скачайте этот файл и используйте, как заготовку для своей программы. По желанию, можно всё переписать по-своему.

// Напишите функцию merge, которая принимает два списка чисел, отсортированных по возрастанию, и создаёт новый отсортированный список путём слияния первых двух.

// Напишите программу, которая читает две упорядоченные по возрастанию последовательности чисел типа int со стандартного потока ввода и создаёт два динамических списка.
// Признаком конца последовательности является число 0, оно не входит в последовательность. Далее программа вызывает целевую функцию merge, печатает полученный список в стандартный поток вывода. Наконец, удаляет все списки.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * next;
    int value;
};

struct List {
    struct Node * first;
    struct Node * last;
};

void append(struct List * list, int value) {
    struct Node * node = malloc(sizeof(struct Node));
    *node = (struct Node) { .value = value };
    if (list->last) {
        list->last->next = node;
        list->last = node;
    } else {
        list->first = list->last = node; 
    }
}

void print(const struct List * list)  {
    struct Node * node = list->first;
    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    putchar('\n');
}

void release(struct List * list) {
    struct Node * node;
    while ((node = list->first)) {
        list->first = list->first->next;
        free(node);
    }
    list->first = list->last = NULL;
}

struct List merge(struct List * list1, struct List * list2) {
    struct List result = { NULL, NULL };

    struct Node * node1 = list1->first;
    struct Node * node2 = list2->first;

    while (node1 != NULL && node2 != NULL) {
        if (node1->value < node2->value) {
            append(&result, node1->value);
            node1 = node1->next;
        } else {
            append(&result, node2->value);
            node2 = node2->next;
        }
    }

    while (node1 != NULL) {
        append(&result, node1->value);
        node1 = node1->next;
    }

    while (node2 != NULL) {
        append(&result, node2->value);
        node2 = node2->next;
    }

    return result;
}

int main(void)
{
    struct List list1 = { };
    struct List list2 = { };
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        append(&list1, n);
    }
    while (scanf("%d", &n) == 1 && n != 0) {
        append(&list2, n);
    }

    struct List merged = merge(&list1, &list2);

    print(&merged);
    release(&merged);
    release(&list1);
    release(&list2);
}
