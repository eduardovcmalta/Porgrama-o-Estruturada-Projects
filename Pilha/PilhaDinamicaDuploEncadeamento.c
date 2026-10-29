struct elem{
    int valor;
    struct elem *prox;
    struct elem *ant;
};
typedef struct elem Elem;

struct pilha{
    Elem *topo;
};
typedef struct pilha *Pilha;

