#include <stdlib.h>
#include <stdio.h>

struct elem{
    int valor;
    struct elem *prox;
};
typedef struct elem Elem;

struct fila{
    int qtd;
    Elem *inicio;
    Elem *final;
};
typedef struct fila* Fila;

Fila criar(){
    Fila f = malloc(sizeof(struct fila));
    if(f == NULL) return NULL;
    f->qtd = 0;
    f->inicio = NULL;
    f->final = NULL;
    return f;
}

int enfileirar(Fila f, int valor){
    if(f == NULL) return 0;
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->valor = valor;
    no->prox = NULL;
    if(f->qtd == 0){
        f->inicio = no;
        f->final = no;
    }else{
        f->final->prox = no;
        f->final = no;
    }
    f->qtd++;
    return 1;
}

int desinfileira(Fila f){
    if(f == NULL || f->inicio == NULL) return 0;
    Elem* no = f->inicio;
    int valor = no->valor;
    if(f->inicio == f->final){
        f->inicio = NULL;
        f->final = NULL;
    }else{
        f->inicio = f->inicio->prox;
    }
    free(no);
    f->qtd--;
    return valor;
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
    if(f == NULL || f->qtd == 0) return 0;
    Elem* no = f->inicio;
    while(no != NULL){
        printf("%d\n", no->valor);
        no = no->prox;
    }
    return 1;
}

void destruir(Fila f){
    if(f == NULL) return;
    Elem *no = f->inicio;
    while(no != NULL){
        Elem *prox = no->prox;
        free(no);
        no = prox;    
    }
    free(f);
}

int main(){
    Fila f = criar();
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 15);
    enfileirar(f, 433);
    enfileirar(f, 44);
    enfileirar(f, 45);
    enfileirar(f, 46);
    enfileirar(f, 47);
    enfileirar(f, 48);
    enfileirar(f, 49);

    desinfileira(f);

    imprimir(f);

    destruir(f);
    return 0;    
}