/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CPPTemplate.cpp to edit this template
 */
#include<stdio.h>
#include<windows.h>
#include<winsock2.h>
#include<mysql.h>

main(){
	MYSQL conexao;
	mysql_init(&conexao);
	
	if(mysql_real_connect(&conexao,"127.0.0.1", "root","1995","",0,NULL,0))
	{
	printf(" \nConexao ao Banco de dados realizada com sucesso!");
	mysql_query(&conexao,"Create Database Testc");
	mysql_close(&conexao);
	}
	else{
		printf("Falha de conexao \n");
		printf("Erro %d : %s\n",mysql_errno(&conexao),mysql_error(&conexao));
	}
	
	return(0);
}

