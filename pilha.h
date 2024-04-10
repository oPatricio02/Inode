#define MAXPILHA 1000

struct TpPilha
{
    int TOPO;
    int PILHA[MAXPILHA];
};

void inicializa(TpPilha &p);
void insere(TpPilha &p, int Elemento);
int retira(TpPilha &p);
int elementoTopo(TpPilha p);
int cheia(int topo);
int vazia(int topo);
int exibe(TpPilha p);

void inicializa(TpPilha &p)
{
    p.TOPO = -1;
}

void insere(TpPilha &p, int Elemento)
{
    p.PILHA[++p.TOPO] = Elemento;
}

int retira(TpPilha &p)
{
    return p.PILHA[p.TOPO--];
}

int elementoTopo(TpPilha p)
{
    return p.PILHA[p.TOPO];
}

int cheia(int topo)
{
    return topo == MAXPILHA-1;
}

int vazia(int topo)
{
    return topo == -1;
}

void exibe(TpPilha p)
{
   while( !vazia(p.TOPO) )
        printf("\n%d",retira(p));
}



