#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "codigo.h"
struct ponto{
    float x;
    float y;
};

typedef struct ponto Ponto;

Ponto* criar_pontos(float x, float y){
    Ponto* p = malloc(sizeof(Ponto));
    if (p == NULL){
        printf("Erro: memória nao alocada!\n");
        return NULL;
    }
    p->x = x;
    p->y = y;
    printf("Pontos criados! (%.2f, %.2f)\n", p->x, p->y);
    return p;
}


void atualizar_pontos(Ponto*p, float novox, float novoy){
    if(p == NULL){
        printf("Erro: os pontos nao existem!\n");
        return;
    }
    p->x = novox;
    p->y = novoy;
    printf("Pontos atualuzados! (%.2f, %.2f)\n", p->x, p->y);
}

void deletar_pontos(Ponto* p){
    if(p != NULL){
        free(p);
    }
}

float calcular_dois_pontos(Ponto* p1, Ponto* p2){
        if(p1 == NULL || p2 == NULL){
            printf("Erro: Um dos pontos é NULL!\n");
            return -1;
        }
        float distancia = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
        printf("A distancia entre os pontos é: %.2f\n", distancia);
        return distancia;
}