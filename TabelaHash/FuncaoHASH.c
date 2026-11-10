#include <stdio.h>
#include <stdlib.h>
#define TAM 7

typedef struct no{
    int matricula;
    int nota;
    struct no *prox;
}No;

typedef struct{
    No *tabela[TAM];
}TabelaHash;

int hash(int chave){
    int indice = chave % TAM;
    if(indice < 0) indice += TAM;
    return indice;
}

void inicializar(TabelaHash *t){
    for(int i = 0; i < TAM; i ++){
        t->tabela[i] = NULL;
    }
}

void inserir(TabelaHash *t, int matricula, float nota){
    int i = hash(matricula);

    for(No *p = t->tabela[i]; p != NULL;p = p->prox){
        if(p->matricula == matricula){
            p->nota = nota;
            return;
        }
    }

    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de memoria!\n");
        return;
    }
    novo->matricula = matricula;
    novo->nota = nota;
    novo->prox = t->tabela[i];
    t->tabela[i] = novo;
}

No *buscar(TabelaHash *t, int matricula){
    int i = hash(matricula);
    No *atual = t->tabela[i];
    No *anterior = NULL;

    while(atual != NULL){
        if(atual->matricula == matricula){
            if(anterior == NULL){
                t->tabela[i] = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}

void imprimir(TabelaHash *t){
    for(int i = 0; i < TAM; i++){
        printf("[%d]", i);
        for(No *p = t->tabela[i]; p != NULL; p = p->prox){
            printf(" -> (%d: %.1f)", p->matricula, p->nota);
        }
        printf(" -> NULL\n");
    }
}

void liberar(TabelaHash *t){
    for(int i = 0; i < TAM; i++){
        No *p = t->tabela[i];
        while(p != NULL){
            No *temp = p;
            p = p->prox;
            free(temp);
        }
        t->tabela[i] = NULL;
    }
}