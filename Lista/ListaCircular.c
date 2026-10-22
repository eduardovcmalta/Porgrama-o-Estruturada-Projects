#include <stdlib.h>
#include <stdio.h>

struct elem{
    int valor;
    struct elem* prox;
};
typedef struct elem Elem;

struct lista{
    int qtd;
    Elem *final;
};
typedef struct lista* Lista;

Lista criar(){
    Lista li = malloc(sizeof(struct lista));

    if(li == NULL) return NULL;
    
    li->qtd = 0;
    li->final = NULL;
    return li;
}

int inserir_inicio(Lista li, int valor){
    if(li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;
    if(li->qtd == 0 && li->final == NULL){
        no->prox = no;
        li->final = no;
    } else{
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->qtd++;
    return 1;
}

int remover_inicio(Lista li){
    if(li == NULL || li->qtd == 0 || li->final == NULL) return 0;
    Elem* no = li->final->prox;
    int valor = no->valor;

    if(no == li->final){
        li->final = NULL;
    }else{
        li->final->prox = no->prox;
    }
    free(no);
    li->qtd--;
    return valor;
}

int inserir_final(Lista li, int valor){
    if(li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    no->valor = valor;
    if(li->qtd == 0 || li->final == NULL){
        no->prox = no;
        li->final = no;
    } else{
        no->prox = li->final->prox;
        li->final->prox = no;
        li->final = no;      
    }
    li->qtd++;
    return 1;
}

int remover_final(Lista li){
    if(li == NULL || li->qtd == 0 || li->final == NULL) return 0;
    Elem* retirada = li->final;
    int valor = retirada->valor;
    if(retirada->prox == retirada){
        li->final = NULL;
    }else{
        Elem* aux = retirada->prox;
        while(aux->prox != li->final){
            aux = aux->prox;
        }
        aux->prox = li->final->prox->prox;
        li->final = aux;        
    }
    free(retirada);
    li->qtd--;
    return valor;    
}

int acessar_inicio(Lista li){
    if(li == NULL || li->qtd == 0 || li->final == NULL) return 0;
    return li->final->prox->valor;
}

int acessar_final(Lista li){
    if(li == NULL || li->qtd == 0 || li->final == NULL) return 0;
    return li->final->valor;
}
void destruir(Lista li){
   if(li == NULL) return;
   while(li->qtd != 0){
        remover_inicio(li);
   }
   free(li);
}