#include <stdlib.h>
#define PI 3.14
#include <stdio.h>

struct cilindro{
    float raio;
    float altura;
};

typedef struct cilindro Cilindro;

Cilindro* criar_cilindro(){
    Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
    return c;
}

float calcular_area(Cilindro* c){
    if (c->raio <= 0 || c->altura <= 0){
        printf("O cilindro não existe!\n");
        return -1.0;
    }else{
        return (2*PI*c->raio) * (c->altura + c->raio);
    }
}

float calcular_volume(Cilindro* c){
    if (c->raio <=0 || c->altura  <= 0){
        printf("O cilindro não existe / nao pode exisitir!\n ");
        return -1.0;
    }else{
        return PI * (c->raio * c->raio) * c->altura;
    }
}


int main(){
    Cilindro* c = criar_cilindro();
    
    printf("Digite aqui o raio do cilindro que voce deseja calcular: \n");
    scanf("%f", &c->raio);

    printf("Digite agora a altura do cilindro: \n");
    scanf("%f", &c->altura);
    
    printf("Area do cilindro: %.2f", calcular_area(c));
    printf("Volume do cilindro: %.2f", calcular_volume(c));

    free(c);
}