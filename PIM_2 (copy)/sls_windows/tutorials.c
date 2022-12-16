#include <stdio.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Function that will print a newcomer message
void newcomer_message_first()
{

    // Clear terminal screen
    boilerplate();

    puts("Seja bem-vindo(a) ao Simple Logistical System!\n");
    puts("Para comecar a utilizar o sistema, cadastre sua primeira conta");
    puts("que, por padrao, tera o escopo de CONTA ADMINISTRADORA.\n");

    puts("Para saber mais sobre as diferentes contas que o SLS suporta");
    puts("e suas particularidades, selecione a opcao 8 no menu");
    puts("ou acesse a secao 'Manual' em nosso site!\n\n");

    press_to_continue();
}

// Function that will print another newcomer message
void newcomer_message_second()
{

    // Clear terminal screen
    boilerplate();

    puts("Conta criada com sucesso!\n");
    puts("Não se esqueça de guardar as credenciais fornecidas");
    puts("em um lugar seguro.\n");

    puts("A seguir voce sera redirecionado(a) para o MENU.");
    puts("A tela do menu discrimina as diferentes funcionalidades do sistema");
    puts("assim como seu respectivo numero de designacao.\n");

    puts("Para acessar qualquer funcionalidade que desejar");
    puts("digite o numero correspondente aquela ferramenta");
    puts("e pressione ENTER\n\n");

    press_to_continue();
}

// Tutorial about different accounts
void tutorial_accounts()
{

    boilerplate();

    puts("Na versao 1.0 do SLS, existem dois tipos de contas.\n");

    puts("Contas 'ADMINISTRADORAS' tem acesso total");
    puts("as funcionalidades do SLS.\n");
    puts("Contas com esse perfil sao capazes de adicionar novos");
    puts("items ao sistema bem como vizualiza-los, edita-los e exclui-los.\n");
    puts("So e possível cadastrar novas contas ao sistema,");
    puts("com as funcionalidades de uma conta administradora.\n");

    puts("Contas 'LIMITADAS' tem acesso somente");
    puts("as ferramentas de vizualizacao e pesquisa de items e relatorios.\n");

    puts("E possivel acessar o manual com ambos os tipos de contas.\n\n");
}

// Tutorial about the first steps one may take
void first_steps()
{

    boilerplate();

    puts("1 / 2\n");

    puts("Se essa e a primeira vez que voce esta utilizando");
    puts("o sistema, a conta logada no momento e 'ADMINISTRADORA'!\n");

    puts("Isso siginifica que todas as funcionalidades do sistema");
    puts("estao disponiveis no momento.\n");

    puts("O primeiro passo e adicionar um novo item.\n");

    getchar();
    press_to_continue();

    boilerplate();

    puts("2 / 2\n");

    puts("O SLS 1.0 possui tres diferentes 'modalidades'");
    puts("de items que podem ser cadastrados: \n");

    puts("1 - PODUTO\n");

    puts("2 - FORNECEDOR\n");

    puts("3 - FUNCIONARIO\n");

    puts("\t\t\t<<<<<<<<<< OPCOES >>>>>>>>>>\n");

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
    puts("Os items do formato 'PRODUTO' tEm como categorias: \n");
    puts("Nome: Um nome generico atribuido ao produto.\n");

    puts("Quantidade: Atribuicao generica a quantidade do produto");
    puts("referente ao criterio utilizado para medir o mesmo.");
    puts("E possivel que a quantidade se refira a um valor unitario");
    puts("ou um valor de metros, centimetros, etc.");
    puts("De qualquer forma, deve-se atribuir apenas um numero inteiro");
    puts("e não informar mais nada.");
    puts("Correto: 2 | Errado: 2cm\n");

    puts("Valor unitario: Especificacao de quanto vale cada unidade do produto.");
    puts("Essa informacao deve respeitar o criterio metrico que e utilizado");
    puts("em particular para tipos diferentes de produtos.");
    puts("Ex: Caso eu informe que o valor unitário de um fio de cobre e 2.00");
    puts("estarei informando que sao 2.00 a cada 10 cm.\n");

    puts("Valor total: Produto da multiplicacao da quantidade e valor unitario do produto.\n");

    getchar();
    press_to_continue();

    boilerplate();

    puts("2 / 3\n");
    puts("FORNECEDOR: \n");
    puts("Os items do formato 'FORNECEDOR' tem como categorias: \n");
    puts("Nome: Um nome generico atribuido ao produto.\n");

    puts("Nome do responsavel: Nome da pessoa que e responsavel pela");
    puts("comunicacao e/ou intermediacao no momento do contato.\n");

    puts("Cidade: Onde o fornecedor esta localizado.\n");

    puts("Tipo de serviço: Atribuicao generica ao tipo de servico que");
    puts("que aquele fornecedor oferece.");
    puts("Ex: Construtora, Eletricista, Materias de contrucao e etc.\n");

    puts("Contato: Número de contato do fornecedor.");

    puts("Email: Email de contato do fornecedor.\n");

    press_to_continue();

    boilerplate();

    puts("3 / 3\n");
    puts("FUNCIONARIO: \n");
    puts("Os items do formato 'FUNCIONARIO' trm como categorias: \n");
    puts("Nome: Nome do funcionario.\n");

    puts("Cargo: Cargo/Area de atuacao do funcionario.\n");

    puts("Salario: Valor do salario do funcionario.");
    puts("Numeros reais devem representar as casas apos a virgula separadas");
    puts("pelo caractere '.' .\n");

    puts("Data de Admissao: Data de quando o funcionario foi admitido/contratado.\n\n");

    puts("\t\t\t<<<<<<<<<< OPCOES >>>>>>>>>>\n");

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

    puts("A partir deste momento, aparecerao as seguintes opcoes na tela: \n");

    puts("1 - Cadastrar PRODUTO\n");
    puts("2 - Cadastrar FORNECEDOR\n");
    puts("3 - Cadastrar FUNCIONARIO\n");

    puts("Ao digitar o numero referente à modalidade de produto que devera ser registrada");
    puts("e apertar ENTER, uma nova tela aparecera e ira solicitar que seja digitada");
    puts("a informação referente a categoria especificada.");
    puts("Ex: Cidade: (O usuario devera digitar a cidade referente aquele item).\n\n");

    puts("\t\t\t<<<<<<<<<< OPCOES >>>>>>>>>>\n");

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

    puts("Para vizualizar um item, basta digitar o número referente a ferramenta 'Vizualizar item'");
    puts("e pressionar ENTER.\n");

    puts("A partir deste momento, aparecerão as seguintes opcoes na tela: \n");

    puts("1 - Vizualizar PRODUTO\n");
    puts("2 - Vizualizar FORNECEDOR\n");
    puts("3 - Vizualizar FUNCIONARIO\n");

    puts("Ao digitar o numero referente a modalidade de produto que devera ser registrada");
    puts("e apertar ENTER, uma nova tela aparecera e ira solicitar que seja selecionada");
    puts("uma modalidade de vizualizacao.\n");

    puts("No SLS 1.0 e possível selecionar duas formas de vizualizacao: \n");

    puts("Vizualizar todos: Nesta modalidade, o programa exibira na tela todos os items");
    puts("daquela modalidade presentes na respectiva base de dados");
    puts("sem nenhuma sequencia específica.\n");

    puts("Pesquisar: Nesta modalidade, sera possível selecionar entre uma lista de opcoes,");
    puts(" especifica a modalidade de item selecionada, e digitar uma busca relacionada");
    puts("aquele criterio que retornara um ou mais items.");
    puts("(Sera exibida uma mensagem especifica caso nenhum item seja encontrado na busca)\n");

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