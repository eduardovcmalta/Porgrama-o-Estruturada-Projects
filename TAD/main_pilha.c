#include <stdio.h>
#include "pilha.h"

int main(){
    Pilha p = criar();

    empilhar(p, 50);
    empilhar(p, 60);
    empilhar(p, 70);
    empilhar(p, 20);
    
    printf("Topo da pilha: %d\n", acessar_topo(p));
    
    desempilhar(p);
    desempilhar(p);
    
    printf("Topo da pilha: %d\n", acessar_topo(p));
    
    destruir(p);

}