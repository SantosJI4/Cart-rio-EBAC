#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o Respons�vel por Cadastrar os Usu�rio no sistema 
{
	setlocale(LC_ALL, "portuguese");
	// Inic�o da cria��o vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o vari�veis/string
	
	printf("Digite o CPF a ser Cadastrado:"); //coletando Informa��o dos Usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	
	strcpy(arquivo, cpf);  //respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "W" escrever
	fprintf(file, cpf); // salvo o valor da var�avel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, ","); // colocar algum carectere 
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser Cadastrado: "); 
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, nome);//salva o valor da var�avel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, sobrenome);//salva o valor da var�avel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//cria  o arquivo
	fprintf(file, cargo);//salva o valor da var�avel
	fclose(file);//fecha o arquivo
	
	system("pause");
	



}

int consultar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite seu cpf: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf, "r");// "r" para computador ler
	
	if(file == NULL)
	{
		printf("N�o foi Poss�vel Encontrar o Arquivo, Tente Novamente ou volte para se registrar.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra os
	{
		printf("\nEssas s�o as Infroma��es do Usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		}
	
	system("pause");
	
	
	
}
int deletar() // Deletar Usu�rios
{
	char cpf[40];
	
	printf("Digite seu CPF Que Deseja Deletar: ");
	scanf("%s", cpf);
		
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL)
		{
			remove(cpf);
			printf("Usu�rio Encontrado e Deletado com sucesso!.\n");  // caso o sistema encontre o arquivo
		
		}
    
	else
	
		printf("O Usu�rio N�o se Encontra no Sistema!.\n");
		system("pause"); // caso o sistema n�o encontre o arquivo
	

	
	}





int main()
    {
	
	int opcao=0; //Definindo Vari�ve�s
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp (senhadigitada, "admin"); //strcmp compara uma string com a outra
	
	if(comparacao== 0) // se valor da senha for igual a da digitada � verdadeiro
	  {
	
    	for(laco=1;laco=1;) // Sistema Repeti��o
	   {  
		system("cls"); // para limpar a tela
		
	
	
	   setlocale(LC_ALL, "portuguese"); //Definindo a L�nguagem
	
      	printf("### Seja bem vindo(a) ao Cart�rio da EBAC! :) ###\n\n"); //Inic�o do Menu
     	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar Nomes\n");
    	printf("\t2 - Consultar Nomes\n");
    	printf("\t3 - Deletar Nomes\n");
    	printf("\t4 - Sair do Sistema\n\n");
    	printf("Op��o: "); //Fim do Menu
 	
    	scanf("%d", &opcao); //Armazenando a Escolha do Usu�rio
		
     	system("cls"); //respons�vel por limpar a tela
     	
     	switch(opcao) // come�o da sele��o do menu
     	{
     		case 1:
     			registro();// chamando a fun��o de registro
  		break;
  		case 2:
  			consultar(); //chamando a fun��o de consultar
		break;
		
		case 3:
			deletar(); // chamando a fun��o de deletar
    	break;
    	case 4: 
    	printf("Obrigado por Utilizar o sistema!\n"); // fechando o sistema ;)
    	return 0; //fechar o sistemas
    	break;
    	
    		 
    	default:
    		printf("Essa Op��o N�o Est� D�sponivel ;(\n"); // fun��o n�o existe
		system("pause"); // espera o comando para voltar para Menu principal
		break;
		 } //Fim da sele��o
       }
     }
     
     else // sempre repetir a tela quando cliente errar a senha

     printf("\nSenha Incorreta!\n\n");

    system("pause");

    system("cls");

     main();

    }
    
    
 
