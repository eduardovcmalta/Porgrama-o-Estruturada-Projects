#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}No;
typedef struct lista{
    struct no* inicio;
}Lista;

Lista* criar(){
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        return li;
    }
    return NULL;
}

int inserir_inicio(Lista* li, int valor_inserir){
    if(li == NULL) return 0;
    No* no = malloc(sizeof(No));
    no->valor = valor_inserir;
    no->prox = li->inicio;
    li->inicio = no;
    return 1;
    
}

int inserir_final(Lista* li, int valor_inserir){
    if(li == NULL) return 0;

    No* no = malloc(sizeof(No));
    no->valor = valor_inserir;
    no->prox = NULL;
    if(li->inicio == NULL){
        li->inicio = no;
        return 1;
    }
    No* aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
    return 1;
}

int buscar(Lista* li, int valor_buscar){
    if(li == NULL) return 0;
    No* aux = li->inicio;
    
    while(aux != NULL){
        if(aux->valor == valor_buscar){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void imprimir(Lista* li){
    if(li == NULL) return 0;
    No* aux = li->inicio;
    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux = aux->prox;

    }
    printf("NULL \n");
}

int remover(Lista* li, int valor_remover){
    if(li == NULL || li->inicio == NULL) return 0;

    No* aux = li->inicio;
    No* ant = NULL;

    while(aux != NULL && aux->valor != valor_remover){
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL) return 0;

    if(ant == NULL){
        li->inicio = aux->prox;
    }else{
        ant->prox = aux->prox;
    }
    free(aux);
    return 1;
}