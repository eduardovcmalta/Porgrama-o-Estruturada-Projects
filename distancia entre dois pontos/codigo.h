typedef struct ponto Ponto;

Ponto* criar_pontos(float x, float y);
void atualizar_pontos(Ponto*p, float novox, float novoy);
void deletar_pontos(Ponto* p);
float calcular_dois_pontos(Ponto* p1, Ponto* p2);
