#include <stdlib.h>
#include <stdio.h>
struct elem{
    int valor;
    struct elem *prox;
    struct elem *ant;
};
typedef struct elem Elem;
struct fila{
    Elem* inicio;
    Elem* final;
};
typedef struct fila *Fila;

Fila criar(){
    Fila f = malloc(sizeof(struct fila));
    if(f != NULL){
        f->inicio = NULL;
        f->final = NULL;
        return f;
    } else{
        return NULL;
    }
}

int enfileirar(Fila f, int valor){
    if(f == NULL) return 0;
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->valor = valor;
    no->prox = NULL;
    if(f->inicio == NULL){
        no->ant = NULL;
        f->inicio = no;
        f->final = no;
    }else{
        no->ant = f->final;
        f->final->prox = no;
        f->final = no;
    }
    return 1;
}

int desenfileira(Fila f){
    if(f == NULL || f->inicio == NULL) return 0;
    Elem *no = f->inicio;
    f->inicio = f->inicio->prox;

    if(f->inicio != NULL){
        f->inicio->ant = NULL;
    }else{
        f->final = NULL;
    }
    free(no);
    return 1;
}

int consultar_inicio(Fila f){
    if(f == NULL || f->inicio == NULL) return 0;
    return f->inicio->valor;
}

int consultar_final(Fila f){
    if(f == NULL || f->final == NULL) return 0;
    return f->final->valor;
}

int imprimir(Fila f){
    if(f == NULL) return 0;
    Elem* aux = f->inicio;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    return 1;
}

void destruir(Fila f){
    if(f == NULL) return;
    Elem *aux = f->inicio;
    while(aux != NULL){
        Elem *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(f);
}