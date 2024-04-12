#define MAXPILHA 1000

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
    Diretorio PILHA[MAXPILHA];
};

void inicializaDir(PilhaDir &p);
void insereDir(PilhaDir &p, int Elemento);
Diretorio retiraDir(PilhaDir &p);
Diretorio elementoTopo(PilhaDir p);
int cheiaDir(int topo);
int vaziaDir(int topo);


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



