
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
	EntradaDiretorio ed[10];
};


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
	TpPilha livres;
	LinkSimbolico link; 
};


struct Disco{
	
	
};
