#include <stdio.h>
#include <stdlib.h>

struct quadrado{
    float aresta;
};

typedef struct quadrado Quadrado;

Quadrado* criar_quadrado(float aresta){
    Quadrado* q = malloc(sizeof(Quadrado));
    q->aresta = aresta;
    return q;
}

float acessar_aresta(Quadrado* q){
    return q->aresta;
} 

float calcular_area(Quadrado* q){
    return  (q->aresta) * (q->aresta);
}

float calcular_perimetro(Quadrado* q){
    return 4 * (q->aresta);
}

int main(){
    Quadrado* q1 = criar_quadrado(10);
    Quadrado* q2 = criar_quadrado(30);

    printf("Quadrado 1: tem aresta no valor de: %.2f, sua area equivale a: %.2f e o seu perimetro equivale a: %.2f\n",
    acessar_aresta(q1), calcular_area(q1), calcular_perimetro(q1));
    
    printf("Quadrado 2: tem aresta no valor de: %.2f, sua area equivale a: %.2f e o seu perimetro equivale a: %.2f\n", 
    acessar_aresta(q2), calcular_area(q2), calcular_perimetro(q2));

    free(q1);
    free(q2);

    return(0);
}