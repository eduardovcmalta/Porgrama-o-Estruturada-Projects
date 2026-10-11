#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct fila{
    int dados[MAX];
    int qtd;
    int fim;
    int inicio;
}Fila;
//criar
Fila* criar(){
    Fila* f = malloc(sizeof(Fila));
    if(f!= NULL){
        f->qtd = 0;
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}
//vazia
bool is_empty(Fila* f){
    if(f->qtd == 0){
        return true;
    }else{
        return false;
    }
}
//cheia
bool is_full(Fila* f){
    if(f->qtd == MAX){
        return true;
    }else{
        return false;
    }
}
//enfileirar 
int enqueue(Fila* f, int valor){
    if(f == NULL){
        return 0;
    }
    if(!is_full(f)){
        f->dados[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX;
        f->qtd++;
        return 1;
    }
    printf("Está cheia! \n");
    return 0;
}
//desinfileirar
int dequeue(Fila* f){
    if(f == NULL){
        return -1;
    }
    if(!is_empty(f)){
        int primeiro = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->qtd--;
        return primeiro;
    }
    printf("Esta vazia!\n");
    return -1;
}

int acessar_inicio(Fila* f){
    if(f == NULL){
        return -1;
    }
    if(!is_empty(f)){
        return f->dados[f->inicio];
    }else{
        return -1;
    }
}

int acessar_final(Fila* f){
    if(f == NULL) return -1;
    
    if(!is_empty(f)){
        int ultimo_indice = (f->fim - 1 + MAX) % MAX;
        return f->dados[ultimo_indice];
    }
    return -1;
}