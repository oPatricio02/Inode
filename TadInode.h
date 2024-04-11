
struct InodeP
{
	int data[5];
	int tamanho;
	char permissoes[11];
	int blocoArq[5];
	int BcIndireto;
	int BcDuplo;
	int BcTriplo;
};
struct InodeSimples
{
	int blocos[5];
};

struct EntradaDiretorio
{
	char nome[50];
	int numBlocoInode;
};

struct Diretorio
{
	char nome[50];
	EntradaDiretorio ed[10];
};

void novoDiretorio(Diretorio &dir,char nome[])
{
	strcpy(dir.nome,nome);
}

struct LinkSimbolico
{
	char caminhoAbsoluto[50];
};


struct Bloco
{
	char tipo;
	Diretorio arq;
	InodeP inodeP;
	InodeSimples inodeS;
	LinkSimbolico link; 
};



struct Disco{
	int qtdBloco;
	Bloco *blocos;
	TpPilha pilha;
};

void IniciaDisco(Disco &d,int num)
{
	d.qtdBloco = num;
	d.blocos = new Bloco[num];
	inicializa(d.pilha,num);
	for(int i=0;i<num;i++)
		d.blocos[i].tipo = 'F';
	
}
void LiberaDisco(Disco &d) {
    delete[] d.blocos; 
    d.blocos = NULL; 
}

void defeituoso(Disco &d,int num)
{
	d.blocos[num].tipo = 'B';
}

int devolverBloco(Disco &d)
{
	return retira(&d.pilha);
}


struct Sistema
{
	Disco disco;
	Diretorio atual;
	int diretorioPai;	
};

void IniciarSistema(Sistema &sis,Disco &d,Diretorio &dir,int qtd)
{
	IniciaDisco(&d,qtd);
	novoDiretorio(&dir,"/");
	sis.disco = &d;
	sis.atual = &dir;
	
}
