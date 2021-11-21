#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 200

char login[15] = "medico";
char senha[15] = "1234";
int logado;

char nome[SIZE][50];
int idade[SIZE];
char cpf[SIZE][12];
char email[SIZE][50];
int op;
//-- Determina as Contas nos "", tendo em conta a quantidade de caracteres dentro dos []

void autenticacao();
void cadastro();
void menu();
void listar();

int main(void)
{

    autenticacao();

    if (logado == 1)
    {
        menu();
        listar();
    }
    else
    {
        return 0;
    }

    return 0;
}

void autenticacao()
{

    system("cls");

    int opLogin;
    char login1[15];
    char senha1[15];

    printf("LOGIN: ");
    scanf("%s", &login1);
    //-- Onde será inserido o nome
    printf("Senha: ");
    scanf("%s", &senha1);
    //-- Onde será inserido a senha

    //-- validaçao para saber se o login está correto
    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0)
    {
        printf("Usuário autenticado com sucesso!\n");
        logado = 1;
    }
    else
    {
        printf("Usuario Inválido.\n1 - Para tentar novamente \n2 - Para sair!\n");
        scanf("%d", &opLogin);

        if (opLogin == 1)
        {
            autenticacao();
        }
        else if (opLogin == 2)
        {
            logado = 0;
            return;
        }
    }
}

void menu()
{

    do
    {
        printf("\n1 - Cadastrar Paciente\n2 - Listar Paciente\n0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastro();
            break;

        case 2:
            listar();
            break;
        }

    } while (op != 0);
}

void cadastro()
{
    FILE *Arquivo;
    Arquivo = fopen("arquivo.txt", "a");

    static int linha;

    do
    {

        system("cls");

        printf("\n---- Cadastrando cliente -----\n");
        printf("\nDigite o nome:");
        scanf("%s", &nome[linha]);

        printf("\nDigite o e-mail:");
        scanf("%s", &email[linha]);

        printf("\nDigite a idade:");
        scanf("%d", &idade[linha]);

        printf("\nDigite o cpf:");
        scanf("%s", &cpf[linha]);

        printf("\n1 - Para continuar\n2 -Para sair\n");
        scanf("%d", &op);

        fprintf(Arquivo, "%s %s %d %s\n", nome[linha], email[linha], idade[linha], cpf[linha]);

        linha++;

    } while (op == 1);

    fclose(Arquivo);
}

void listar()
{
    system("cls");

    printf("\n Pascientes cadastrados\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (idade[i] == 0)
        {
            break;
        }
        printf("\n Paciente : %d\n", i + 1);
        printf("Nome: %s\n", nome[i]);
        printf("Idade: %d\n", idade[i]);
        printf("Email: %s\n", email[i]);
        printf("CPf: %s\n", cpf[i]);
        printf("\n----------------\n");
    }
}