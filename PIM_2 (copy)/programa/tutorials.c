#include <stdio.h>

// Include "linker" header file
#include "functions.h"

// Function that will print a newcomer message
void newcomer_message_first()
{

    // Clear terminal screen
    clear();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Seja bem-vindo(a) ao Simple Logistical System!\n");
    puts("Para começar a utilizar o sistema, cadastre sua primeira conta");
    puts("que, por padrão, tera o escopo de CONTA ADMINISTRADORA.\n");

    puts("Para saber mais sobre as diferentes contas que o SLS suporta");
    puts("e suas particularidades, selecione a opção 8 no menu");
    puts("ou acesse a seção 'Manual' em nosso site!\n");

    press_to_continue();
}

// Function that will print another newcomer message
void newcomer_message_second()
{

    // Clear terminal screen
    clear();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Conta criada com sucesso!\n");
    puts("Não se esqueça de guardar as credenciaus fornecidas");
    puts("em um lugar seguro.\n");

    puts("A seguir você será redirecionado(a) para o MENU.");
    puts("A tela do menu discrimina as diferentes funcionalidades do sistema");
    puts("assim como seu respectivo número de designação.\n");

    puts("Para acessar qualquer funcionalidade que desejar");
    puts("digite o número correspondente aquela ferramenta");
    puts("e pressione ENTER\n");

    press_to_continue();
}

// Tutorial about different accounts
void tutorial_accounts()
{

    boilerplate();

    puts("Na versão 1.0 do SLS, existem dois tipos de contas.\n");

    puts("Contas 'ADMINISTRADORAS' tem acesso total");
    puts("às funcionalidades do SLS.\n");
    puts("Contas com esse perfil são capazes de adicionar novos");
    puts("items ao sistema bem como vizualiza-los, editá-los e excluí-los.\n");
    puts("Só é possível cadastrar novas contas ao sistema,");
    puts("vizualizar relatórios e alterar configurações");
    puts("com as funcionalidades de uma conta administradora.\n");

    puts("Contas 'LIMITADAS' tem acesso somente");
    puts("as ferramentas de vizualização e pesquisa de items.\n");

    puts("É possível acessar o manual com ambos os tipos de contas.\n");
}

// Tutorial about the first steps one may take
/* void first_steps()
{
} */