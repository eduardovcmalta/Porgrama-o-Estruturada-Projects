#include <stdio.h>
#include "circulo.h"


int main() {
    Circulo* c1 = criar_circulo(10);
    Circulo* c2 = criar_circulo(20);

    printf("Circulo 1 -> Raio: %.2f | Diametro: %.2f | Area: %.2f | Perimetro: %.2f\n",
           acessar_raio(c1), calcular_diametro(c1), calcular_area(c1), calcular_perimetro(c1));

    printf("Circulo 2 -> Raio: %.2f | Diametro: %.2f | Area: %.2f | Perimetro: %.2f\n",
           acessar_raio(c2), calcular_diametro(c2), calcular_area(c2), calcular_perimetro(c2));

    free(c1);
    free(c2);

    return 0;
}