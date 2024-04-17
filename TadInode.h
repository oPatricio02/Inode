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
	i.data[0] = inTempo->tm_hour;
	i.data[1] = inTempo->tm_min;
	i.data[2] = inTempo->tm_mday;
	i.data[3] = inTempo->tm_mon+1;
	i.data[4] = inTempo->tm_year+1900;
	
	i.permissoes[0] = '-';
	i.permissoes[1] = 'r';
	i.permissoes[2] = 'w';
	i.permissoes[3] = 'x';
	i.permissoes[4] = 'r';
	i.permissoes[5] = 'w';
	i.permissoes[6] = 'x';
	i.permissoes[7] = 'r';
	i.permissoes[8] = 'w';
	i.permissoes[9] = 'x';
	i.permissoes[10] = '\0';
	
	
}

void newInodeD(InodeP &i)
{
	time_t tem;
	tm *inTempo;
	
	time(&tem);
	inTempo = localtime(&tem);
	
	//Pegar horario
	i.data[0] = inTempo->tm_hour;
	i.data[1] = inTempo->tm_min;
	i.data[2] = inTempo->tm_mday;
	i.data[3] = inTempo->tm_mon+1;
	i.data[4] = inTempo->tm_year+1900;
	
	i.permissoes[0] = 'd';
	i.permissoes[1] = 'r';
	i.permissoes[2] = 'w';
	i.permissoes[3] = 'x';
	i.permissoes[4] = 'r';
	i.permissoes[5] = 'w';
	i.permissoes[6] = 'x';
	i.permissoes[7] = 'r';
	i.permissoes[8] = 'w';
	i.permissoes[9] = 'x';
	i.permissoes[10] = '\0';
	
}
struct InodeSimples
{
	int blocos[5];
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

void defeituoso(Disco &d,int num) //Correto
{
	d.blocos[num].tipo = 'B';
}


struct Sistema
{
	Disco disco;
	Diretorio atual;
	int diretorioPai;	
};

void IniciarSistema(Sistema &sis,Disco &d,int qtd, PilhaDir &pdir, TpPilha &p)  //Correto
{
    IniciaDisco(d,qtd);
    Diretorio raiz;
    raiz.cont = 0;
    strcpy(raiz.nome, "/");
    sis.atual = raiz;
    insereDir(pdir, raiz);
    sis.disco = d;
}

//Operações

void list(Sistema s){ //Correto
	for(int i=0; i<s.atual.cont; i++){
		printf("\n%s",s.atual.ed[i].nome);
	}
}

void listL(Sistema s){  //Correto
	int i;
	
	for(i=0; i<s.atual.cont; i++){
		printf("\n%s, %d, %d %d %d, %s",
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.permissoes,
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.tamanho*10,
		
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.data[2],
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.data[3],
		s.disco.blocos[s.atual.ed[i].numBlocoInode].inodeP.data[4],
		s.atual.ed[i].nome);
	}
}

void statusBloco(Sistema s)
{
	for(int i=0;i<s.disco.qtdBloco;i++)
		printf("%d[%c]| ",i,s.disco.blocos[i].tipo);
}

void espacoLivre(Sistema s)
{
	int livre =0,ocupados = 0 ;
	for(int i = 0;i<s.disco.qtdBloco;i++)
	{
		if(s.disco.blocos[i].tipo == 'F')
			livre++;
		else
			ocupados++;
	}
	
	printf("Bytes Livres: %d\n",livre*10);
	printf("Bytes Ocupados: %d\n",ocupados*10);
		
}



void makedir(char *nome, Sistema &s, TpPilha &p){	//Correto
	int numbloco;
	
	if(s.atual.cont<=9)
	{
		numbloco = retira(p);
		Diretorio dir;
		strcpy(dir.nome,nome);
		dir.cont=0;
		
		s.atual.ed[s.atual.cont].numBlocoInode=numbloco;
		strcpy(s.atual.ed[s.atual.cont].nome,nome);
		s.atual.cont++;
		
		InodeP inode;
		newInodeD(inode);
		
		s.disco.blocos[numbloco].tipo = 'I';
		s.disco.blocos[numbloco].inodeP = inode;
		s.disco.blocos[numbloco].arq = dir;
			
	}
	else{
		printf("Diretorio cheio!\n");
		getch();
	}
		
}


void reordena(Sistema &s,int pos) //Correto
{
	int tl = s.atual.cont;
	for(int i= pos;i<tl;i++)
	{
		s.atual.ed[i].numBlocoInode = s.atual.ed[i+1].numBlocoInode;
		strcpy(s.atual.ed[i].nome,s.atual.ed[i+1].nome); 
	}
}

void removedir(char *nome,Sistema &s, TpPilha &p){ //Correto
	
	int i=0;
	while(i<s.atual.cont && strcmp(s.atual.ed[i].nome,nome) != 0 )	
		i++;
	if(strcmp(s.atual.ed[i].nome,nome) == 0)
	{
		int pos = s.atual.ed[i].numBlocoInode; //numero do bloco
		Diretorio dir = s.disco.blocos[pos].arq;
		if(dir.cont == 0)
		{
			
			s.disco.blocos[pos].tipo = 'F';
			insere(p,pos);
			strcpy(dir.nome,"");
			strcpy(s.atual.ed[i].nome,"");
			reordena(s,i);
			s.atual.cont--;
		}
		else
		{
			printf("Diretorio cheio!\n");
			getch();
		}
		
	}
	else
	{
		printf("Diretorio nao encontrado!");
		getch();
	}
		
		
}

//criar um arquivo regular -  Completo aparentemente
void touch(char *nome, Sistema &s, TpPilha &p,int tamanho)
{ 
	int qtdb = tamanho/10; //Cada bloco cabe 10 Bytes.	
	int pos,i =0;
	if(qtdb >0 && s.disco.qtdBloco> qtdb)  //Corrigir flag
	{
		if(s.atual.cont<=9)
		{
			strcpy(s.atual.ed[s.atual.cont].nome,nome);
			pos = retira(p);
			s.atual.ed[s.atual.cont].numBlocoInode = pos; 
			s.atual.cont++;
			
			
			InodeP inode;
			inode.tamanho = qtdb;
			newInode(inode);
			
			s.disco.blocos[pos].tipo = 'I';
			s.disco.blocos[pos].inodeP = inode; 
			
			while(i<5 && qtdb>0)	//Enquanto estiver nos blocos normais, apos cria InodeSimples
			{
				pos = retira(p);
				inode.blocoArq[i] = pos;
				s.disco.blocos[pos].tipo = 'A';
				
				i++;
				qtdb--;
			}
			if(qtdb>0)
			{
				InodeSimples inodeS;
				pos = retira(p);
				inode.BcIndireto = pos;
				s.disco.blocos[pos].tipo = 'I';
				s.disco.blocos[pos].inodeS = inodeS;
			
				i = 0;
				while(i<5 && qtdb>0)   //Inode Simples
				{
					pos = retira(p);
					inodeS.blocos[i] = pos;
					s.disco.blocos[pos].tipo = 'A';
					i++;
					qtdb--;
				}
				
				if(qtdb >0)
				{
					
					InodeSimples inodeD;
					pos = retira(p);
					inode.BcDuplo = pos;
					s.disco.blocos[pos].tipo = 'I';
					s.disco.blocos[pos].inodeS = inodeD;
				
					i = 0;
					while(i<5 && qtdb>0)  	//Inode Duplo
					{
						pos = retira(p);
						inodeD.blocos[i] = pos;
						s.disco.blocos[pos].tipo = 'I';
						InodeSimples inodeS;
						s.disco.blocos[pos].inodeS = inodeS;
						for(int j = 0;j<5  && j < qtdb;j++,qtdb--)
						{
							pos = retira(p);
							inodeS.blocos[j] = pos;
							s.disco.blocos[pos].tipo = 'A';
						}
						i++;
						qtdb--;
					}
					
					//Inode Triplo
				}
				
				
			}
			
			
			
		}
		else
		{
			printf("Diretorio cheio!\n");
			getch();
		}
	}
	else
	{
		printf("Espaco de armazenamento insuficiente!\n");
		getch();
	}
	
	
}

void remove(char *nome,Sistema s,TpPilha &p){ //Falta completar
	bool flag = false;
	int i =0,pos,aux,tam;
	InodeP inode;
	while(i<s.atual.cont && strcmp(s.atual.ed[i].nome, nome)!= 0)
		i++;
	if(strcmp(s.atual.ed[i].nome, nome)== 0)
	{
		pos = s.atual.ed[i].numBlocoInode;
		inode = s.disco.blocos[pos].inodeP;
		tam = inode.tamanho;
		for(int j=0;j<5 && j<tam;j++,tam--)
		{
			aux = inode.blocoArq[j];
			s.disco.blocos[aux].tipo = 'F';
			insere(p,aux);
		}	
		
		aux = inode.BcIndireto;
		InodeSimples inodeS = s.disco.blocos[aux].inodeS;
		s.disco.blocos[aux].tipo = 'F';
		insere(p,aux);
		
		for(int j=0;j<5 && j<tam; j++,tam--)
		{
			aux = inodeS.blocos[j];
			s.disco.blocos[aux].tipo = 'F';
			insere(p,aux);
		}
		
		aux = inode.BcDuplo;
		InodeSimples inodeD = s.disco.blocos[aux].inodeS;
		s.disco.blocos[aux].tipo = 'F';
		insere(p,aux);
		
		i = 0;
		while(i<5 && i<tam)
		{
			aux = inodeD.blocos[i];
			InodeSimples inodeSi = s.disco.blocos[aux].inodeS;
			s.disco.blocos[aux].tipo = 'F';
			insere(p,aux);
			for(int j =0;j<5 && j<tam;j++,tam--)
			{
				aux = inodeSi.blocos[j];
				s.disco.blocos[aux].tipo = 'F';
				insere(p,aux);
			}
			
			i++;
			tam --;
		}	
	}
	else
		printf("Arquivo nao encontrado!\n");
}

void remove_palavra(char * frase, char * palavra)
{
    int tamanhoFrase = strlen(frase);
    int tamanhoPalavra = strlen(palavra);
    char * ponteiro = strstr(frase, palavra);
    if(ponteiro)
    {    
        int posicao = (ponteiro - frase);
		ponteiro = ponteiro + tamanhoPalavra;                
        int i;
        for(i = 0; i < strlen(ponteiro); i++)
            frase[posicao + i] = ponteiro[i]; 

       frase[posicao + i] = 0;      
    }   
}

char* cd(Sistema &s, PilhaDir &pdir, char *nome){		//Aparentemente correto
	int i;
	bool flag = false;
	int aux;
	for(i=0; i<10; i++){
		if(strcmp(s.atual.ed[i].nome,nome)== 0)
		{
			flag = true;
			aux = s.atual.ed[i].numBlocoInode;
		}
	}
	if(flag){
		insereDir(pdir, s.atual);
		s.atual = s.disco.blocos[aux].arq;
		return s.atual.nome;
	}
	else{
		printf("Diretorio nao existe\n");
		return NULL;
	}
}

void cdponto(PilhaDir &pdir, Sistema &s){			//Aparentemente correto
	Diretorio aux;
	
	if(pdir.TOPO!=0){ //verifica se não é o diretório raiz
		aux = retiraDir(pdir);
		s.atual = aux;
	}
	
}
