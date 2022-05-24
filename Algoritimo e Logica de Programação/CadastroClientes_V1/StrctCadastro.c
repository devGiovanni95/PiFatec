#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<iostream>

using namespace std;

struct Clientes{
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
};

	//quantidade de clientes
	const int TOTAL_CLIENTES = 100;
	struct Clientes cliente[TOTAL_CLIENTES];

	void Cabecalho(char texto[]){
		system("cls");
		cout<<"********Bem Vindo ao HELPCAR********";
		cout<<"********"<<texto<<"********\n";
	}
	
	
	
	
	int main(){
		setlocale(LC_ALL,"");
		Cabecalho("Giovanni");
		return(0);
	}
