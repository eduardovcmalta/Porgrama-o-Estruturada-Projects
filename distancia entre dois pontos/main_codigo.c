#include <stdio.h>
#include <stdlib.h>
#include "codigo.h"
#include <math.h>

int main(){
    Ponto* p1 = criar_pontos(2.0, 3.0);
    Ponto* p2 = criar_pontos(5.0, 7.0);

    atualizar_pontos(p1, 4.0, 6.0);

    calcular_dois_pontos(p1, p2);

    deletar_pontos(p1);

    p1 = NULL;

    deletar_pontos(p2);
    
    p2 = NULL;

    return 0;
}