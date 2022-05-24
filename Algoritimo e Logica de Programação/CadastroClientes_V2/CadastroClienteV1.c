#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//colocamos como file* pois ï¿½ esperado um retorno do tipo txt
//definimos tambem o modo que ï¿½ leitura gravaï¿½ï¿½o append
//e o caminho ate o arquivo
FILE* AbreArquivo(char modo, char caminho[30]){
	FILE *arquivo;
	switch(modo){
		case 'g':
			arquivo = fopen(caminho,"wt");
			break;
		case 'l':
			arquivo = fopen(caminho,"rt");
			break;
		case 'a':
			arquivo = fopen(caminho,"a");
			break;
	}
	//se houver algum erro, o ponteiro apontam para null
	if(arquivo==NULL){
		printf("Não existe nenhum cadastro ainda.\nPor favor primeiro cadastre um novo cliente para depois consulta-lo.\nPor favor reabra o programa");
		exit(0);
	}
	return arquivo;
	
}


//funcao com parametro indicativo do tipo de arquivo
void FecharArquivo(FILE *arquivo){
	//fechar o arquivo.txt
	fclose(arquivo);
}

void Cadastro(char cpf[14],char nomeInteiro[50],char genero[10],char email[40],char dataNascimento[10],char celular[15],char telefone[15],char telefoneRecado[15],char rua[50],int numeroDaCasa,char cep[10],char complemento[20],char cidade[30],char estado[20],char planoContemplado[10],char situacaoPlano[10]){
		
	FILE *arquivo;
	arquivo = AbreArquivo('a', "CadastroClientesHelpCar.txt");
	fprintf(arquivo, "%s %s %s %s %s %s %s %s %s %d %s %s %s %s %s %s\n",cpf, nomeInteiro,genero,email,dataNascimento,celular,telefone,telefoneRecado,rua,numeroDaCasa,cep, complemento,cidade,estado,planoContemplado,situacaoPlano);
	FecharArquivo(arquivo);
}


void ContagemLinhas(){
	FILE *arquivo;
	
	int linhas = 0;
	char texto[500];//tem 500 pois é a quantidade que vamos ler no while
	arquivo = AbreArquivo('l',"CadastroClientesHelpCar.txt");
	
	if(arquivo==NULL){
		printf("Não foi possivel abrir o caminho");
		exit(0);
	}
	//enquanto nao chegar no fim do arquivo continua lendo o arquivo
	while(!feof(arquivo)){
		//ler os arquivos de texto e salvar numa variavel
		//ate quantos caracteres voamos ler
		//ponteiro para o que vamos ler
		fgets(texto, 500, arquivo);
		//printf("%s", texto);
		//se o comprimento do texto(strlen = le o comprimento do arquivo)
		if(strlen(texto) < 499){
			linhas++;
		//	printf("%d:%s------\n", linhas, texto);
		}
		
	}
	printf("A quandidade de linhas é: %d", linhas);
	FecharArquivo(arquivo);

}

void Listar(){
	FILE *arquivo;
	char cpf[14];
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
	
	arquivo = AbreArquivo('l',"CadastroClientesHelpCar.txt");
	//enquando não for fim do arquivo
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %s %s %s %s %s %s %s %s %d %s %s %s %s %s %s\n",&cpf, &nomeInteiro,&genero,&email,&dataNascimento,&celular,&telefone,&telefoneRecado,&rua,&numeroDaCasa,&cep,&complemento,&cidade,&estado,&planoContemplado,&situacaoPlano);
		printf("CPF: %s - Nome Completo: %s - Genero: %s - Email: %s - Nascimento: %s - Celular: %s - Telefone: %s - TelefoneRecado: %s - Rua: %s - Numero: %d - Cep: %s - Complemento: %s - Cidade: %s - Estado: %s - PlanoContratado: %s - SituacaoPagamento: %s\n", cpf, nomeInteiro,genero,email,dataNascimento,celular,telefone,telefoneRecado,rua,numeroDaCasa,cep,complemento,cidade,estado,planoContemplado,situacaoPlano);
	}
	FecharArquivo(arquivo);
}

int main(){
	setlocale(LC_ALL,"Portuguese");

	int opcao;
	char cpf[14];
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
	
	do{
	
		//limpar tela
		system("cls");
		
		printf("\n\n\t\tBem Vindo(a) ao Cadastro de clientes\n");
		printf("\nMENU");
		printf("\n 1 - Cadastrar novo Cliente");
		printf("\n 2 - Listar todos os Clientes");
		printf("\n 3 - Sair ");
		
		printf("\nDigite uma opção: \n");
		scanf("%d", &opcao);
		//limpar tela
		system("cls");
		
		switch(opcao){
			case 1:
				printf("\nDigite o CPF com formato ###.###.###/##  : ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(cpf);
				
				printf("\nDigite o nome inteiro: ");
				printf("\nSubstitua espaços por _ : ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(nomeInteiro);			
				
				printf("\nDigite o genero (Masculino ou Feminino) : ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(genero);
				
				printf("\nDigite o email: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(email);
				
				printf("\nDigite a data de nascimento: ##/##/#### ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(dataNascimento);
				
				printf("\nDigite o celular: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(celular);
							
				printf("\nDigite o telefone: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(telefone);
										
				printf("\nDigite o telefone para recado: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(telefoneRecado);
				
				printf("\nDigite o nome da: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(rua);
							
				printf("\nDigite o numero da casa: ");
				scanf("%d", &numeroDaCasa);
				
				printf("\nDigite o CEP: ##.###-### ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(cep);
				
				printf("\nDigite o complemento de endereço: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(complemento);
				
				printf("\nDigite a cidade: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(cidade);
							
				printf("\nDigite o estado: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(estado);
										
				printf("\nDigite o plano contemplado: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(planoContemplado);
				
				printf("\nDigite a situação do plano(Ativo/Inadimplente): ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(situacaoPlano);
				
				
				
				
				Cadastro(cpf, nomeInteiro,genero,email,dataNascimento,celular,telefone,telefoneRecado,rua,numeroDaCasa,cep, complemento,cidade,estado,planoContemplado,situacaoPlano);
				
				
				system("pause");
				break;
			case 2: 
				Listar();
				system("pause");
				break;
			
				case 4: 
				ContagemLinhas();
				system("pause");
				break;
			
			case 3:
				printf("\n\nFinalizando....\n\n");
			 	system("pause");
				exit(0);
				break;
			
			default:
				printf("Opï¿½ï¿½o Invï¿½lida! Tente Novamente");
				system("pause");
		}
	}while(opcao!=3);
	
	return(0);
	
}

int Explicacao() {
	char vetor[6];
	int valor;

	//definindo ponteiro para abrir um arquivo
	FILE *arquivo;


	//Abrir arquivo
	arquivo = AbreArquivo('g', "teste.txt");

	
	//escreve dados no arquivo de txt
	fprintf(arquivo,"teste 78965");

	//Fecha o arquivo
	FecharArquivo(arquivo);
	
	
	//Abrindo o arquivo em modo leitura
	arquivo = AbreArquivo('l', "teste.txt");
	
	fscanf(arquivo,"%s %d",&vetor,&valor);
	printf("\n\n%s %d\n\n",vetor,valor);
	
	//Fecha o arquivo
	FecharArquivo(arquivo);
	
	system("pause");
	return 0;
}
