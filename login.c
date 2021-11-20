#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 200

char nome[SIZE][50];
int cpf[SIZE][11];
char email[SIZE][50];
char endereco[SIZE][50];
int cep[SIZE][20];
int op;
void cadastro();

char login[15] = "medico";
char login1[15];
char senha[15] = "1234";
char senha1[15];
//-- Determina as Contas nos "", tendo em conta a quantidade de caracteres dentro dos []

main(void)
{
    FILE *Ponteiro;
    Ponteiro = fopen("arquivo.txt", "a");
    // Ponteiro = (int*) malloc(100*sizeof(int));

    printf("LOGIN: ");
    scanf("%s", login1);
    //-- Onde será inserido o nome
    printf("Senha: ");
    scanf("%s", senha1);
    //-- Onde será inserido a senha

    //-- validaçao para saber se o login está correto
    if (strcmp(login, login1) || strcmp(senha, senha1) == 0)
    {
        printf("Logado\n");
        cadastro();
    }
    else
    {
        printf("Usuario Invalido. Tente novamente!\n");
        return 1;
    }

    printf("Dados gravados com sucesso!");

    return (0);
}

void cadastro()
{
    static int linha;

    do
    {
        FILE *Ponteiro;
        Ponteiro = fopen("arquivo.txt", "a");

        printf("\nDigite o Nome do paciente:");
        scanf("%[^\n]s", &nome[linha], stdin);
        fprintf(Ponteiro, "\nNome: %s", nome);

        printf("Digite o CPF do paciente:");
        scanf("%[^\n]s", &cpf[linha]);
        fprintf(Ponteiro, "\nCPF: %s", cpf);

        printf("\nDigite o email do paciente:");
        scanf("%[^\n]s", &email[linha]);
        fprintf(Ponteiro, "\nEmail: %s", email);

        printf("\nDigite o endereço do paciente:");
        scanf("%[^\n]s", &endereco[linha]);
        fprintf(Ponteiro, "\nEndereco: %s", endereco);

        printf("\nDigite o CEP do paciente:");
        scanf("%[^\n]d", &cep[linha]);
        fprintf(Ponteiro, "\nCep: %d", cep);

        fprintf(Ponteiro, "\n");
        printf("\nDigite 1 para continuar ou outro valor para sair ");
        scanf("%[^\n]d", &op);
        linha++;
        fclose(Ponteiro);
    } while (op == 1);
}
