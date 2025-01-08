#include <stdio.h>  //biblioteca de comunicacao com o usuario
#include <stdlib.h>  //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //funcao responsavel por cadastrar o usuario no sistema
{
	//inicio craiacao de variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // final da funcao variavel/string
   
   printf("digite o cpf a ser cadstrado: "); //coletando informacao do usuario
   scanf("%s", cpf); //%s sao string
   
   strcpy(arquivo, cpf); //responsavel por copiar os valores das string
   
   FILE *file; // cria o arquivo
   file = fopen(arquivo, "w"); //cria o arquivo
   fprintf(file,cpf); // salvoo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado: ");
   scanf("%s" ,nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o sobrenome a ser cadastrado: ");
   scanf("%s" ,sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o seu cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");    
}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
    
	char cpf [40];
	char conteudo [200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
    {
    	printf("nao foi possivel abrir o arquivo, nao localizado! .\n");
	}
    while(fgets(conteudo,200, file) != NULL)
    {
    	printf("\n essas sao as informacoes do usuario: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	
	system("pause");
}



int deletar()
{
	char cpf[40];
	
    printf("digite o cpf a ser deletado:");
	scanf("%s" , cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usuario nao se encontra no sistema! .\n");
		system("pause");
	}
	
		
}

int main()
{
    int opcao=0; //definindo variaveis
    int laco=1;

    for(laco=1;laco=1;)
    {
	
        system("cls");
	
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
      	printf("#### cartório da EBAC ### \n\n"); //inicio do menu
    	printf("esolha a opção desejada do menu: \n\n");
	    printf("\t1 - registra nomes \n");
     	printf("\t2 - consultar nomes \n");
     	printf("\t3 - deletar nomes \n\n"); //final do menu
        printf("\t4 - sair do sistema\n\n");
		printf("opcao:"); //fim do menu
    
        scanf("%d", &opcao); //armazenando a escolha do usuario
    
        system("cls"); //responsavel por limpar a tela
        
        
        switch(opcao) //inicio das funcoes de menu
        {
        	case 1:
            registro(); //chamada de funcao
        	break;
        	
        	case 2:
        	consulta();
    	    break;
    	    
    	    case 3:
    	    deletar();
		    break;
		   
		    case 4:
		    printf("obrigado por ultilizar o sistema \n");	
		    return 0;
		    break;
			
			default:
		    
		    printf("essa opcao nao esta disponivel!\n");  //final da selecao
	        system("pause"); 
	        break;
		}
    
       
    }
}

