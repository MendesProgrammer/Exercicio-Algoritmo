#include <stdio.h>
#include <string.h>

#define Tamanho 10 // Tamanho máximo da nossa variável

typedef struct{
    int conta; // Número de conta
    int numero; // id do cliente
    int cpf; // Número do cpf
    char nome[30]; // Nome do cliente
    char opcao; // Opção da conta
    float saldo; // Saldo da conta
}banco;

int quant = 0; // Inicializando a variavel da quantidade de contas em 0
banco conta[Tamanho];

void cadastrar(){ // Funcao para o cadastro de novas contas
    char tipo, cnova;
    int id, i, flag=0, posi = 0, cpf, num_conta = 0, flag_conta = 0;
    float num_saldo;

    printf("Digite o id do cliente: ");
    scanf("%d", &id);

    for (i = 0; i < quant; i++) { // Repeticao para ver se ja existe uma conta cadastrada no ID do cliente
        if (conta[i].numero == id) {
        flag = 1; // flag vira 1 
        posi = i; // a posicao da conta ja cadastrada é salva, para buscarmos os dados depois
        }
    }

    if (flag == 1) { // Caso a flag for verdadeira, puxamos o CPF e nome ja existente para a nova conta
        do{
            printf ("Ja existe um cliente com esse id, deseja cadastrar mais uma conta para ele? (s/n)\n");
            fflush(stdin);
            scanf ("%s", &cnova);
            if(cnova != 's' && cnova != 'S' && cnova != 'n' && cnova != 'N'){
                printf("Erro, digite apenas ou S ou N\n");
            }
        } while (cnova != 's' && cnova != 'S' && cnova != 'n' && cnova != 'N');

        if (cnova == 's'){ 
            conta[quant].numero = id;
            conta[quant].cpf = conta[posi].cpf;
            strcpy(conta[quant].nome,conta[posi].nome);

            printf("O id da conta e: %d\n", conta[quant].numero);
            printf("O CPF da conta e: %d\n", conta[quant].cpf);
            printf("O nome do cliente e: %s\n", conta[quant].nome);
            
            do{
                flag_conta = 0;
                printf("Digite o numero da conta: \n");
                scanf("%d", &num_conta);
                for(int i = 0; i < quant; i++){
                    if(num_conta == conta[i].conta){
                        printf("Erro, este codigo ja foi usado\n");
                        flag_conta = 1;
                    }
                }
            } while(flag_conta == 1);


        }

        else if (cnova == 'n') { // se o cliente nao quiser cadastrar uma nova conta, ele retorna ao menu
            printf ("Cadastro encerrado, voltando ao menu\n");
            return;
        }

        else {
            printf("Codigo invalido\n");
            return;
        }

    }

    else if (flag == 0) { // caso o id nao tenha nenhuma conta ja cadastrada, o cadastro da nova conta segue normalmente, dessa vez verificando o CPF

        conta[quant].numero = id;

        printf("Digite o numero CPF: ");
        scanf("%d", &cpf);

        for (i = 0; i < quant; i++) { // Repeticao para ver se ja existe uma conta cadastrada no CPF do cliente
            if (conta[i].cpf == cpf) {
                flag = 1; // flag vira 1 
                posi = i; // a posicao da conta ja cadastrada é salva, para buscarmos os dados depois
            }
        }

        if (flag == 1) { // Caso a flag for verdadeira, puxamos o CPF, ID e nome ja existente para a nova conta
            do{
                printf ("Ja existe um cliente com esse id, deseja cadastrar mais uma conta para ele? (s/n)\n");
                fflush(stdin);
                scanf ("%s", &cnova);
                if(cnova != 's' && cnova != 'S' && cnova != 'n' && cnova != 'N'){
                    printf("Erro, digite apenas ou S ou N\n");
                }
            } while (cnova != 's' && cnova != 'S' && cnova != 'n' && cnova != 'N');

            if (cnova == 's'){
                conta[quant].numero = conta[posi].numero;
                conta[quant].cpf = conta[posi].cpf;
                strcpy(conta[quant].nome,conta[posi].nome);

                printf("o ID da conta ja cadastrado nesse CPF e: %d\n", conta[quant].numero); // Exibimos o ID antigo que ja cadastrado ao CPF
                printf("o CPF da conta e: %d\n", conta[quant].cpf);
                printf("O nome do cliente e: %s\n", conta[quant].nome);
            

                do{
                    flag_conta = 0;
                    printf("Digite o numero da conta: \n");
                    scanf("%d", &num_conta);
                    for(int i = 0; i < quant; i++){
                        if(num_conta == conta[i].conta){
                            printf("Erro, este codigo ja foi usado\n");
                            flag_conta = 1;
                        }
                    }
                } while(flag_conta == 1);


            }

            else if (cnova == 'n') { // se o cliente nao quiser cadastrar uma nova conta, ele retorna ao menu
                printf ("Cadastro encerrado, voltando ao menu\n");
                return;
            }

            else {
                printf("Codigo invalido\n");
                return;
            }

        }


        else { // em nenhum dos casos de dados iguais, o cadastro segue normalmente

            conta[quant].cpf = cpf;

            printf("Digite o numero da conta: ");
            scanf("%d", &conta[quant].conta);

            printf("Digite o nome do cliente: ");
            fflush(stdin);
            gets(conta[quant].nome);
            
        }
            
    }

    do{
        printf("Digite a opcao de conta: (D -> deposito | S - salario | P - poupanca) ");
        scanf("%c", &tipo);
        if(tipo != 'd' && tipo != 'D' && tipo != 'p' && tipo != 'P' && tipo != 's' && tipo != 'S'){
            printf("Erro, digite apenas entre conta corrente C, conta salario S ou conta poupanca P\n");
        }
    } while(tipo != 'd' && tipo != 'D' && tipo != 'p' && tipo != 'P' && tipo != 's' && tipo != 'S');
    conta[quant].opcao = tipo;

    do{
        printf("Digite o saldo da conta: ");
        scanf("%f", &num_saldo);
        if(num_saldo < 0){
            printf("Nao e permitido saldo negativo\n");
        }
    } while (num_saldo < 0);
    conta[quant].saldo = num_saldo;

    quant++; // Adicionando 1 ao contador do numero de contas
}

void mostrar(int ind){ // Funcao para exibir os dados de determinada conta
    printf("Cliente encontrado\n");
    printf("==============================\n");
    printf("Numero da conta: %d\n", conta[ind].conta);
    printf("ID do cliente: %d\n", conta[ind].numero);
    printf("Numero do CPF: %d\n", conta[ind].cpf);
    printf("Nome do cliente: %s\n", conta[ind].nome);
    printf("Tipo da conta: %c\n", conta[ind].opcao);
    printf("Saldo da conta: %.2f\n", conta[ind].saldo);
    printf("==============================\n");
}

void apagar(int ind){ // Funcao para apagar determinada conta ja cadastrada
    char car;
    do{
        mostrar(ind);
        printf("Deseja apagar? (s/n) ");
        scanf("%c", &car);
        fflush(stdin);
        if(car != 's' && car != 'S' && car != 'n' && car != 'N'){
            printf("Erro, digite apenas S ou N\n");
        }
    } while(car != 's' && car != 'S' && car != 'n' && car != 'N');

    if(car == 's' || car == 'S'){
        for(int i = ind; i < quant-1; i++){
            conta[i] = conta[i+1];
        }
        quant--; // Reduz o vetor da quantidade de contas em 1, liberando assim, mais um espaço para cadastro
        printf("Cliente excluido\n");

    } else if(car == 'n' || car == 'N'){
        printf("Retornando sem alteracoes\n");
    }

}

void buscar(int opt){ // Funcao para buscar determinado dado dentre as contas ja cadastradas
    int vt;
    int numero;
    char nom[30];
    int indice = -1;
    int res = 0;

        do{

        printf(" [1 - ID do cliente    ]\n");
        printf(" [2 - Numero do conta  ]\n");
        printf(" [3 - Numero do CPF    ]\n");
        printf(" [4 - Nome do cliente  ]\n");
        printf(" [5 - Sair para o menu ]\n");

        printf("Selecione uma opcao: ");
        scanf("%d", &vt);

        switch(vt){ // Switch case para o menu de busca
            case 1:
                printf("Digite o ID do cliente: ");
                scanf("%d", &numero);
                for(int i = 0; i < quant; i++){
                    if(numero == conta[i].numero){
                        indice = i;
                        if(opt == 1){
                            mostrar(i);
                        } else if(opt == 2){
                            apagar(i);
                        }
                    }
                }
                if(indice < 0){
                    printf("Nao ha cliente com essas credenciais\n");
                }
                break;

            case 2:
                printf("Digite o numero da conta: ");
                scanf("%d", &numero);
                for(int i = 0; i < quant; i++){
                    if(numero == conta[i].conta){
                        indice = i;
                        if(opt == 1){
                            mostrar(i);
                        } else if(opt == 2){
                            apagar(i);
                        }
                    }
                }
                if(indice < 0){
                    printf("Nao ha cliente com essas credenciais\n");
                }
                break;

            case 3:
                printf("Digite o numero do CPF: ");
                scanf("%d", &numero);
                for(int i = 0; i < quant; i++){
                    if(numero == conta[i].cpf){
                        indice = i;
                        if(opt == 1){
                            mostrar(i);
                        } else if(opt == 2){
                            apagar(i);
                        }
                    }
                }
                if(indice < 0){
                    printf("Nao ha cliente com essas credenciais\n");
                }
                break;

            case 4:
                printf("Digite o nome do cliente: ");
                fflush(stdin);
                gets(nom);
                for(int i = 0; i < quant; i++){
                    res = strcmp(nom, conta[i].nome);
                    if(res == 0){
                        indice = i;
                        if(opt == 1){
                            mostrar(i);
                        } else if(opt == 2){
                            apagar(i);
                        }
                    }
                }
                if(indice < 0){
                    printf("Nao ha cliente com essas credenciais\n");
                }
                break;

            case 5:
                printf("Retornando ao menu principal\n");
                break;

            default:
                printf("Opcao invalida");
                break;
        }
        } while(vt < 1 && vt > 5);
}

int main(){ // iniciando o int main apos ter cadastrado todas as funcoes e structs
    int opc;

    do{
        // Mostra ao usuário um menu de opções
        printf("\n=-=-=-=-=-=-=Menu principal=-=-=-=-=-=-=-=\n");
        printf(" [1 - Cadastrar conta        ]\n");
        printf(" [2 - Realizar busca         ]\n");
        printf(" [3 - Excluir conta          ]\n");
        printf(" [4 - Mostrar todas as contas]\n");
        printf(" [5 - Sair                   ]\n");

        // Solicita ao usuário que escolha uma opção
        printf("Digite uma opcao: ");
        scanf("%d", &opc);

        switch(opc){ // Switch case para o menu principal
            case 1:
                if(quant < 10){
                    printf("----------------Cadastrar conta do cliente----------------\n");
                    printf("=======================================================\n");
                    cadastrar();
                } else {
                    printf("Nao pode cadastrar mais clientes\n");
                }
                break;

            case 2:
                if(quant > 0){
                    printf("---------------Realizar busca de cliente--------------\n");
                    printf("=======================================================\n");
                    buscar(1);
                } else {
                    printf("Nao ha clientes cadastrados\n");
                }
                break;

            case 3:
                if(quant > 0){
                    printf("----------------Apagar conta do cliente----------------\n");
                    printf("=======================================================\n");
                    buscar(2);
                } else {
                    printf("Nao ha clientes cadastrados\n");
                }
                break;

            case 4:
                if(quant > 0){
                    printf("---------Mostrar todos os clientes cadastrados---------\n");
                    for(int i = 0; i < quant; i++){
                        mostrar(i);
                    }
                } else {
                    printf("Nao ha clientes cadastrados\n");
                }
                break;

            case 5:
                printf("Finalizando programa\n");
                break;

            default:
                break;
        }

    } while(opc != 5);

    return 0;
}
