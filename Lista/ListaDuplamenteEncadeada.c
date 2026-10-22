#include <stdlib.h>
#include <stdio.h>

struct elem{
    int valor;
    struct elem *prox;
    struct elem *ant;
};
typedef struct elem Elem;
struct lista{
    int qtd;
    Elem *final;
    Elem *inicio;
};
typedef struct lista* Lista;

Lista criar(){
    Lista l = malloc(sizeof(struct lista));
    if(l == NULL) return NULL;
    l->inicio = NULL;
    l->final = NULL;
    l->qtd = 0;
    return l;
}

int inserir_inicio(Lista l, int valor){
    if(l == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0; 
    no->valor = valor;
    no->prox = NULL;
    no->ant = NULL;
    if(l->qtd == 0){
        l->inicio = no;
        l->final = no;
    } else{
        no->prox = l->inicio;
        l->inicio->ant = no;
        l->inicio = no;
    }
    l->qtd++;
    return 1;
}

int inserir_final(Lista l, int valor){
    if(l == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->valor = valor;
    no->prox = NULL;
    no->ant = NULL;
    if(l->qtd == 0){
        l->final = no;
        l->inicio = no;
    }else{
        no->ant = l->final;
        l->final->prox = no;
        l->final = no;
    }
    l->qtd++;
    return 1;
}

int remover_inicio(Lista l){
    if(l == NULL || l->inicio == NULL || l->qtd == 0) return 0;
    if(l->inicio == l->final){
        free(l->inicio);
        l->inicio = NULL;
        l->final = NULL;
        l->qtd--;
        return 1;
    }else{
        l->inicio = l->inicio->prox;
        free(l->inicio->ant);
        l->inicio->ant = NULL;  
    }
    l->qtd--;
    return 1;
}

int remover_final(Lista l){
    if(l == NULL || l->final == NULL || l->qtd == 0) return 0;
    if(l->final == l->inicio){
        free(l->final);
        l->final = NULL;
        l->inicio = NULL;
        l->qtd--;
        return 1;
    }  else{
        l->final = l->final->ant;
        free(l->final->prox);
        l->final->prox = NULL;
    }
    l->qtd--;
    return 1;
}

int acessar_inicio(Lista l){
    if(l == NULL || l->inicio == NULL || l->qtd == 0) return 0;
    return l->inicio->valor;
}
int acessar_final(Lista l){
    if(l == NULL  || l->final == NULL || l->qtd == 0) return 0;
    return l->final->valor;
}

int imprimir(Lista l){
    if(l == NULL) return 0;
    Elem *atual = l->inicio;
    while(atual != NULL){
        printf("%d", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
    return 1;
}

void destruir(Lista l){
    if(l == NULL) return;
    if(l->inicio != NULL){
        while(l->inicio->prox != NULL){
            l->inicio = l->inicio->prox;
            free(l->inicio->ant);
        }
        free(l->inicio);
    }
    free(l);
}