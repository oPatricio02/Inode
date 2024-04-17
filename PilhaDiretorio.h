
struct EntradaDiretorio 
{
	char nome[50];
	int numBlocoInode;
};

struct Diretorio
{
	char nome[50];
	EntradaDiretorio ed[10];
	int cont;
};

struct PilhaDir
{
    int TOPO;
    int qtd;
    Diretorio *PILHA;
};

void inicializaDir(PilhaDir &p);
void insereDir(PilhaDir &p, int Elemento);
Diretorio retiraDir(PilhaDir &p);
Diretorio elementoTopo(PilhaDir p);
int cheiaDir(int topo);
int vaziaDir(int topo);


void inicializaDir(PilhaDir &p,int qtde)
{
	p.PILHA = new Diretorio[qtde];
    p.TOPO = -1;
    p.qtd = qtde;
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

int cheiaDir(PilhaDir p)
{
    return p.TOPO ==p.qtd-1;
}

int vaziaDir(PilhaDir p )
{
    return p.TOPO == -1;
}



