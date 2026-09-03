#include "pilha.h"

Pilha copia(Pilha p){
    Pilha p_aux = criar();
    while (acessar_topo(p)){
        desempilhar(p);
        int valor = acessar_topo(p);
        empilhar(p_aux, valor);
    }
    while (acessar_topo(p_aux)){
        desempilhar(p_aux);
        int valor = acessar_topo(p_aux);
        empilhar(p_aux, valor);
    }
    return p;

}


int main() {
    
    Pilha criar();

    
    return 0;
}