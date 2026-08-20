#include <stdio.h>
#include <stdlib.h>

struct quadrado{
    float lado;
    float area;
    float perimetro;
};

typedef struct quadrado Quadrado;

Quadrado* criar(float lado){
    Quadrado* q = malloc(sizeof(Quadrado));
    if(q != NULL){
        q->lado = lado;
        q->area = q->lado*q->lado;
        q->perimetro = 4*q->lado;    
    }
    return q;
}

float acessar(Quadrado* q, char var){
    if(var == 'L')
        return q->lado;
    if(var == 'A')
        return q->area;
    if(var == 'P')
        return q->perimetro;
    return -1;
}

int alterar(Quadrado* q, float lado){
    if(lado <= 0)
        return -1;
    else{
        q->lado = lado;
        q->area = q->lado*q->lado;
        q->perimetro = 4*q->lado;    
        return 1;
    }
}

void destruir(Quadrado* q){
    if(q != NULL)
        free(q);
}

int main(){
    float lado = 4;
    
    Quadrado* q = criar(lado);

    printf("Lado do quadrado: %.2f\n", acessar(q, 'L'));
    printf("Area do quadrado: %.2f\n", acessar(q, 'A'));
    printf("Perimetro do quadrado: %.2f\n", acessar(q, 'P'));

    destruir(q);

    return 0;
}






// struct quadrado{
//     float aresta;
// };

// typedef struct quadrado Quadrado;

// Quadrado* criar_quadrado(float aresta){
//     Quadrado* q = malloc(sizeof(Quadrado));
//     q->aresta = aresta;
//     return q;
// }

// float acessar_aresta(Quadrado* q){
//     return q->aresta;
// } 

// float calcular_area(Quadrado* q){
//     return  (q->aresta) * (q->aresta);
// }

// float calcular_perimetro(Quadrado* q){
//     return 4 * (q->aresta);
// }

// int main(){
//     Quadrado* q1 = criar_quadrado(10);
//     Quadrado* q2 = criar_quadrado(30);

//     printf("Quadrado 1: tem aresta no valor de: %.2f, sua area equivale a: %.2f e o seu perimetro equivale a: %.2f\n",
//     acessar_aresta(q1), calcular_area(q1), calcular_perimetro(q1));
    
//     printf("Quadrado 2: tem aresta no valor de: %.2f, sua area equivale a: %.2f e o seu perimetro equivale a: %.2f\n", 
//     acessar_aresta(q2), calcular_area(q2), calcular_perimetro(q2));

//     free(q1);
//     free(q2);

//     return(0);
// }