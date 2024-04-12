#include"pilha.h"

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
	int cont
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

void IniciarSistema(Sistema &sis,Disco &d,int qtd, PilhaDir &pdir, TpPilha &p)
{
	IniciaDisco(&d,qtd);
	makedir("/", sis, p); //Criar uma função para criar o raiz
	insereDir(pdir, dir);
	sis.disco = &d;
	sis.atual = &dir;
	
}

int primeiroEDlivre()

//Operações


void visualize(*char nome){

}

void list(Sistema s){
	int i;
	for(i=0; i<10; i++){
		printf("%s/n",s.atual.ed[i].nome)
	}
}

void listL(Sistema s){
	int i;
	
	for(i=0; i<10; i++){
		printf("%s, %d, %s, %s/n",
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.permissoes,
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.tamanho,
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.data,
		s.atual.ed[i].nome)
	}
}

void makedir(*char nome, Sistema s, TpPilha &p)
{	
	int numbloco = retira(p);
	Diretorio dir = new Diretorio;
	strcpy(dir.nome,nome);
	dir.cont=0;
	s.atual.ed[s.atual.cont].numBlocoInode=numbloco;
	strcpy(s.atual.ed[s.atual.cont].nome,nome);
	s.atual.cont++;
}

void removedir(*char nome){
	
}

void touch(*char nome, Sistema s, TpPilha &p{ //criar um arquivo regular
	int numbloco = retira(p);
	s.atual.ed[s.atual.cont].numBlocoInode=numbloco;
	strcpy(s.atual.ed[s.atual.cont].nome,nome);
	s.atual.cont++;
}

void remove(*char nome){ //remove um arquivo
	int i;
	for{i=0; i<s.atual.cont; i++}{
		if(strcmp(s.atual.ed[i].nome, nome)=="0"){
			
		}
	}
}

void cd(Sistema &s, PilhaDir &pdir, *char nome){
	int i;
	bool flag = false;
	int aux;
	for(i=0; i<10; i++){
		if(strcmp(s.atual.ed[i].nome,nome)=="0")
		{
			flag = true;
			aux = s.atual.ed[i].numblocoinode;
		}
	}
	if(flag){
		insereDir(pdir, s.atual);
		s.atual = s.disco.blocos[aux].arq;
	}
	else{
		printf("Diretorio não existe");
	}
}

void cdponto(PilhaDir &pdir, Sistema &s){
	Diretorio aux;
	
	if(pdir.Topo!=0){ //verifica se não é o diretório raiz
		aux = retiraDir(pdir);
		s.atual = aux;
	}
	
}
