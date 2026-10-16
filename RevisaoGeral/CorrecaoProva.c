// #include <stdlib.h>
//QUESTAO 2
// #define MAX 4
// 
// struct fila{
//     float dados[MAX];
//     int qtd;
//     int final;
//     int inicio;
// };
// typedef struct fila* Fila;
// 
// Fila cria_fila(){
//     Fila f = malloc(sizeof(Fila));
//     if(f == NULL) return NULL;
//     f->qtd = 0;
//     f->inicio = 0;
//     f->final = 0;
//     return f;
// }
// 
// int enfileira(Fila f, float valor){
//     if(f == NULL) return 0;
//     if(f->qtd == MAX) return 0;
//     f->dados[f->final] = valor;
//     f->final = (f->final + 1) % MAX;
//     f->qtd++;
//     return 1;
// }
// 
// int desenfileira(Fila f){
//     if(f == NULL) return 0;
//     if(f->qtd  == 0) return 0;
//     float valor_remover = f->dados[f->inicio];
//     f->inicio = (f->inicio + 1) % MAX;
//     f->qtd--;
//     return valor_remover;
// }
// 
// float consulta_inicio(Fila f){
//     if(f == NULL || f->qtd == 0) return 0;
//     return f->dados[f->inicio];
// }
//QUESTAO 4
// typedef struct elem{
//     int valor;
//     struct elem* prox;
// }Elem;
// 
// typedef struct lista{
//     Elem* inicio;
// }*Lista;
// 
// int inserir_posicao(Lista li, int valor, int pos){
//     if(li == NULL || pos < 0) return 0;
// 
//     Elem* novo = malloc(sizeof(Elem));
//     if(novo == NULL) return 0;
//     novo->valor = valor;
// 
//     if(pos == 0){
//         novo->prox = li->inicio;
//         li->inicio = novo;
//         return 1;
//     }
// 
//     Elem *aux = li->inicio;
//     int i = 0;
//     while(aux != NULL && pos - 1){
//         aux = aux->prox;
//         i++;
//     }
// 
//     if(aux == NULL){
//         free(novo);
//         return 0;
//     }
// 
//     novo->prox = aux->prox;
//     aux->prox = novo;
//     return 1;
// }
// QUESTAO 5
// float maior_valor(Pilha p){
//     if(p == NULL || tamanho(p) == 0) return 0;
// 
//     Pilha aux = cria_pilha();
//     float maior = peek(p);
// 
//     // passa tudo de p para aux, guardando o maior
//     while(tamanho(p) > 0){
//         float v = peek(p);
//         if(v > maior) maior = v;
//         push(aux, v);
//         pop(p);
//     }
// 
//     // devolve tudo de aux para p (inverte de novo, restaurando a ordem)
//     while(tamanho(aux) > 0){
//         push(p, peek(aux));
//         pop(aux);
//     }
// 
//     return maior;
// }