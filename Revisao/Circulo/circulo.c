
#include <stdlib.h>
#define PI 3.14
#include "circulo.h"

struct circulo {
    float raio;
};

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