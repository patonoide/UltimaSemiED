

#define BRANCO (0)
#define CINZA (1)
#define PRETO (2)

struct grafo{
    int **matriz;
    int vertices;
};
typedef struct grafo Grafo;

struct resultado{
    int *cor;
    int *distancia;
    int *predecessor;
};
typedef struct resultado Res;

struct aresta{
    int predecessor;
    int sucessor;
};
typedef struct aresta Aresta;


struct fila{
    int n;
    int ini;
    int vet[10];
};
typedef struct fila Fila;


Fila *criaFila();
void insereFinal(Fila* f, int v);
int retiraInicio(Fila * f);
Grafo *criaGrafo(int v);
Res *bfs(Grafo *g, int origem);
Res *criaResultado(int v);
Aresta *criaAresta(Grafo *g);