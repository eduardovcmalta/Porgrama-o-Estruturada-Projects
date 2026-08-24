#include <stdio.h>
#include "quadrado.h"

int main(){
    
    printf("Insira o lado do quadrado: ");
    scanf("%f", &lado);
    Quadrado* q = criar(lado);

    printf("Lado do quadrado: %.2f\n", acessar(q, 'L'));
    printf("Area do quadrado: %.2f\n", acessar(q, 'A'));
    printf("Perimetro do quadrado: %.2f\n", acessar(q, 'P'));

    destruir(q);

    return 0;
}
