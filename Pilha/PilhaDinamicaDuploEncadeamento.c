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

}

int push(Pilha p, int valor){
    if(p == NULL) return 0;
    
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;

    no->valor = valor;
    no->prox = NULL;

    if(p->topo == NULL){
        p->topo = no;
        no->ant = NULL;
    }else{
        p->topo->prox = no;
        no->ant = p->topo;
        p->topo = no;
    }
    return 1;
}

int pop(Pilha p){
    if(p == NULL || p->topo == NULL) return 0;
    Elem *remove = p->topo;
    p->topo = p->topo->ant;
    p->topo->prox = NULL;
    free(remove);
    return 1;
}

int peek(Pilha p){
    if(p == NULL || p->topo == NULL) return 0;
    return p->topo->valor;
}

void free(Pilha p){
    if(p == NULL || p->topo == NULL) return;

    Elem* no = p->topo;
    while(no != NULL){
        Elem* aux = no->ant;
        free(no);
        no = aux;
    }
    free(p);
}