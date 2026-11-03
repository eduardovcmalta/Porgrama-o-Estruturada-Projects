#include <stdlib.h>

struct elem{
    int valor;
    struct elem *prox;
    struct elem *ant;
};
typedef struct elem Elem;

struct pilha{
    Elem *topo;
};
typedef struct pilha *Pilha;

Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));
    if( p == NULL) return NULL;
    p->topo = NULL;
    return p;
}

int push(Pilha p, int valor){
    if(p == NULL) return 0;
    
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;

    no->valor = valor;
    no->prox = NULL;
    no->ant = p->topo;

    if(p->topo != NULL){
        p->topo->prox = no;
    }
    p->topo = no;
    return 1;
}

int pop(Pilha p, int *valor){
    if(p == NULL || p->topo == NULL) return 0;

    Elem *remove = p->topo;
    p->topo = remove->ant;
    if(p->topo != NULL){
        p->topo->prox = NULL;
    }
    free(remove);
    return 1;
}

int peek(Pilha p, int *valor){
    if(p == NULL || p->topo == NULL) return 0;
    return p->topo->valor;
}

void destruir(Pilha p){
    if(p == NULL) return;

    Elem* no = p->topo;
    while(no != NULL){
        Elem* aux = no->ant;
        free(no);
        no = aux;
    }
    free(p);
}