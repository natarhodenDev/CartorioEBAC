#include <stdio.h> 																					// Biblioteca de comunicacao com o usuario
#include <stdlib.h> 																				// Biblioteca de alocacao de espaco de memoria
#include <locale.h> 																				// Biblioteca de alocacao de texto por regiao
#include <string.h> 																				// Biblioteca responsável por cuidar das strings


int registro() 																						//função responsável por cadastrar os usuários no sistema
{	
	
	setlocale(LC_ALL, "Portuguese"); 																// início de criação de variáveis/string
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];																				// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); 														//coletando info do usuário a ser cadastrado
	scanf("%s", cpf); 																				// armazenando os dados da string (%s) na variável "cpf"
	
	strcpy(arquivo, cpf); 																			// Responsável por copiar os valores da string
	
	FILE *file; 																					//cria o arquivo
	file = fopen(arquivo, "w"); 																	// cria o arquivo - "w" cria
	fprintf(file, cpf); 																			//salvo o valor da variavel "cpf"
	fclose(file); 																					// fecha o arquivo
	
	file = fopen(arquivo, "a");																		// "a" atualiza o arquivo
	fprintf(file, ","); 																			// adiciona vírgula no arquivo
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
	
	printf("Digite o sobrenome/último nome da pessoa a ser cadastrada: ");
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
	
	printf("Cadastro concluído com sucesso!\n"); 													// mostra ao usuário que o cadastro foi concluído
	
	{																								//mostra as informações do usuário logo após o cadastro
		FILE *file;																					//abre os arquivos
		file = fopen(cpf, "r"); 																	// abre o arquivo cpf e le os dados, "r" para ler o arquivo
		
		if(file == NULL) 																			// se o arquivo não existir, mostre ao usuário
		{
			printf("\nNão foi possível abrir o arquivo, CPF não localizado!\n\n");
		}
	
		while(fgets(conteudo, 200, file) != NULL) 													//enquanto tiver caracteres no arquivo, ele vai ir atribuindo à váriavel "conteudo" - limite 200 
		{
			printf("\nEssas são as informações do usuário: \n\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
		
	
	fclose(file);																					// fecha o arquivo para salvar as informações
	
	system("pause"); 																				// pausa tela para que o usuário consiga vizualizar a tela antes de retornar ao menu
}

int consulta() 																						//função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); 																//setando linguagem em ptbr - PERMITINDO ACENTOS
	
	char cpf[40];																					// var do tipo caracter com até 40 caracteres
	char conteudo[200];																				// var do tipo caracter com até 200 caracteres
	
	printf("Digite o CPF a ser consultado: ");														// mostra ao usuário uma mensagem
	scanf("%s", cpf); 																				//atribui o valor que usuário digitou à var cpf
	
	FILE *file;																						// abre os arquivos
	file = fopen(cpf, "r"); 																		// abre o arquivo com o nome do cpf escolhido, "r" para ler o arquivo
	
	if(file == NULL) 																				// se o arquivo não existir, mostre ao usuário
	{
		printf("\nNão foi possível abrir o arquivo, CPF não localizado!\n\n");						// msg para o usuio
	}
	
	while(fgets(conteudo, 200, file) != NULL) 														//enquanto tiver caracteres no arquivo, ele vai ir atribuindo à váriavel "conteudo" - limite 200 
	{
		printf("\nEssas são as informações do usuário: \n\n");										// msg ao usuário
		printf("%s", conteudo);																		// escreve tudo que estava atribuido a string da variavel "conteudo"
		printf("\n\n");
	}
	
	fclose(file);																					// fecha o arquivo
	
	system("pause");																				// pausa a tela para que o user veja a msg
	
}

int deletar() 																						//função responsável por deletar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); 																//setando linguagem em ptbr - PERMITINDO ACENTOS
	
	char cpf[40];
	char opcao[3];
	char conteudo[200];
	
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file; 																					// abrir os arquivos
	file = fopen(cpf, "r"); 																		// abrir o arquivo cpf e ler "r" os dados
	fclose(file); 																					//  fechar arquivo
	
	if(file == NULL) 																				//  se não existir arquivo com o cpf digitado, enviar a mensagem
	{
		printf("\nO usuário não possui cadastro no sistema!\n\n");
	}
	
	else 																							// senão, excluir o arquivo e mandar a mensagem ao usuário
	{
		remove(cpf);																				// remover o arquivo com o valor de "cpf"
		printf("\nUsuário deletado com sucesso!\n\n"); 												// mostrar mensagem ao usuário	
	}
	
	system("pause"); 																				// pausar na tela da mensagem para que o usuário consiga ler
	
}

	


int main () 																						//função responsável por mostar o menu
{
	int opcao=0; 																					//Definindo variáveis - alocando espaço vazio na memoria
	int laco=1;
	
	
	for(laco=1; laco=1;) 																			// função para criar um laco, toda vez voltar para este menu
	{
		
		system("cls"); 																				//limpar tela
		
		setlocale(LC_ALL, "Portuguese"); 															//setando linguagem em ptbr
	
		printf("\tCARTÓRIO DA EBAC\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar Nomes\n"); 														//opções do menu
		printf ("\t2 - Consultar Nomes\n"); 														//opções do menu
		printf ("\t3 - Deletar Nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");														//opções do menu
		printf("Escolha a opção: ");																//fim do menu
	
		scanf("%d", &opcao);
	
		system("cls");																				// limpar tela após o usuário escolher a opção
		
		switch(opcao)																				// reduzir a necessidade de vários if
		{
			case 1: 																				// caso o usuário digite 1, irá realizar a função int registro
			registro();
			break;
			
			case 2: 																				// caso o usuário digite 2, irá realizar a função int consulta
			consulta();
			break;
			
			case 3: 																				// caso o usuário digite 1, irá realizar a função int deletar
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
		
			default: 																				// caso ele digite qualquer outra coisa irá exibir mensagem de "erro"
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		}
	}
}
