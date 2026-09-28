#include <stdlib.h>
struct elem{
    int valor;
    Elem* prox;
};
typedef struct elem Elem;

struct lista{
    int qtd; //contador dos elementos da lista
    Elem* inicio;
};
typedef struct lista* Lista;

Lista criar(){
    Lista li = malloc(sizeof(struct lista));
    if (li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}

int inserir_inicio(Lista li, int valor_inserir){
    Elem* no = malloc(sizeof(Elem)); // declaração do no
    if (no != NULL){
        no->valor = valor_inserir;
        no->prox = li->inicio;
        li->inicio = no; //inicio esta como varivel de ponteiro, logo ele recebe o nó inteiro como endereço
        li->qtd++;
        return 1;
    }
    return 0;
}
int inserir_final(Lista li, int valor_inserir){
    Elem* no = malloc(sizeof(Elem));
    if(no != NULL){
        no->valor = valor_inserir;
        no->prox = NULL;
        if(li->inicio == NULL){
            li->inicio = no;
            li->qtd++;
            return 1;
        }
        Elem* aux = li->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        li->qtd++;
        return 1;
    }
    return 0;
}


int remover_inicio(Lista li){
    if (li->qtd == 0){
        return 0;
    }
    Elem* aux= li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;
    return 1;
}
// int remover_inicio(Lista li, int *valor_removido){
//     if (li->inicio != NULL){
//         Elem* aux = li->inicio;
//         *valor_removido = aux->valor;
//         li->inicio = aux->prox;
//         free(aux);
//         li->qtd--;
//         return 1;
//     }
//     return 0;
// }

int acessar_inicio(Lista li, int *valor_inicio){
    if(li->inicio != NULL){
        *valor_inicio = li->inicio->valor;
        return 1;
    }
    return 0;
}

int remover_final(Lista li){
    if (li->qtd == 0){
        return 0;
    }
    Elem* aux = li->inicio;
    if(aux->prox == NULL){
        free(aux);
        li->inicio = NULL;
        li->qtd--;
        return 1;
    }
    Elem* ant = aux;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    free(aux);
    ant->prox = NULL;
    li->qtd--;
    return 1;
}
// int remover_final(Lista li, int *valor_removido){
//     if (li->inicio != NULL){
//         if(li->inicio->prox == NULL){
//             *valor_removido = li->inicio->valor;
//             free(li->inicio);
//             li->inicio = NULL;
//         }else{
//             Elem* aux = li->inicio;
//             while(aux->prox->prox != NULL){
//                 aux = aux->prox;
//             }
//             *valor_removido = aux->prox->valor;
//             free(aux->prox);
//             aux->prox = NULL;
//         }
//         li->qtd--;
//         return 1;
//     }
//     return 0;
// } 

int aceessar_final(Lista li, int *valor_final){
    if(li->inicio != NULL){
        if(li->inicio->prox == NULL){
            *valor_final = li->inicio->valor;
            return 1;
        }else{
            Elem* aux = li->inicio;
            while(aux->prox->prox != NULL){
                aux = aux->prox;
            }
            *valor_final = aux->prox->valor;
            return 1;
        }
    }
}
int buscar_por_valor(Lista li, int valor_buscado, int *posicao_encontrada){
    Elem* aux = li->inicio;
    int pos = 0;

    while(aux != NULL){
        if(aux->valor == valor_buscado){
            *posicao_encontrada = pos;
            return 1;
        }
        aux = aux->prox;
        pos++;
    }
    return 0;
}
int buscar_por_posicao(Lista li, int posicao, int *valor_encontrado){
    if (li->inicio != NULL){
        if(posicao>= 0 && posicao<= li->qtd-1){
            Elem* aux = li->inicio;
            int i = 0;
            while(i != posicao){
                aux = aux->prox;
                i++;
            }
            *valor_encontrado = aux->valor;
            return 1;
        }
    }
    return 0;
}

void destruir(Lista li){
    if(li == NULL){
        return;
    }
    Elem* aux = li->inicio;
    while(aux->prox != NULL){
        Elem* atual = aux;
        aux->prox;
        free(atual);
    }
    free(aux);
    free(li);
}
// void destruir(Lista li){
//    if(li->inicio != NULL){
//        Elem* aux = li->inicio;
//        while(aux != NULL){
//            Elem* proximo = aux->prox;
//            free(aux);
//            aux = proximo;
//        }
//    }
//    free(li);
// } 