
/*======================================================================*/ 
/*
 // Autor: Gabriel Massuquetti de Carvalho
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define ARQ "Dados.dat" /* arquivo com os dados*/
#define OP_INSERIR '1'
#define OP_ALTERAR '2'
#define OP_APAGAR '3'
#define OP_LISTAR '4'
#define OP_PESQUISAR '5'
#define OP_SAIR '0'
#define OP_PESQ_IDADE '1'
#define OP_PESQ_NOME '2'

char *MainMenu[]={
    "1. Inserir registro",
    "2. Alterar registro",
    "3. Apagar registro",
    "4. Listar registros",
    "5. Pesquisar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *PesqMenu[]={
    "1. Pesquisar por intervalo de idades",
    "2. Pesquisar por nome",
    NULL  /* ACABARAM AS OPÇÕES*/
};

FILE *fp; /*variável global pois é útil ao longo do programa*/

typedef struct{
    char nome[30+1];
    int idade;
    float salario;
    char Status; /* '*' indica que o registro está apagado*/
}Pessoa;

void Mensagem(char *msg);

/* lê os dados de um registro introduzido pelo usuário*/
void Ler_Pessoa(Pessoa *p){
    printf("Nome:    "); gets(p->nome);
    printf("Idade:   "); scanf("%d",&p->idade);
    printf("salario: "); scanf("%f",&p->salario);
    p->Status = ' ';
    fflush(stdin);
}


/*Mostra na tela os dados existentes no registro*/
void Mostrar_Pessoa(Pessoa p){
    printf("%-30s %3d %10.2f \n",p.nome, p.idade, p.salario);
}

/*Adiciona uma pessoa ao arquivo*/
void Adiciona_Pessoa(Pessoa p){
    fseek(fp, 0L, SEEK_END);
    if(fwrite(&p, sizeof(p), 1, fp)!=1)
        Mensagem("Adicionar pessoa: Falhou a escrita do registro");
}

/*Colocar uma mensagem na tela*/
void Mensagem(char *msg){
    printf(msg);
    getchar();
}



/*Verificar se o arquivo já existe. Se não existir, ele é criado
se já existir, abre-o em modo de leitura e escrita (r+b)
*/
void Inic(){
    fp= fopen(ARQ, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQ, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf(stderr," Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
}

/* Faz um menu simples com as opções do vetor de strings.
seleciona a opção, usando o primeiro caracter de cada string.
devolve o primeiro caracter da opção.
*/
char Menu(char *opcoes[]){
    int i;
    char ch;
    while(1){
        /*CLS */
        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);
               
            printf("\n\n\t\tOpcao: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

void Inserir_Pessoa(){
    Pessoa x;
    Ler_Pessoa(&x);
    Adiciona_Pessoa(x);
}

void Alterar_Pessoa(){
    Pessoa x;
    long int n_reg;
    printf("Qual o numero do registro: ");
    scanf("%ld", & n_reg); fflush(stdin);
    if(fseek(fp, (n_reg-1)*sizeof(Pessoa), SEEK_SET)!=0){
        Mensagem("Registro inexistente ou problemas no posicionamento!!!");
        return;
    }
    if(fread(&x, sizeof(Pessoa), 1, fp)!= 1){
        Mensagem("Problemas na leitura do registro!!!");
        return;
    }
   
    if(x.Status=='*'){
        Mensagem("Um registro apagado não pode ser alterado!!! \n\n");
        return;
    }
   
    printf("\n\n Dados Atuais \n\n");
    Mostrar_Pessoa(x);
    printf("\n\n Novos dados \n\n");
    Ler_Pessoa(&x);
   
    // recuar um registro no arquivo
    fseek(fp, -(long) sizeof(Pessoa), SEEK_CUR);
    // reescrever o registro;
    fwrite(&x, sizeof(Pessoa), 1, fp);
    fflush(fp); /*despejar os arquivos no disco rígido*/
}

void Apagar_Pessoa(){
    Pessoa x;
    long int n_reg;
    char resp;
   
    printf("Qual o numero do registro: ");
    scanf("%ld", & n_reg); fflush(stdin);
    if(fseek(fp, (n_reg - 1)*sizeof(Pessoa), SEEK_SET)!= 0){
        Mensagem("Registro inexistente ou problemas no registro!!!");
        return;
    }
    if(fread(&x, sizeof(Pessoa), 1, fp)!= 1){
        Mensagem("Problema na leitura do registro!!!");
        return;
    }
    if(x.Status=='*'){
        Mensagem("Registro já está apagado!!!\n\n");
    }
    printf("\n\n Dados atuais \n\n");
    Mostrar_Pessoa(x);
    printf("\n\n Apagar o registro (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;
   
    x.Status= '*';
    // recuar um registro no arquivo
    fseek(fp, -(long) sizeof(Pessoa), SEEK_CUR);
    // reescrever o registro;
    fwrite(&x, sizeof(Pessoa), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco rígido*/
}

void Listar(){
   
    long int n_Linhas = 0;
    Pessoa reg;
    rewind(fp);
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1)break; /*Sair do laço*/
        if(reg.Status=='*') continue; /*Passa ao próximo*/
        Mostrar_Pessoa(reg);
        n_Linhas++;
        if(n_Linhas%20==0)
            Mensagem("Pressione <Enter> para continuar .  .  .");
    }
    Mensagem("\n\n Pressione <Enter> para continuar .  .  ."); /*No fim da listagem*/
}

void pesquisar_Idades(int ini, int fim){
    Pessoa reg;
    rewind(fp);
   
    while(fread(&reg, sizeof(Pessoa), 1, fp))
        if(reg.Status!='*' && reg.idade>=ini && reg.idade<=fim)
            Mostrar_Pessoa(reg);
   
    Mensagem("\n\n Pressione <Enter> para continuar .  .  ."); /*No fim da listagem*/
}

void Pesquisar_Nome(char *s){
    Pessoa reg;
    rewind(fp);
   
    while(fread(&reg, sizeof(Pessoa), 1, fp))
        if(reg.Status!='*' && strstr(reg.nome, s))
            Mostrar_Pessoa(reg);
           
    Mensagem("\n\n Pressione <Enter> para continuar .  .  ."); /*No fim da listagem*/
}


int main(int argc, char *argv[]) {
   
    char opcao;
    Inic();
    while((opcao = Menu(MainMenu))!= OP_SAIR)
        switch(opcao){
           
            case OP_INSERIR: Inserir_Pessoa(); break;
            case OP_ALTERAR: Alterar_Pessoa(); break;
            case OP_APAGAR: Apagar_Pessoa(); break;
            case OP_LISTAR: Listar(); break;
            case OP_PESQUISAR:
                switch(opcao){
                    case OP_PESQ_IDADE:
                        {
                            int n1, n2;
                            printf("Qual o intervalo de idades: ");
                            scanf("%d%d", &n1, &n2); fflush(stdin);
                            pesquisar_Idades(n1, n2);
                                break;
                        }
                    case OP_PESQ_NOME:
                        {
                            char string[BUFSIZ+1];
                            printf("Qual o nome a procurar: ");
                            gets(string); fflush(stdin);
                            Pesquisar_Nome(string);
                        }
                }
        }
   
   
    return 0;
}

/*======================================================================*/ 

Referência: Luis Damas linguagem c