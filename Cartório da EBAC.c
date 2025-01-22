#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função Responsável por Cadastrar os Usuário no sistema 
{
	setlocale(LC_ALL, "portuguese");
	// Inicío da criação variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação variáveis/string
	
	printf("Digite o CPF a ser Cadastrado:"); //coletando Informação dos Usuário
	scanf("%s", cpf);//%s refere-se a string
	
	
	strcpy(arquivo, cpf);  //responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "W" escrever
	fprintf(file, cpf); // salvo o valor da varíavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, ","); // colocar algum carectere 
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser Cadastrado: "); 
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, nome);//salva o valor da varíavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, sobrenome);//salva o valor da varíavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//cria  o arquivo
	fprintf(file, cargo);//salva o valor da varíavel
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
		printf("Não foi Possível Encontrar o Arquivo, Tente Novamente ou volte para se registrar.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra os
	{
		printf("\nEssas são as Infromações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		}
	
	system("pause");
	
	
	
}
int deletar() // Deletar Usuários
{
	char cpf[40];
	
	printf("Digite seu CPF Que Deseja Deletar: ");
	scanf("%s", cpf);
		
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL)
		{
			remove(cpf);
			printf("Usuário Encontrado e Deletado com sucesso!.\n");  // caso o sistema encontre o arquivo
		
		}
    
	else
	
		printf("O Usuário Não se Encontra no Sistema!.\n");
		system("pause"); // caso o sistema não encontre o arquivo
	

	
	}





int main()
    {
	
	int opcao=0; //Definindo Variáveís
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp (senhadigitada, "admin"); //strcmp compara uma string com a outra
	
	if(comparacao== 0) // se valor da senha for igual a da digitada é verdadeiro
	  {
	
    	for(laco=1;laco=1;) // Sistema Repetição
	   {  
		system("cls"); // para limpar a tela
		
	
	
	   setlocale(LC_ALL, "portuguese"); //Definindo a Línguagem
	
      	printf("### Seja bem vindo(a) ao Cartório da EBAC! :) ###\n\n"); //Inicío do Menu
     	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar Nomes\n");
    	printf("\t2 - Consultar Nomes\n");
    	printf("\t3 - Deletar Nomes\n");
    	printf("\t4 - Sair do Sistema\n\n");
    	printf("Opção: "); //Fim do Menu
 	
    	scanf("%d", &opcao); //Armazenando a Escolha do Usuário
		
     	system("cls"); //responsável por limpar a tela
     	
     	switch(opcao) // começo da seleção do menu
     	{
     		case 1:
     			registro();// chamando a função de registro
  		break;
  		case 2:
  			consultar(); //chamando a função de consultar
		break;
		
		case 3:
			deletar(); // chamando a função de deletar
    	break;
    	case 4: 
    	printf("Obrigado por Utilizar o sistema!\n"); // fechando o sistema ;)
    	return 0; //fechar o sistemas
    	break;
    	
    		 
    	default:
    		printf("Essa Opção Não Está Dísponivel ;(\n"); // função não existe
		system("pause"); // espera o comando para voltar para Menu principal
		break;
		 } //Fim da seleção
       }
     }
     
     else // sempre repetir a tela quando cliente errar a senha

     printf("\nSenha Incorreta!\n\n");

    system("pause");

    system("cls");

     main();

    }
    
    
 
