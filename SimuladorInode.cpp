#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"conio2.h"
#include<string.h>
#include"pilha.h"
#include"PilhaDiretorio.h"
#include"TadInode.h"

char  menu(char caminho[])
{
    clrscr();
    printf("%s",caminho);
    printf("\n1 - cd");
    printf("\n2 - cd ..");
    printf("\n3 - mkdir (Criar Diretorio)");
    printf("\n4 - rmdir (Remover Diretorio)");
    printf("\n5 - ls (listar)");
    printf("\n6 - ls -l (listara)");
    printf("\n7 - touch (Criar Aquivo)");
    printf("\n[ESC] - Sair\n");
    printf("\nDigite a opcao desejada: \n");
    return getche();
}


int main()
{
	int tam;
	char opcao;
	char comando[100], *linhacmd, operacao[50], nome[100], caminho[1000] = "~/";
	TpPilha p;
	PilhaDir pdir;
	Disco d;
	Sistema s;
	inicializa(p, 1000);
	inicializaDir(pdir);
	IniciarSistema(s, d, 1000, pdir, p);
	
	do
    {
    	opcao=menu(caminho);
    	
        switch(opcao)
        {
        case '1':
            printf("\nInforme o nome do diretório\n");
        	scanf("%s",&nome);
        	linhacmd = cd(s, pdir, nome);
        	if(strcmp(linhacmd,"")!=0){
        		strcat(caminho, linhacmd);
        	}
        	else{
        		getch();	
        	}
            break;
        case '2':
        	cdponto(pdir,s);
            break;
        case '3':
        	printf("\nInforme o nome do diretorio a ser criado\n");
        	scanf("%s",&nome);
        	makedir(nome, s, p);
        	
            break;
        case '4':
        	printf("\nInforme o nome do diretorio a ser deletado\n");
        	scanf("%s",&nome);
        	removedir(nome,s,p);
            break;
        case '5':
        	list(s);
        	getch();
            break;
        case '6':
        	listL(s);
        	getch();
            break;
        case '7':
        	printf("\nInforme o nome do arquivo\n");
        	scanf("%s", &nome);
        	printf("\nInforme o tamanho dele em Bytes\n");
        	scanf("%d", &tam);
        	touch(nome,s,p,tam);
        	getch();
        	break;
        }
    }while(opcao!=27);
	
}
/*
int main(){
	bool parar = false;
	char comando[100], *linhacmd, operacao[50], nome[100], caminho[1000];
	TpPilha p;
	PilhaDir pdir;
	Disco d;
	Sistema s;
	inicializa(p, 1000);
	inicializaDir(pdir);
	IniciarSistema(s, d, 1000, pdir, p);
	
	strcpy(caminho, "~/");
	while(!parar){
		
		printf("\n%s", caminho);
		
		scanf("%s", &comando);
		
		linhacmd = strtok(comando, " ");
		while(linhacmd!=NULL){
			strcpy(operacao,linhacmd);
			linhacmd = strtok(NULL, " ");
			strcpy(nome,linhacmd);
		}
		printf("%s\n", operacao);
		printf("%s", nome);
	}
	
	return 0;
}
*/
