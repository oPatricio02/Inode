
struct TpPilha
{
    int TOPO;
    int qtd;
    int *PILHA;
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
    p.PILHA = new int[q];
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

int cheia(TpPilha p)
{
    return p.TOPO == p.qtd -1;
}

int vazia(TpPilha p)
{
    return p.TOPO == -1;
}

/*int exibe(TpPilha p)
{
   while( !vazia(p.TOPO) )
        printf("\n%d",retira(p));
}*/



