#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no* prox;
}No;

typedef struct pilha{
    No* topo;
}Pilha;

Pilha* criar(){
    Pilha* p = malloc(sizeof(Pilha));
    if(p != NULL){
        p->topo = NULL;
        return p;
    }
    return NULL;
}

bool is_empty(Pilha* p){
    if(p->topo == NULL){
        return true;
    }
    return false;
}

int push(Pilha* p, int valor){
    if(p == NULL) return 0;
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->prox = p->topo;
    p->topo = no;
    return 1;
}

int pop(Pilha* p){
    if(p == NULL) return 0;
    if(is_empty(p)) return -1;

    No* aux = p->topo;
    int valor_salvo = aux->valor;
    p->topo = aux->prox;
    free(aux);

    return valor_salvo;
}

int peek(Pilha* p){
    if(p == NULL) return 0;
    if(is_empty(p)) return 0;

    return p->topo->valor;
}