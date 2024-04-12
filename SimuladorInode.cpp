#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"meuconio.h"
#include<string.h>
#include"pilha.h"
#include"TadInode.h"
#include"PilhaDiretorio.h"

char  menu(void)
{
    clrscr();
    printf("\n1 - Inicializa Disco");
    printf("\n2 - Criar Arquivo");
    printf("\n3 - Criar Diretorio");
    printf("\n4 - Selecionar Bloco defeituoso");
    printf("\n5 - Libera disco");
    printf("\n[ESC] - Sair\n");
    printf("\nDigite a opcao desejada: \n");
    
    return getche();
}


int main()
{
	int tam;
	char opcao;
	Disco disco;
	
	do
    {
    	opcao=menu();
    	
        switch(opcao)
        {
        case '1':
        	clrscr();
            printf("Selecione o tamanho do Disco desejado:\n");
			scanf("%d\n",&tam);
			IniciaDisco(disco,tam);
            break;
        case '2':
        	clrscr();
			printf("Informe o nome do arquivo e o tamanho\n");
			char nome[50];
			int qtdb;
			fflush(stdin);
			scanf("%s",&nome);
			printf("Informe o tamanho em bytes\n");
			scanf("%d\n",&qtdb);
            break;
        case '3':
        	clrscr();
            getch();
            break;
        case '4':
        	
        	clrscr();
            getch();
            break;
        case '5':
        	LiberaDisco(disco); 
        	clrscr();
            break;
        }
    }while(opcao!=27);
	
}
