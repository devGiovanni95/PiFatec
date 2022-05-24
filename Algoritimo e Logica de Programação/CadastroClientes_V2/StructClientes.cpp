#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>


using namespace std;

struct Clientes{
	int opcao; 
	int cpf;
	char nomeInteiro[50];
	char genero[10];
	char email[40];
	char dataNascimento[10];
	char celular[15];
	char telefone[15];
	char telefoneRecado[15];
	char rua[50];
	int numeroDaCasa;
	char cep[10];
	char complemento[20];
	char cidade[30];
	char estado[20];
	char planoContemplado[10];
	char situacaoPlano[10];
};

	//quantidade de clientes
	const int TOTAL_CLIENTES = 2;
	struct Clientes cliente[TOTAL_CLIENTES];
	int indice = 0;

	void Cabecalho(char texto[]){
		system("cls");
		printf("********Bem Vindo ao HELPCAR********\n");
		printf("********%s********\n",texto);
	}
	
	
	void Imprimir(){
		Cabecalho("Impressão dos Clientes Cadastrados em Tela");
		for(int i = 0 ; i < TOTAL_CLIENTES; i++){
			printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
		}
		system("pause");
	}
	
	void Menu(){
		Cabecalho("\nMENU DE OPÇÕES");
		printf("\nDigite a opção desejada");		
		printf("\n 1 - Cadastrar novo Cliente");
		printf("\n 2 - Listar todos os Clientes");
		printf("\n 3 - Alterar ");
		printf("\n 4 - Sair \n");
	}
	
	void Alterar(){
		int cpf;
		bool achou = false;
		Cabecalho("Alteração do Cadastro do Cliente\n");
		printf("Digite o CPF: ");
		scanf("%d",&cpf);
		//Percorre todos os produtos verificando se o cpf digitado é igual a um ja cadastrado
		for(int i = 0;i < TOTAL_CLIENTES; i++){
			if(cpf == cliente[i].cpf){
				//se caso for igual, a variavel achou recebe true e exibe o cadastro
				printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
				achou = true;
			}
		}
		if(!achou){
			printf("CPF não cadastrado");
		}
		//para exibir a mensagem na tela pois se nao colocarmos o cmd nao vai deixar mostrar a imagem a tempo no consonle
		system("pause");
	}
	
	void Cadastrar(){
		
		//comparador
		int cpf;
		int vezes = 0;
		
		
		Cabecalho("Cadastro de Clientes");
		printf("Cadastrando Cliente no indice %d \n",indice);
		
		/*Comparando se o cpf digitado já está cadastrado */
		do{
			vezes = 0;
		printf("\nDigite o CPF com formato ###.###.###/##  : ");
				setbuf(stdin, NULL);
			scanf("%d",&cpf);
			//setbuf(stdin, NULL);	
			for(int i = 0;i<indice;i++){
				if(cliente[i].cpf == cpf){
					vezes++;
				}
			}
			/*Se ja tiver outra igual ele retorna que ja tem um cadastro igual*/
			if(vezes > 0){
				printf("Cpf Já cadastrado\n");
			}
		}while(vezes > 0);
	
		cliente[indice].cpf = cpf;
		//Limpar o lixo do teclado
		//setbuf(stdin, NULL);
		//scanf("%d", &cliente[indice].cpf);
		
		printf("\nDigite o nome inteiro: ");
		printf("\nSubstitua espaços por _ : ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].nomeInteiro);			
		
		printf("\nDigite o genero (Masculino ou Feminino) : ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].genero);
			
		printf("\nDigite o email: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].email);
			
			printf("\nDigite a data de nascimento: ##/##/#### ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].dataNascimento);
				
		printf("\nDigite o celular: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].celular);
						
		printf("\nDigite o telefone: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].telefone);
										
		printf("\nDigite o telefone para recado: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].telefoneRecado);
		
		printf("\nDigite o nome da: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].rua);
							
		printf("\nDigite o numero da casa: ");
		scanf("%d", &cliente[indice].numeroDaCasa);
				
		printf("\nDigite o CEP: ##.###-### ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].cep);
				
		printf("\nDigite o complemento de endereço: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].complemento);
				
		printf("\nDigite a cidade: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].cidade);
							
		printf("\nDigite o estado: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].estado);
										
		printf("\nDigite o plano contemplado: ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].planoContemplado);
			
		printf("\nDigite a situação do plano(Ativo/Inadimplente): ");
		//Limpar o lixo do teclado
		setbuf(stdin, NULL);
		gets(cliente[indice].situacaoPlano);
		
	}
	
	
	int main(){
		setlocale(LC_ALL,"Portuguese");
		
		Menu();
		
		//auxiliar para executar o while antes de cadastrar um cliente
		int opcao;
		
	
		
		/*como definimos que  vamos forcar ele entrar automaticamente
		 no menu para mostrar as opcoes que o usuario deseja fazer 
		 assim so iremos para cadastrar clientes se o funcionario quiser*/
		 do{
		 	Menu();
		 	scanf("%d",&opcao);
		 	
		 	switch(opcao){
		 		case 1: 
		 			//Cadastrar();
		 			
		 			//Fazendo uma inclementação para cada vez que um
					// cliente for criado ele aumente o numero do indice automaticamente
				 	for(int i = 0; i < TOTAL_CLIENTES; i++){
					Cadastrar();
					indice++;
					break;
		}
		 			break;
		 		
		 		case 2: 
		 			Imprimir();
		 			break;
		 		
		 		case 3: 
		 			Alterar();
		 			break;
		 		
		 		case 4: 
		 			printf("Até logo");
		 			system(0);
		 			break;
		 		default: 
		 		printf("Opção inválida favor verificar Opçao escolhida");
		 			break;
			 }		 	
		 	
		 }while(opcao != 4);
						
		
		
		return(0);
	}
