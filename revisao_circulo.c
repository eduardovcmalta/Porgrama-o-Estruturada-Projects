#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

struct circulo {
    float raio;
};

typedef struct circulo Circulo;

Circulo* criar_circulo(float raio) {
    Circulo* c = malloc(sizeof(Circulo));
    c->raio = raio;
    return c;
}

float acessar_raio(Circulo* c) {
    return c->raio;
}

float calcular_diametro(Circulo* c) {
    return 2 * c->raio;
}

float calcular_area(Circulo* c) {
    return PI * c->raio * c->raio;
}

float calcular_perimetro(Circulo* c) {
    return 2 * PI * c->raio;
}

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


// float calcular_diametro(int raio){
//     float diametro = 2*raio;
//     return diametro;
// }

// float calcular_perimetro(int raio){
//     float perimetro = 2 * calcular_diametro(raio);
//     return perimetro;
// }

// float calcular_area(int raio){
//     float area= PI*raio*raio;
//     return area;
// }

// float* calcular_area2(int raio){
//     float *area = malloc(1*sizeof(float)); //alocaçao de memoria. malloc(qtd de bytes a serem alocados). sizeof pede o o espaço a ser alocado.
//     *area = PI*raio*raio;
//     return &area;
// }

    // int raio = 10;
    // printf("valor do raio: %d | Endereço do raio %p\n", raio, &raio);
    // float *area = calcular_area2(raio);
    // printf("Valor da area: %.2f", *area);
    // printf("Endereço da variavel area: %p\n", &area);
    // printf("Endereço ponteiro area %p\n", &area);

    // free(area); //liebrar o espaço na memoria para desalocar o que foi guardado
