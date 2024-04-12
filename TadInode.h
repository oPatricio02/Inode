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

void newInode(InodeP &i)
{
	time_t tem;
	tm *inTempo;
	
	time(&tem);
	inTempo = localtime(&tem);
	
	//Pegar horario
	data[0] = inTempo->tm_hour;
	data[1] = inTempo->tm_min;
	data[2] = inTempo->tm_mday;
	data[3] = inTempo->tm_mon+1;
	data[4] = inTempo->tm_year+1900;
	
	i.permissoes[0] = '-';
	i.permissoes[1] = 'r';
	i.permissoes[2] = 'w';
	i.permissoes[3] = 'x';
	i.permissoes[4] = 'r';
	i.permissoes[5] = 'w';
	i.permissoes[6] = 'x';
	i.permissoes[7] = 'r';
	i.permissoes[8] = 'w';
	i.permissoes[9] = x;
	i.permissoes[10] = '\0';
	
}

void newInodeD(InodeP &i)
{
	time_t tem;
	tm *inTempo;
	
	time(&tem);
	inTempo = localtime(&tem);
	
	//Pegar horario
	data[0] = inTempo->tm_hour;
	data[1] = inTempo->tm_min;
	data[2] = inTempo->tm_mday;
	data[3] = inTempo->tm_mon+1;
	data[4] = inTempo->tm_year+1900;
	
	i.permissoes[0] = 'd';
	i.permissoes[1] = 'r';
	i.permissoes[2] = 'w';
	i.permissoes[3] = 'x';
	i.permissoes[4] = 'r';
	i.permissoes[5] = 'w';
	i.permissoes[6] = 'x';
	i.permissoes[7] = 'r';
	i.permissoes[8] = 'w';
	i.permissoes[9] = x;
	i.permissoes[10] = '\0';
	
}
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
	int cont;
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
	int numbloco;
	
	if(s.atual.cont<=9)
	{
		numbloco = retira(&p);
		Diretorio dir = new Diretorio;
		strcpy(dir.nome,nome);
		dir.cont=0;
		
		s.atual.ed[s.atual.cont].numBlocoInode=numbloco;
		strcpy(s.atual.ed[s.atual.cont].nome,nome);
		s.atual.cont++;
		
		InodeP inode = new InodeP;
		newInodeD(&inode);
		
		s.disco.blocos[numbloco].tipo = 'I';
		s.disco.blocos[numbloco].inodeP = inode;
			
	}
	else
		printf("Diretorio cheio!\n");
	
		
}

void removedir(*char nome,Sistema s, TpPilha &p){
	
	
	
}

//criar um arquivo regular
void touch(*char nome, Sistema s, TpPilha &p,int tamanho)
{ 
	int qtdb = tamanho/10; //Cada bloco cabe 10 Bytes.	
	int pos,i =0;
	if(qtdb >0)
	{
		if(s.atual.cont<=9)
		{
			strcpy(s.atual.ed[s.atual.cont].nome,nome);
			pos = retira(&p);
			s.atual.ed[s.atual.cont].numBlocoInode = pos; 
			s.atual.cont++;
			
			InodeP inode = new InodeP;
			inode.tamanho = qtdb;
			newInode(&inode);
			
			s.disco.blocos[pos].tipo = 'I';
			s.disco.blocos[pos].inodeP = inode; 
			
			while(i<qtdb && i<5)	//Enquanto estiver nos blocos normais, apos cria InodeSimples
			{
				pos = retira(&p);
				inode.blocoArq[i] = pos;
				s.disco.blocos[pos].tipo = 'A';
				
				i++;
			}
			qtdb-=5;
			InodeSimples inodeS = new InodeSimples;
			pos = retira(&p);
			inode.BcIndireto = pos;
			s.disco.blocos[pos].tipo = 'I';
			s.disco.blocos[pos].inodeS = inodeS;
		
			i = 0;
			while(i<qtdb && i<5)   //Inode Simples
			{
				pos = retira(&p);
				inodeS.blocos[i] = pos;
				s.disco.blocos[pos].tipo = 'A';
				i++;
			}
			qtdb-=5;
			
			InodeSimples inodeD = new InodeSimples;
			pos = retira(&p);
			inode.BcDuplo = pos;
			s.disco.blocos[pos].tipo = 'I';
			s.disco.blocos[pos].inodeS = inodeD;
		
			i = 0;
			while(i<5 && i<qtdb)  	//Inode Duplo
			{
				pos = retira(&p);
				inodeD.blocos[i] = pos;
				s.disco.blocos[pos].tipo = 'I';
				InodeSimples inodeS = new InodeSimples;
				s.disco.blocos[pos].inodeS = inodeS;
				for(int j = 0;j<5  && j < qtdb;j++,qtdb--)
				{
					pos = retira(&p);
					inodeS.blocos[j] = pos;
					s.disco.blocos[pos].tipo = 'A';
				}
				i++;
			}
			
			//Inode Triplo
			
			
		}
		else
		{
			printf("Diretorio cheio!\n");
		}
	}
	
}

void remove(*char nome,Sistema s,TpPilha &p){ //remove um arquivo
	bool flag = false;
	int i =0,pos,aux,tam;
	InodeP inode;
	while(i<s.atual.cont && strcmp(s.atual.ed[i].nome, nome)!="0")
		i++;
	if(strcmp(s.atual.ed[i].nome, nome)=="0")
	{
		pos = s.atual.ed[i].numBlocoInode;
		inode = s.disco.blocos[pos].inodeP;
		tam = inode.tamanho;
		for(int j=0;j<5 && j<tam;j++,tam--)
		{
			aux = inode.blocoArq[j];
			s.disco.blocos[aux].tipo = 'F';
			insere(&p,aux);
		}	
		
		aux = inode.BcIndireto;
		InodeSimples inodeS = s.disco.blocos[aux].inodeS;
		s.disco.blocos[aux].tipo = 'F';
		insere(&p,aux);
		
		for(int j=0;j<5 && j<tam; j++,tam--)
		{
			aux = inodeS.blocos[j];
			s.disco.blocos[aux].tipo = 'F';
			insere(&p,aux);
		}
		
		aux = inode.BcDuplo;
		InodeSimples inodeD = s.disco.blocos[aux].inodeS;
		s.disco.blocos[aux].tipo = 'F';
		insere(&p,aux);
		
		i = 0;
		while(i<5 && i<tam)
		{
			aux = inodeD.blocos[i];
			InodeSimples inodeSi = s.disco.blocos[aux].inodeS;
			s.disco.blocos[aux].tipo = 'F';
			insere(&p,aux);
			for(int j =0;j<5 && j<tam;j++,tam--)
			{
				aux = inodeSi.blocos[j];
				s.disco.blocos[aux].tipo = 'F';
				insere(&p,aux);
			}
			
			i++;
			tam --;
		}	
	}
	else
		printf("Arquivo nao encontrado!\n");
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
		printf("Diretorio não existe\n");
	}
}

void cdponto(PilhaDir &pdir, Sistema &s){
	Diretorio aux;
	
	if(pdir.Topo!=0){ //verifica se não é o diretório raiz
		aux = retiraDir(pdir);
		s.atual = aux;
	}
	
}
