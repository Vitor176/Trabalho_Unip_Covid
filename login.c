#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#define SIZE 200
#define Comorbidade "S"

char login[15] = "medico";
char senha[15] = "1234";
int logado;

char nome[50];
int dia[SIZE];
int mes[SIZE];
int ano[SIZE];
int cpf[SIZE];
char email[SIZE][50];
char telefone[SIZE][50];
char endereco[SIZE][50];
char dataNascimento[SIZE][8];
char dtdiagnostico[SIZE][50];
char validaComorbidade[SIZE][50];
int op;

void autenticacao();
void cadastro();
void menu();
void listar();

int main(void)
{

    autenticacao();
    getchar();

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

    printf("Senha: ");
    scanf("%s", &senha1);

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
    char casoComorbidade[SIZE][50];

    static int linha;

    do
    {

        system("cls");

        printf("\n---- Cadastrando cliente -----\n");
        printf("\nDigite o nome:");
        scanf("%[^\n]", &nome[linha]);

        printf("\nDigite o cpf:");
        scanf("%[^\n]", &cpf[linha]);

        printf("\nDigite o Telefone:");
        scanf("%d", &telefone[linha]);

        printf("\nDigite o Endereço:");
        scanf("%[^\n]", &endereco[linha]);

        printf("\nDigite a dia do nascimento:");
        scanf("%d", &dia[linha]);

        printf("\nDigite o mês do nascimento:");
        scanf("%d", &mes[linha]);

        printf("\nDigite o ano do nascimento:");
        scanf("%d", &ano[linha]);

        printf("\nDigite o e-mail:");
        scanf("%s", &email[linha]);

        printf("\nPaciente com comorbidade:  S/N");
        scanf("%s", &validaComorbidade);
        if (strcmp(Comorbidade, validaComorbidade) == 0)
        {
            printf("\nQual a comorbidade do paciente?");
            scanf("%s", &validaComorbidade[linha]);
        }
        else
        {
            return;
        }

        printf("\n1 - Para continuar\n2 -Para sair\n");
        scanf("%d", &op);

        fprintf(Arquivo, "%s %s %d %s %d %s %d %s %d\n", nome[linha], cpf[linha], telefone[linha], endereco[linha], dataNascimento[linha], email[linha], dtdiagnostico[linha], validaComorbidade[linha]);

        linha++;

    } while (op == 1);

    fclose(Arquivo);
}

void listar()
{
    system("cls");

    printf("\n ---Pascientes cadastrados---\n");
    for (int i = 0; i < SIZE - 1; i++)
    {

        if (strcmp(dia[i], dia) == 0)
        {
            printf("\n Paciente : %d\n", i + 1);
            printf("Nome: %s\n", nome[i]);
            printf("CPF: %s\n", cpf[i]);
            printf("Telefone: %d\n", telefone[i]);
            printf("Endereço: %s\n", endereco[i]);
            printf("Idade: %d\n", calcularIdade(dataAtual, dataNascimento));
            printf("Email: %s\n", email[i]);
            printf("Data de diagnóstico: %s\n", dtdiagnostico[i]);
            printf("Comorbidade: %d\n", validaComorbidade[i]);
            printf("\n----------------\n");
        }
        else
        {
            break;
        }
    }
}

struct tm dataSistema();

struct tm dataAtual()
{

    struct tm dataAtual = dataSistema();

    struct tm dataNascimento = dataSistema();
    dataNascimento.tm_mday = dia; // Preencha esse campo
    dataNascimento.tm_mon = mes;  // Preencha esse campo
    dataNascimento.tm_year = ano; // Preencha esse campo

    int idade = calcularIdade(&dataAtual, &dataNascimento);

    printf("Você tem %i anos de idade. \n", idade);

    if (idade >= 65)
    {

        printf("Você faz parte do grupo de risco!");
    }
    else
    {

        return;
    }
}

struct tm dataSistema()
{
    time_t temp = time(NULL);

    struct tm dataAtual = *localtime(&temp);
    dataAtual.tm_year += 1900; // Compensa a forma como é contado o ano

    return dataAtual;
}

int calcularIdade(struct tm *dataAtual, struct tm *dataNascimento)
{
    int idade = dataAtual->tm_year - dataNascimento->tm_year;

    /*
     * Verifica as condições para determinar se já fez aniversário.
     * Caso não tenha feito ainda, decrementamos a idade para compensar.
     */
    if (dataAtual->tm_mon < dataNascimento->tm_mon)
    {
        idade -= 1;
    }
    else if (dataAtual->tm_mon == dataNascimento->tm_mon)
    {
        if (dataAtual->tm_mday < dataNascimento->tm_mday)
        {
            idade -= 1;
        }
    }

    return idade;
}