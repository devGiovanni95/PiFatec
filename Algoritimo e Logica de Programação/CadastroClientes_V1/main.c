#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//colocamos como file* pois é esperado um retorno do tipo txt
//definimos tambem o modo que é leitura gravação append
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
	//se houver algum erro, o ponteiro apontará para null
	if(arquivo==NULL){
		printf("Não foi possivel abrir o caminho");
		exit(0);
	}
	return arquivo;
	
}

//funcao com parametro indicativo do tipo de arquivo
void FecharArquivo(FILE *arquivo){
	//fechar o arquivo.txt
	fclose(arquivo);
}

void Cadastro(char nome[30],int telefone){
	FILE *arquivo;
	arquivo = AbreArquivo('a', "cadastroCliente.txt");
	fprintf(arquivo, "%s %d\n",nome, telefone);
	FecharArquivo(arquivo);
}

void Listar(){
	FILE *arquivo;
	char nome[30];
	int telefone;
	
	arquivo = AbreArquivo('l',"cadastroCliente.txt");
	//enquando não for fim do arquivo
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %d ", &nome, &telefone);
		printf("Nome: %s - Telefone: %d\n", nome, telefone);
	}
	FecharArquivo(arquivo);
}

int main2(){
	setlocale(LC_ALL,"Portuguese");

	int opcao;
	char nome[30];
	int telefone;
	
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
				printf("\nDigite o nome: ");
				//Limpar o lixo do teclado
				setbuf(stdin, NULL);
				gets(nome);
				printf("\nDigite o telefone: ");
				scanf("%d", &telefone);
				Cadastro(nome, telefone);
				system("pause");
				break;
			case 2: 
				Listar();
				system("pause");
				break;
			
			case 3:
				printf("\n\nFinalizando....\n\n");
			 	system("pause");
				exit(0);
				break;
			
			default:
				printf("Opção Inválida! Tente Novamente");
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
