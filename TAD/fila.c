#define MAX 4
#include <stdlib.h>

struct fila{
    int dados[MAX];
    int inicio;
    int final;
};
typedef struct fila* Fila; 

Fila criar(){
    Fila f = malloc(sizeof(struct fila));
    if (f != NULL){
        f->inicio = 0;
        f->final = 0;
    }

    
}
int main(){
    
    return 0;

}