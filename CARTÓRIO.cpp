#include <stdio.h> 																					// Biblioteca de comunicacao com o usuario
#include <stdlib.h> 																				// Biblioteca de alocacao de espaco de memoria
#include <locale.h> 																				// Biblioteca de alocacao de texto por regiao
#include <string.h> 																				// Biblioteca respons�vel por cuidar das strings


int registro() 																						//fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	
	setlocale(LC_ALL, "Portuguese"); 																// in�cio de cria��o de vari�veis/string
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];																				// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); 														//coletando info do usu�rio a ser cadastrado
	scanf("%s", cpf); 																				// armazenando os dados da string (%s) na vari�vel "cpf"
	
	strcpy(arquivo, cpf); 																			// Respons�vel por copiar os valores da string
	
	FILE *file; 																					//cria o arquivo
	file = fopen(arquivo, "w"); 																	// cria o arquivo - "w" cria
	fprintf(file, cpf); 																			//salvo o valor da variavel "cpf"
	fclose(file); 																					// fecha o arquivo
	
	file = fopen(arquivo, "a");																		// "a" atualiza o arquivo
	fprintf(file, ","); 																			// adiciona v�rgula no arquivo
	fclose(file); 																					// fecha o arquivo
	
	system("cls"); 																					// limpa a tela
	
	printf("Digite o primeiro nome da pessoa a ser cadastrada: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); 																			// adicona o valor atribuido "nome" ao arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("cls");
	
	printf("Digite o sobrenome/�ltimo nome da pessoa a ser cadastrada: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, sobrenome); 																		// adiciona o valor atribuido "sobrenome" ao arquivo
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("cls");
	
	printf("Digite o cargo da pessoa cadastrada: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); 																			// adiciona o valor atribuido "cargo" ao arquivo
	fclose(file);
	system("cls");
	
	printf("Cadastro conclu�do com sucesso!\n"); 													// mostra ao usu�rio que o cadastro foi conclu�do
	
	{																								//mostra as informa��es do usu�rio logo ap�s o cadastro
		FILE *file;																					//abre os arquivos
		file = fopen(cpf, "r"); 																	// abre o arquivo cpf e le os dados, "r" para ler o arquivo
		
		if(file == NULL) 																			// se o arquivo n�o existir, mostre ao usu�rio
		{
			printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n\n");
		}
	
		while(fgets(conteudo, 200, file) != NULL) 													//enquanto tiver caracteres no arquivo, ele vai ir atribuindo � v�riavel "conteudo" - limite 200 
		{
			printf("\nEssas s�o as informa��es do usu�rio: \n\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
		
	
	fclose(file);																					// fecha o arquivo para salvar as informa��es
	
	system("pause"); 																				// pausa tela para que o usu�rio consiga vizualizar a tela antes de retornar ao menu
}

int consulta() 																						//fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); 																//setando linguagem em ptbr - PERMITINDO ACENTOS
	
	char cpf[40];																					// var do tipo caracter com at� 40 caracteres
	char conteudo[200];																				// var do tipo caracter com at� 200 caracteres
	
	printf("Digite o CPF a ser consultado: ");														// mostra ao usu�rio uma mensagem
	scanf("%s", cpf); 																				//atribui o valor que usu�rio digitou � var cpf
	
	FILE *file;																						// abre os arquivos
	file = fopen(cpf, "r"); 																		// abre o arquivo com o nome do cpf escolhido, "r" para ler o arquivo
	
	if(file == NULL) 																				// se o arquivo n�o existir, mostre ao usu�rio
	{
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n\n");						// msg para o usuio
	}
	
	while(fgets(conteudo, 200, file) != NULL) 														//enquanto tiver caracteres no arquivo, ele vai ir atribuindo � v�riavel "conteudo" - limite 200 
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");										// msg ao usu�rio
		printf("%s", conteudo);																		// escreve tudo que estava atribuido a string da variavel "conteudo"
		printf("\n\n");
	}
	
	fclose(file);																					// fecha o arquivo
	
	system("pause");																				// pausa a tela para que o user veja a msg
	
}

int deletar() 																						//fun��o respons�vel por deletar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); 																//setando linguagem em ptbr - PERMITINDO ACENTOS
	
	char cpf[40];
	char opcao[3];
	char conteudo[200];
	
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file; 																					// abrir os arquivos
	file = fopen(cpf, "r"); 																		// abrir o arquivo cpf e ler "r" os dados
	fclose(file); 																					//  fechar arquivo
	
	if(file == NULL) 																				//  se n�o existir arquivo com o cpf digitado, enviar a mensagem
	{
		printf("\nO usu�rio n�o possui cadastro no sistema!\n\n");
	}
	
	else 																							// sen�o, excluir o arquivo e mandar a mensagem ao usu�rio
	{
		remove(cpf);																				// remover o arquivo com o valor de "cpf"
		printf("\nUsu�rio deletado com sucesso!\n\n"); 												// mostrar mensagem ao usu�rio	
	}
	
	system("pause"); 																				// pausar na tela da mensagem para que o usu�rio consiga ler
	
}

	


int main () 																						//fun��o respons�vel por mostar o menu
{
	int opcao=0; 																					//Definindo vari�veis - alocando espa�o vazio na memoria
	int laco=1;
	
	
	for(laco=1; laco=1;) 																			// fun��o para criar um laco, toda vez voltar para este menu
	{
		
		system("cls"); 																				//limpar tela
		
		setlocale(LC_ALL, "Portuguese"); 															//setando linguagem em ptbr
	
		printf("\tCART�RIO DA EBAC\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar Nomes\n"); 														//op��es do menu
		printf ("\t2 - Consultar Nomes\n"); 														//op��es do menu
		printf ("\t3 - Deletar Nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");														//op��es do menu
		printf("Escolha a op��o: ");																//fim do menu
	
		scanf("%d", &opcao);
	
		system("cls");																				// limpar tela ap�s o usu�rio escolher a op��o
		
		switch(opcao)																				// reduzir a necessidade de v�rios if
		{
			case 1: 																				// caso o usu�rio digite 1, ir� realizar a fun��o int registro
			registro();
			break;
			
			case 2: 																				// caso o usu�rio digite 2, ir� realizar a fun��o int consulta
			consulta();
			break;
			
			case 3: 																				// caso o usu�rio digite 1, ir� realizar a fun��o int deletar
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			printf(
          		"______*#######* \n"
         		 "____*##########* \n"
          		"__*############## \n"
          		"__################ \n"
         		 "_##################_________*####* \n"
         		 "__##################_____*########## \n"
         		 "__##################___*############# \n"
         		 "___#################*_###############* \n"
         		 "____#################################* \n"
         		 "______############################### \n"
         		 "_______############################# \n"
         		 "________=########################## \n"
        		  "__________######################## \n"
        		  "___________*##################### \n"
        		  "____________*################## \n"
        		  "_____________*############### \n"
        		  "_______________############# \n"
        		  "________________########## \n"
        		  "________________=#######* \n"
        		  "_________________###### \n"
        		  "__________________#### \n"
        		  "__________________### \n"
        		  "___________________# \n"
				);
			return 0;
			break;
		
			default: 																				// caso ele digite qualquer outra coisa ir� exibir mensagem de "erro"
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}
	}
}
