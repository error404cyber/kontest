#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode * Tree;

struct TNode {
    int key;
    struct TNode * left;
    struct TNode * right;
};

void add(Tree* pTree, int n) {
    if (*pTree == NULL) {
        (*pTree) = (struct TNode*)malloc(sizeof(struct TNode));
        (*pTree)->key = n;
        (*pTree)->left = NULL;
        (*pTree)->right = NULL;
        return;
    }

    if (n < (*pTree)->key) {
        add(&((*pTree)->left), n);
    } 
    else {
        if (n == (*pTree)->key)
                return;
        add(&((*pTree)->right), n);
    }
}

void print(Tree tree){
    if (tree == NULL){
        return;
    }
    print(tree->left);
    printf("%d ", tree->key);
    print(tree->right);
}

void release(Tree pTree) {
    if (pTree == NULL) {
        return;
    }
    release(pTree->left);
    release(pTree->right);
    free(pTree); //почему null не работает
}


int main(int argc, char *argv[]) {
    if (argc < 2)
        return 1;
    Tree tree = NULL;
    char *stroka = argv[1];
    char *chisla;

    chisla = strtok(stroka, " ,");

    while (chisla != NULL){
        int chis = atoi(chisla);
        add(&tree, chis);
        chisla = strtok(NULL, " ,");
    }

    print(tree);
    release(tree);
    return 0;
}
