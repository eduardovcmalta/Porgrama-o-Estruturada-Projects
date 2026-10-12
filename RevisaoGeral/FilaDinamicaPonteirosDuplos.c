#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no* prox;
}No;

typedef struct fila{
    No* inicio;
    No* fim;
}Fila;

Fila* criar(){
    Fila* f = malloc(sizeof(Fila));
    if(f != NULL){
        f->inicio = NULL;
        f->fim = NULL;
        return f;
    }
    return NULL;
}

bool is_empty(Fila* f){
    if(f->inicio == NULL && f->fim == NULL){
        return true;
    }
    return false;
}

int enqueue(Fila* f, int valor){
    if(f == NULL) return 0;
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;

    if(is_empty(f)){
        f->inicio = no;
        f->fim = no;
    }else{
        f->fim->prox = no;
        f->fim = no;
    }
    return 1;
}

int dequeue(Fila* f){
    if(f == NULL || is_empty(f)) return 0;
    No* atual = f->inicio;
    int valor_salvo = atual->valor;

    f->inicio = atual->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    free(atual);
    return 1;
}
