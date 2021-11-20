//Vitor

#include <stdio.h>
#include <string.h>

char login[15] = "admin";
char login1[15];
char senha[15] = "1234";
char senha1[15];
//-- Determina as Contas nos "", tendo em conta a quantidade de caracteres dentro dos []
//oi
main()
{

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
    }
    else
    {
        printf("Usuario Invalido. Tente novamente!\n");
    }
}
