#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no* prox;
}No;

typedef struct fila{
    No* inicio;
    No* fim;
}Fila;

// Fila* criar(){
// 
// }
// 
// bool is_empty(Fila* f){
// 
// }
// 
// int enqueue(Fila* f, int valor){
// 
// }
// 
// int dequeue(Fila* f){
// 
// }
