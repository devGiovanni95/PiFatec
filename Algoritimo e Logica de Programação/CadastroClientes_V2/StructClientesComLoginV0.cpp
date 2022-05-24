#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>


using namespace std;

	void Cabecalho(char texto[]){
		system("cls");
		printf("********Bem Vindo ao HELPCAR********\n");
		printf("********%s********\n",texto);
	}

bool login(){
	char usuario[25], senha[10];
	int testeUsuario;
	int testeSenha;
	
	Cabecalho("Sistema de login");
	do{
	printf("Digite o Usuário:");
	setbuf(stdin, NULL);//limpar lixo do teclado
	gets(usuario);
	printf("Digite a Senha:");
	setbuf(stdin, NULL);
	gets(senha);
	system("cls");
	printf("Dados Incorretos. Tente Novamente:\n");	
	testeUsuario = strcmp(usuario,"HELPCAR");
	testeSenha = strcmp(usuario,"HELPCAR");
	}
		while(testeUsuario!= 0 || testeSenha !=0);	
		printf("Seja Bem vindo\n\n");	
			system("pause");
			return 1;
}


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
	const int TOTAL_CLIENTES = 5000;
	struct Clientes cliente[TOTAL_CLIENTES];
	int indice = 0;
	
	void Imprimir(){
		Cabecalho("Impressão dos Clientes Cadastrados em Tela");
		for(int i = 0 ; i < indice; i++){
			printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
		}
		if (indice < 1){
			printf("Não Tem Nenhum Cliente Cadastrado Ainda");
		}
		system("pause");
	}
	
	void Menu(){
		Cabecalho("MENU DE OPÇÕES");
		printf("\nDigite a opção desejada");		
		printf("\n 1 - Cadastrar novo Cliente");
		printf("\n 2 - Listar todos os Clientes");
		printf("\n 3 - Alterar Endereco ");
		printf("\n 4 - Alterar Plano Contratado ");
		printf("\n 5 - Alterar Situação de Pagamento ");	
		printf("\n 6 - Excluir Cadastro");
		printf("\n 7 - Sair \n");
	}
	
	void AlterarEndereco(){
		int cpf;
		bool achou = 0;
		Cabecalho("Alteração do Cadastro do Cliente");
		printf("Digite o CPF: ");
		scanf("%d",&cpf);
		//Percorre todos os produtos verificando se o cpf digitado é igual a um ja cadastrado
		for(int i = 0;i < TOTAL_CLIENTES; i++){
			if(cpf == cliente[i].cpf){
				//se caso for igual, a variavel achou recebe true e exibe o cadastro
				printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
				
					printf("\nDigite o Novo nome da rua: ");
					//Limpar o lixo do teclado
					setbuf(stdin, NULL);
					gets(cliente[i].rua);
										
					printf("\nDigite o Novo numero da casa: ");
					scanf("%d", &cliente[i].numeroDaCasa);
							
					printf("\nDigite o Novo CEP: ##.###-### ");
					//Limpar o lixo do teclado
					setbuf(stdin, NULL);
					gets(cliente[i].cep);
							
					printf("\nDigite o Novo complemento de endereço: ");
					//Limpar o lixo do teclado
					setbuf(stdin, NULL);
					gets(cliente[i].complemento);
			
				achou = 1;
				
			}
		}
		if(!achou){
			printf("CPF não cadastrado");
		}
		//para exibir a mensagem na tela pois se nao colocarmos o cmd nao vai deixar mostrar a imagem a tempo no consonle
		system("pause");
	}
	
		void AlterarPlano(){
		int cpf;
		bool achou = 0;
		Cabecalho("Alteração do Cadastro do Cliente");
		printf("Digite o CPF: ");
		scanf("%d",&cpf);
		//Percorre todos os produtos verificando se o cpf digitado é igual a um ja cadastrado
		for(int i = 0;i < TOTAL_CLIENTES; i++){
			if(cpf == cliente[i].cpf){
				//se caso for igual, a variavel achou recebe true e exibe o cadastro
				printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
				printf("Digite o Novo Plano Contratado:");
				setbuf(stdin, NULL);
				gets(cliente[i].planoContemplado);		
				achou = 1;
				
			}
		}
		if(!achou){
			printf("CPF não cadastrado");
		}
		//para exibir a mensagem na tela pois se nao colocarmos o cmd nao vai deixar mostrar a imagem a tempo no consonle
		system("pause");
	}
		void AlterarSituacaoPagento(){
			int cpf;
			bool achou = 0;
			Cabecalho("Alteração do Cadastro do Cliente");
			printf("Digite o CPF: ");
			scanf("%d",&cpf);
			//Percorre todos os produtos verificando se o cpf digitado é igual a um ja cadastrado
			for(int i = 0;i < TOTAL_CLIENTES; i++){
				if(cpf == cliente[i].cpf){
					//se caso for igual, a variavel achou recebe true e exibe o cadastro
					printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
					printf("Digite a Situação do Pagamento(Ativo/Inadimplente):");
					setbuf(stdin, NULL);
					gets(cliente[i].situacaoPlano);				
					achou = 1;
						
				}
			}
			if(!achou){
				printf("CPF não cadastrado");
			}
			//para exibir a mensagem na tela pois se nao colocarmos o cmd nao vai deixar mostrar a imagem a tempo no consonle
			system("pause");
	}
	
	
		void Excluir(){
				
			int cpf;
			bool achou = 0;
			char confirma;
			Cabecalho("Exclusão de Cliente");
			printf("Digite o CPF: ");
			scanf("%d",&cpf);
			
			//Percorre todos os produtos verificando se o cpf digitado é igual a um ja cadastrado
			for(int i = 0;i < TOTAL_CLIENTES; i++){
				if(cpf == cliente[i].cpf){
					//se caso for igual, a variavel achou recebe true e exibe o cadastro
					printf("CPF: %d - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cliente[i].cpf, cliente[i].nomeInteiro,cliente[i].genero,cliente[i].email,cliente[i].dataNascimento,cliente[i].celular,cliente[i].telefone,cliente[i].telefoneRecado,cliente[i].rua,cliente[i].numeroDaCasa,cliente[i].cep,cliente[i].complemento,cliente[i].cidade,cliente[i].estado,cliente[i].planoContemplado,cliente[i].situacaoPlano);
					printf("Deseja Realmente Excluir Cliente ?");
					setbuf(stdin, NULL);
					scanf("%c",&confirma);		
						switch(confirma){
							case 's':
								for(int x = i; x < indice-1; x++ ){
									//vai settar o indice do proximo 
									cliente[x] = cliente[x+1];
								}
								indice--;
								break;
						}
					achou = 1;
					
				}
			}
			if(!achou){
				printf("CPF não cadastrado");
			}
			//para exibir a mensagem na tela pois se nao colocarmos o cmd nao vai deixar mostrar a imagem a tempo no consonle
			system("pause");
	}
	
	void Cadastrar(){
		
		if(indice >= TOTAL_CLIENTES){
			printf("Não é Possivel Cadastrar Mais nenhum Cliente Quantidade Acima do Permitido!!");
			//nao precisamos retornar nem o 1 ou 0 pois o metodo é void
			return;		
		}
		
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
		
		printf("\nDigite o nome da rua: ");
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
		login();
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
		 			Cadastrar();
		 			indice++;
		 			
		 			/*
		 			Fazendo uma inclementação para cada vez que um
					 cliente for criado ele aumente o numero do indice automaticamente
				 	for(int i = 0; i < TOTAL_CLIENTES; i++){
					Cadastrar();
					indice++;
					break;
					}*/
					
		 			break;
		 		
		 		case 2: 
		 			Imprimir();
		 			break;
		 		
		 		case 3: 
		 			AlterarEndereco();
		 			break;
		 			
		 		case 4: 
		 			AlterarPlano();
		 			break;
		 			
			 	case 5: 
		 			AlterarSituacaoPagento();
		 			break;
		 			
		 		case 6: 
		 			Excluir();
		 			break;
		 			
		 		case 7: 
		 			printf("Até logo");
		 			system(0);
		 			break;
		 		default: 
		 		printf("Opção inválida favor verificar Opçao escolhida");
		 			break;
			 }		 	
		 	
		 }while(opcao != 7);
						
		
		
		return(0);
	}
