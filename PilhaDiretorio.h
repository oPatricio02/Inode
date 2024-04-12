#define MAXPILHA 1000

struct PilhaDir
{
    int TOPO;
    int qtd;
    Diretorio PILHA[MAXPILHA];
};

void inicializaDir(PilhaDir &p);
void insere(PilhaDir &p, int Elemento);
int retira(PilhaDir &p);
int elementoTopo(PilhaDir p);
int cheia(int topo);
int vazia(int topo);
int exibe(PilhaDir p);

void inicializaDir(PilhaDir &p)
{
    p.TOPO = -1;
}

void insereDir(PilhaDir &p, Diretorio Elemento)
{
    p.PILHA[++p.TOPO] = Elemento;
}

Diretorio retiraDir(PilhaDir &p)
{
    return p.PILHA[p.TOPO--];
}

Diretorio elementoTopoDir(PilhaDir p)
{
    return p.PILHA[p.TOPO];
}

int cheiaDir(int topo)
{
    return topo == MAXPILHA-1;
}

int vaziaDir(int topo)
{
    return topo == -1;
}



