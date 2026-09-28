#include <stdlib.h>

struct elem{
    int valor;
    struct elem* prox;
};
typedef struct elem Elem;

struct lista{
    int qtd;
    struct elem* final;
};
typedef struct lista Lista;

Lista* criar(){
    Lista* li = malloc(sizeof(struct lista*));
    if(li != NULL){
        li->qtd = 0;
        li->final = NULL;
    }
    return li;
}
int inserir_inicio(Lista* li, int valor_inserir){
    if (li == NULL){
        return 0;
    }
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->valor = valor_inserir;
    if(li->qtd == 0){
        no->prox = no;
        li->final = no;
    }else{
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->qtd++;
    return 1;
 
}
int inserir_final(Lista* li, int valor_inserir){
    if(li == NULL){
        return 0;
    }
    Elem* no = malloc(sizeof(Elem));
    if (no == NULL){
        return 0;
    }
    no->valor = valor_inserir;
    if(li->qtd == 0){
        no->prox = no;
        li->final = no;
    }else{
        no->prox = li->final->prox;
        li->final->prox = no;
        li->final = no;
    }
    li->qtd++;
    return 1;
}
int remover_inicio(Lista* li){
    if(li == NULL || li->qtd == 0){
        return 0;
    }
    Elem* no = li->final->prox;
    if(li->qtd == 1){
        li->final == NULL;
    }else{
        li->final->prox = no->prox;
    }
    free(no);
    li->qtd--;
    return 1;
}
int remover_final(Lista* li){
    if(li == NULL || li->qtd == 0){
        return 0;
    }
    Elem* no = li->final;
    if(li->qtd == 1){
        li->final = NULL;
    }else{
        Elem* aux = li->final->prox; //recebe o primeiro elemento
        while(aux->prox != li->final){ 
            aux = aux->prox; // anda ate o penultimo
        }
        aux->prox = no->prox; // o penultimo recebe o primeiro, fechando assim o encadeamento
        li->final = aux; // o penultimo vira o novo final
    }
    free(no); // libera o final anterior
    li->qtd--;
    return 1;
}
int acessar_inicio(Lista* li,int* valor){
    if(li == NULL || li->qtd  == 0 || valor == NULL){
        return 0;
    }
    *valor = li->final->prox->valor;
    return 1;
}
// acessar_final()
// destruir()