#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<string.h>
#include"pilha.h"
#include"PilhaDiretorio.h"
#include"TadInode.h"

char  menu(char caminho[])
{
    clrscr();
    printf("%s\n",caminho);
    printf("\n1 - cd");
    printf("\n2 - cd ..");
    printf("\n3 - mkdir (Criar Diretorio)");
    printf("\n4 - rmdir (Remover Diretorio)");
    printf("\n5 - ls (listar)");
    printf("\n6 - ls -l (listara)");
    printf("\n7 - touch (Criar Aquivo)");
    printf("\n8 - Bloco defeituoso");
    printf("\n[ESC] - Sair\n");
    printf("\nDigite a opcao desejada: \n");
    return getche();
}


int main()
{
	int tam,aux;
	char opcao;
	char auxnome[100], comando[100], *linhacmd, operacao[50], nome[100], caminho[1000] = "~/";
	printf("Qual o tamanho do disco desejado?\n");
	scanf("%d", &tam);
	
	TpPilha p;
	PilhaDir pdir;
	Disco d;
	Sistema s;
	inicializa(p, 1000);
	inicializaDir(pdir);
	IniciarSistema(s, d, tam, pdir, p);
	
	do
    {
    	opcao=menu(caminho);
    	
        switch(opcao)
        {
        case '1':
            printf("\nInforme o nome do diretorio\n");
        	scanf("%s",&nome);
        	linhacmd = cd(s, pdir, nome);
        	if(strcmp(linhacmd,"")!=0){
        		strcat(caminho, linhacmd);
        		strcat(caminho, "/");
        	}
        	else{
        		getch();	
        	}
            break;
        case '2':
        	strcpy(auxnome,s.atual.nome);
        	strcat(auxnome,"/");
        	remove_palavra(caminho, auxnome);
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
        	clrscr();
        	printf("%s\n",caminho);
        	list(s);
        	getch();
            break;
        case '6':
        	clrscr();
        	printf("%s\n",caminho);
        	listL(s);
        	getch();
            break;
        case '7':
        	printf("\nInforme o nome do arquivo\n");
        	scanf("%s", &nome);
        	printf("Informe o tamanho dele em Bytes\n");
        	scanf("%d", &tam);
        	touch(nome,s,p,tam);
        	getch();
        	break;
    	case '8':
	    	printf("\nInforme o numero do bloco\n");
	    	scanf("%d", &aux);
	    	defeituoso(d,aux);
	    	getch();
    	break;
        }
    }while(opcao!=27);
    
	return 0;
}
