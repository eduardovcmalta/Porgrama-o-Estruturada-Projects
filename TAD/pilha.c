#include <stdlib.h>
#define MAX 4
//stack
struct pilha{
    int topo;
    int dados[MAX];

};

typedef struct pilha* Pilha;
//create
Pilha criar(){
    Pilha p = malloc(sizeof(Pilha));
    if (p!= NULL){
        p->topo = 0;
    }
    return p;
}
//push
int empilhar(Pilha p, int valor){
    if(p->topo <= MAX){

        p->dados[p->topo] = valor;
        p->topo++;        
        return 1;    
    }
    return -1;
}
//peek
int acessar_topo(Pilha p){
    if(p->topo == 0){
        return p->dados[p->topo -1];
    }else{
        return -1;
    }
}
//pop
int desempilhar(Pilha p){
    if(p->topo == 0){
        return -1;
    }else{
        p->topo--;
        return 1;
    }
}
//free
void destruir(Pilha p){
    if(p != NULL){
        return free(p);
    }
}