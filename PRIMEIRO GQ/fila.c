#include <stdlib.h>

struct elem{
    int valor;
    struct elem* prox;
};
typedef struct elem Elem;

struct fila{
    Elem* inicio;
    Elem* final;
};
typedef struct fila Fila;

int fila_inversa(Fila* f1){
    if(f1 == NULL || f1->inicio == NULL){
        return 0;
    }
    Elem* atual = f1->inicio;
    Elem* ant = NULL;
    Elem* prox;

    f1->final = f1->inicio;

    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    f1->inicio = ant;

}

int concatenar_filas(Fila* f1, Fila* f2){
    if(f1 == NULL || f2 == NULL){
        return 0;
    }

    if(f2->inicio == NULL){
        return 1;
    }

    if(f1->inicio == NULL){
        f1->inicio = f2->inicio;
    }else{
        f1->final->prox = f2->inicio;
    }
    f1->final = f2->final;

    f2->inicio = NULL;
    f2->final = NULL;
    return 1;
}

int ordenar_filas_crescente(Fila* f1, Fila* f2, Fila* f3){
    if(f1 == NULL || f2 == NULL || f3 == NULL){
        return 0;
    }

    while(f1->inicio != NULL && f2->inicio != NULL){
        Elem* menor;
        if(f1->inicio->valor <= f2->inicio->valor){
            menor = f1->inicio;
            f1->inicio = f1->inicio->prox;
        } else {
            menor = f2->inicio;
            f2->inicio = f2->inicio->prox;
        }
        menor->prox = NULL;

        if(f3->inicio == NULL){
            f3->inicio = menor;
        } else {
            f3->final->prox = menor;
        }
        f3->final = menor;
    }

    Fila* resto;
    if(f1->inicio != NULL){
        resto = f1;
    } else {
        resto = f2;
    }    
    if(resto->inicio != NULL){
        if(f3->inicio == NULL){
            f3->inicio = resto->inicio;
        } else {
            f3->final->prox = resto->inicio;
        }
        f3->final = resto->final;
    }

    f1->inicio = f1->final = NULL;
    f2->inicio = f2->final = NULL;
    return 1;
}