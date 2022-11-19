#include <stdio.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Function that will print a newcomer message
void newcomer_message_first()
{

    // Clear terminal screen
    boilerplate();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Seja bem-vindo(a) ao Simple Logistical System!\n");
    puts("Para começar a utilizar o sistema, cadastre sua primeira conta");
    puts("que, por padrão, tera o escopo de CONTA ADMINISTRADORA.\n");

    puts("Para saber mais sobre as diferentes contas que o SLS suporta");
    puts("e suas particularidades, selecione a opção 8 no menu");
    puts("ou acesse a seção 'Manual' em nosso site!\n\n");

    press_to_continue();
}

// Function that will print another newcomer message
void newcomer_message_second()
{

    // Clear terminal screen
    boilerplate();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Conta criada com sucesso!\n");
    puts("Não se esqueça de guardar as credenciaus fornecidas");
    puts("em um lugar seguro.\n");

    puts("A seguir você será redirecionado(a) para o MENU.");
    puts("A tela do menu discrimina as diferentes funcionalidades do sistema");
    puts("assim como seu respectivo número de designação.\n");

    puts("Para acessar qualquer funcionalidade que desejar");
    puts("digite o número correspondente aquela ferramenta");
    puts("e pressione ENTER\n\n");

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
    puts("com as funcionalidades de uma conta administradora.\n");

    puts("Contas 'LIMITADAS' tem acesso somente");
    puts("as ferramentas de vizualização e pesquisa de items e relatórios.\n");

    puts("É possível acessar o manual com ambos os tipos de contas.\n\n");
}

// Tutorial about the first steps one may take
void first_steps()
{

    boilerplate();

    puts("1 / 2\n");

    puts("Se essa é a primeira vez que você esta utilizando");
    puts("o sistema, a conta logada no momento é 'ADMINISTRADORA'!\n");

    puts("Isso siginifica que todas as funcionalidades do sistema");
    puts("estão disponíveis no momento.\n");

    puts("O primeiro passo é adicionar um novo item.\n");

    getchar();
    press_to_continue();

    boilerplate();

    puts("2 / 2\n");

    puts("O SLS 1.0 possui três diferentes 'modalidades'");
    puts("de items que podem ser cadastrados: \n");

    puts("1 - PODUTO\n");

    puts("2 - FORNECEDOR\n");

    puts("3 - FUNCIONÁRIO\n");

    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Saber mais sobre cada modalidade de item\n");
    puts("ENTER - Voltar ao menu\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    char storage;

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        item_modality();
        break;
    default:
        press_to_continue();
        if (check_account_type() == 0)
        {
            menu_manual_admin();
        }
        else
        {
            menu_manual_limited();
        }
    }
}

void item_modality()
{

    boilerplate();

    puts("1 / 3\n");
    puts("PRODUTOS: \n");
    puts("Os items do formato 'PRODUTO' têm como categorias: \n");
    puts("Nome: Um nome genérico atribuido ao produto.\n");

    puts("Quantidade: Atribuição gnérica a quantidade do produto");
    puts("referente ao critério utilizado para medir o mesmo.");
    puts("É possível que a quantidade se refira a um valor unitário");
    puts("ou um valor de metros, centímetros, etc.");
    puts("De qualquer forma, deve-se atribuir apenas um numero inteiro");
    puts("e não informar mais nada.");
    puts("Correto: 2 | Errado: 2cm\n");

    puts("Valor unitário: Especificação de quanto vale cada unidade do produto.");
    puts("Essa informação deve respeitar o critério métrico que é utilizado");
    puts("em particular para tipos diferentes de produtos.");
    puts("Ex: Caso eu informe que o valor unitário de um fio de cobre é 2.00");
    puts("estarei informando que são 2.00 a cada 10 cm.\n");

    puts("Valor total: Produto da multiplicação da quantidade e valor unitário do produto.\n");

    getchar();
    press_to_continue();

    boilerplate();

    puts("2 / 3\n");
    puts("FORNECEDOR: \n");
    puts("Os items do formato 'FORNECEDOR' tẽm como categorias: \n");
    puts("Nome: Um nome genérico atribuido ao produto.\n");

    puts("Nome do responsável: Nome da pessoa que é responsável pela");
    puts("comunicação e/ou intermediação no momento do contato.\n");

    puts("Cidade: Onde o fornecedor esta localizado.\n");

    puts("Tipo de serviço: Atribuição genérica ao tipo de serviço que");
    puts("que aquele fornecedor oferece.");
    puts("Ex: Construtora, Eletricista, Materias de contrução e etc.\n");

    puts("Contato: Número de contato do fornecedor.");

    puts("Email: Email de contato do fornecedor.\n");

    press_to_continue();

    boilerplate();

    puts("3 / 3\n");
    puts("FUNCIONÁRIO: \n");
    puts("Os items do formato 'FUNCIONÁRIO' têm como categorias: \n");
    puts("Nome: Nome do funcionário.\n");

    puts("Cargo: Cargo/Area de atuação do funcionário.\n");

    puts("Salário: Valor do salário do funcionário.");
    puts("Número reais devem representar as casas após a virgula separadas");
    puts("pelo caractére '.' .\n");

    puts("Data de Admissão: Data de quando o funcionário foi admitido/contratado.\n\n");

    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Saber como cadastrar um item\n");
    puts("ENTER - Voltar ao menu\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    char storage;

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        item_signup();
        break;
    default:
        getchar();
        press_to_continue();
        if (check_account_type() == 0)
        {
            menu_manual_admin();
        }
        else
        {
            menu_manual_limited();
        }
    }
}

void item_signup()
{

    boilerplate();

    puts("Para cadastrar um item basta digitar a tecla '1'");
    puts("e pressionar ENTER.\n");

    puts("A partir deste momento, aparecerão as seguintes opções na tela: \n");

    puts("1 - Cadastrar PRODUTO\n");
    puts("2 - Cadastrar FORNECEDOR\n");
    puts("3 - Cadastrar FUNCIONÁRIO\n");

    puts("Ao digitar o número referente à modalidade de produto que devera ser registrada");
    puts("e apertar ENTER, uma nova tela aparecera e irá solicitar que seja digitada");
    puts("a informação referente a categoria especificada.");
    puts("Ex: Cidade: (O usuário devera digitar a cidade referente aquele item).\n\n");

    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Saber como vizualizar um item\n");
    puts("ENTER - Voltar ao menu\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    char storage;

    getchar();

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        item_view();
    default:
        getchar();
        press_to_continue();
        if (check_account_type() == 0)
        {
            menu_manual_admin();
        }
        else
        {
            menu_manual_limited();
        }
    }
}

void item_view()
{

    boilerplate();

    puts("Para vizualizar um item, basta digitar o número referente à ferramenta 'Vizualizar item'");
    puts("e pressionar ENTER.\n");

    puts("A partir deste momento, aparecerão as seguintes opções na tela: \n");

    puts("1 - Vizualizar PRODUTO\n");
    puts("2 - Vizualizar FORNECEDOR\n");
    puts("3 - Vizualizar FUNCIONÁRIO\n");

    puts("Ao digitar o número referente à modalidade de produto que devera ser registrada");
    puts("e apertar ENTER, uma nova tela aparecera e irá solicitar que seja selecionada");
    puts("uma modalidade de vizualização.\n");

    puts("No SLS 1.0 é possível selecionar duas formas de vizualização: \n");

    puts("Vizualizar todos: Nesta modalidade, o programa exibira na tela todos os items");
    puts("daquela modalidade presentes na respectiva base de dados");
    puts("sem nenhuma sequência específica.\n");

    puts("Pesquisar: Nesta modalidade, será possível selecioanar entre uma lista de opções,");
    puts(" específica à modalidade de item selecionada, e digitar uma busca relacionada");
    puts("aquele critério que retornara um ou mais items.");
    puts("(Sera exibida uma mensagem específica caso nenhum item seja encontrado na busca)\n");

    getchar();

    press_to_continue();

    if (check_account_type() == 0)
    {
        menu_manual_admin();
    }
    else
    {
        menu_manual_limited();
    }
}