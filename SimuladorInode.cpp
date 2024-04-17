#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<string.h>
#include"pilha.h"
#include"PilhaDiretorio.h"
#include"TadInode.h"

int qtd_espacos(char *str){
    int espacos = 0;
    while(*str){
        if (*str == ' '){
           espacos++;
        }
        str++;
    }
    return espacos;
}

char  menu(char caminho[], char nome[], int &tam, int &aux)
{	
    clrscr();
    char opcao, comando[500];
    printf("%s",caminho);
    fgets(comando, sizeof(comando), stdin);
    remove_palavra(comando, "\n");
    int qtd_strings = qtd_espacos(comando) + 1, i = 0;
    char strings[qtd_strings][strlen(comando)];
    char *pch = strtok (comando," ");
    while (pch != NULL){
        strcpy(strings[i++], pch);
        pch = strtok (NULL, " ");
    }
    
    if(strcmp(strings[0],"cd")==0){
    	opcao = '1';
    	strcpy(nome, strings[1]);
    }
    
    if(strcmp(strings[0],"cd..")==0){
    	opcao = '2';
    }
    
    if(strcmp(strings[0],"mkdir")==0){
    	if(qtd_strings==2){
	    	opcao = '3';
	    	strcpy(nome, strings[1]);	
    	}
    }
    
    if(strcmp(strings[0],"rmdir")==0){
    	if(qtd_strings==2){
	    	opcao = '4';
	    	strcpy(nome, strings[1]);
    	}
	}
	
    if(strcmp(strings[0],"ls")==0){
    	opcao = '5';
    }
    
    if(strcmp(strings[0],"ls")==0 && strcmp(strings[1],"-l")==0){
    	opcao = '6';
    }
    
    if(strcmp(strings[0],"touch")==0){
    	if(qtd_strings==3){
	    	opcao = '7';
	    	strcpy(nome, strings[1]);
	    	tam = atoi(strings[2]);
    	}
    }
    
    if(strcmp(strings[0],"bad")==0){
    	if(qtd_strings==2){
	    	opcao = '8';
	    	aux = atoi(strings[1]);
    	}
	}
    
    
    return opcao;
}


int main()
{
	int tam,aux;
	char opcao;
	char auxnome[100], comando[100], *linhacmd, operacao[50], nome[100], caminho[1000] = "~/";
	printf("Qual o tamanho do disco desejado?\n");
	scanf("%d", &tam);
	if(tam<1000)
	{
		TpPilha p;
		PilhaDir pdir;
		Disco d;
		Sistema s;
		inicializa(p, tam);
		inicializaDir(pdir,tam);
		IniciarSistema(s, d, tam, pdir, p);
		
		do
	    {
	    	opcao=menu(caminho, nome, tam, aux);
	    	
	        switch(opcao)
	        {
	        case '1':
	        	linhacmd = cd(s, pdir, nome);
	        	if(linhacmd != NULL)
	        	{
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
	        	makedir(nome, s, p);
	        	
	            break;
	        case '4':
	        	removedir(nome,s,p);
	            break;
	        case '5':
	        	clrscr();
	        	printf("%s",caminho);
	        	list(s);
	        	getch();
	            break;
	        case '6':
	        	clrscr();
	        	printf("%s",caminho);
	        	listL(s);
	        	getch();
	            break;
	        case '7':
	        	touch(nome,s,p,tam);
	        	break;
	    	case '8':
		    	defeituoso(d,aux);
		    	getch();
	    	break;
	    	case '9':
	    		clrscr();
		    	statusBloco(s);
		    	getch();
	    	break;
	    	case '0':
	    		clrscr();
		    	espacoLivre(s);
		    	getch();
	    	break;
	        }
	    }while(opcao!=27);
	}
	else
		printf("Valor de Blocos indisponiveis!\n");
	
    
	return 0;
}
