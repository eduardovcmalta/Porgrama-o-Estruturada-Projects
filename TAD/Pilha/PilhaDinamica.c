#include <stdlib.h>
#include <stdio.h>

struct elem{
    int valor;
    struct elem *prox;
};
typedef struct elem Elem;

struct pilha{
    Elem* topo;
};
typedef struct pilha* Pilha;

Pilha criar(){
    Pilha p = malloc(sizeof(struct pilha));
    if(p == NULL) return NULL;
    p->topo = NULL;
    return p;
}

int push(Pilha p, int valor){
    if(p == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->valor = valor;
    no->prox = p->topo;
    p->topo = no;
    return 1;
}

int pop(Pilha p){
    if(p == NULL || p->topo == NULL) return 0;
    Elem* aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    p->topo--;
    return 1;
}

int acessar_topo(Pilha p){
    if(p == NULL || p->topo == NULL) return 0;
    return p->topo->valor;
}

int imprimir(Pilha p){
    if(p == NULL || p->topo == NULL) return 0;
    Elem* aux = p->topo;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    return 1;
}

void destruir(Pilha p){
    if(p == NULL) return;
    Elem *no = p->topo;
    while(no != NULL){
        Elem *prox = no->prox;
        free(no);
        no = prox;
    }
    free(p);
}

