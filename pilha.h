#define MAXPILHA 1000

struct TpPilha
{
    int TOPO;
    int qtd;
    int PILHA[MAXPILHA];
};

//Alterar para a pilha ter o mesmo tamanho do Disco, pois está retornando enddereços de blocos fora do vetor

void inicializa(TpPilha &p, int q);
void insere(TpPilha &p, int Elemento);
int retira(TpPilha &p);
int elementoTopo(TpPilha p);
int cheia(int topo);
int vazia(int topo);
int exibe(TpPilha p);

void inicializa(TpPilha &p,int q)
{
    p.TOPO = -1;
    p.qtd = q;
 	for(int i = 0;i<q;i++)
		insere(p,i);
	
	
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

int exibe(TpPilha p)
{
   while( !vazia(p.TOPO) )
        printf("\n%d",retira(p));
}



