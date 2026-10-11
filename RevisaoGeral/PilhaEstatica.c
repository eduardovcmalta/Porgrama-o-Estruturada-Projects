#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct pilha{
    int dados[MAX];
    int topo;
}Pilha;

Pilha* criar(){
    Pilha* p = malloc(sizeof(Pilha));
    if(p != NULL){
        p->topo = -1;
        return p;
    }else{
        return NULL;
    }
}

bool is_empty(Pilha* p){
    return (p->topo == -1);
}

bool is_full(Pilha* p){
    return (p->topo == MAX - 1);
}

int push(Pilha* p, int valor_inserir){
    if(p == NULL){
        return 0;
    }
    if(!is_full(p)){
        p->topo++;
        p->dados[p->topo] = valor_inserir;
        return 1;
    }
    printf("Erro: Pilha cheia!\n");
    return 0;
}

int pop(Pilha* p){
    if(p == NULL){
        return 0;
    }
    if(!is_empty(p)){
        int valor_removido = p->dados[p->topo];
        p->topo--;
        return valor_removido;
    }
    printf("Erro: Pilha vazia!\n");
    return -1;
}

int peek(Pilha* p){
    if(!is_empty(p)){
        return p->dados[p->topo];
    }else{
        printf("Erro: pilha vazia nao tem topo!\n");
        return -1;
    }
}
