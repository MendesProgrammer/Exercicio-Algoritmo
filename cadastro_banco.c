#include <stdio.h>
#include <string.h>

#define Tamanho 10

typedef struct{
    int conta; // Número de conta
    int numero; // id do cliente
    int cpf; // Número do cpf
    char nome[30]; // Nome do cliente
    char opcao; // Opção da conta
    float saldo; // Saldo da conta
}banco;

int quant = 0;
banco conta[Tamanho];

void cadastrar(){
    char tipo;

    printf("Digite o numero do cliente: ");
    scanf("%d", &conta[quant].numero);

    printf("Digite o numero CPF: ");
    scanf("%d", &conta[quant].cpf);

    printf("Digite o numero da conta: ");
    scanf("%d", &conta[quant].conta);

    printf("Digite o nome do cliente: ");
    fflush(stdin);
    gets(conta[quant].nome);

    do{
        printf("Digite a opcao de conta: (D -> deposito | S - salario | P - pagamento) ");
        scanf("%c", &tipo);
        if(tipo != 'd' && tipo != 'D' && tipo != 'p' && tipo != 'P' && tipo != 's' && tipo != 'S'){
            printf("Erro, digite apenas entre conta corrente C ou conta poupança P\n");
        }
    } while(tipo != 'd' && tipo != 'D' && tipo != 'p' && tipo != 'P' && tipo != 's' && tipo != 'S');
    conta[quant].opcao = tipo;

    printf("Digite o saldo da conta: ");
    scanf("%f", &conta[quant].saldo);

    quant++;
}

void mostrar(int ind){
    printf("Cliente encontrado\n");
    printf("==============================\n");
    printf("Numero da conta: %d\n", conta[ind].conta);
    printf("Numero do cliente: %d\n", conta[ind].numero);
    printf("Numero do CPF: %d\n", conta[ind].cpf);
    printf("Nome do cliente: %s\n", conta[ind].nome);
    printf("Tipo da conta: %c\n", conta[ind].opcao);
    printf("Saldo da conta: %.2f\n", conta[ind].saldo);
    printf("==============================\n");
}

void apagar(int ind){
    char car;
    do{
        mostrar(ind);
        printf("Deseja apagar? (s/n) ");
        scanf("%c", &car);
        if(car != 's' && car != 'S' && car != 'n' && car != 'N'){
            printf("Erro, digite apenas S ou N\n");
        }
    } while(car != 's' && car != 'S' && car != 'n' && car != 'N');

    if(car == 's' || car == 'S'){
        for(int i = ind; i < quant-1; i++){
            conta[i] = conta[i+1];
        }
        quant--;
        printf("Cliente excluido\n");

    } else if(car == 'n' || car == 'N'){
        printf("Retornando sem alteracoes\n");
    }

}

void buscar(int opt){
    int vt;
    int numero;
    char nom[30];
    int indice = -1;
    int res = 0;

        do{

        printf(" [1 - Numero do cliente]\n");
        printf(" [2 - Numero do conta  ]\n");
        printf(" [3 - Numero do CPF    ]\n");
        printf(" [4 - Nome do cliente  ]\n");
        printf(" [1 - Sair             ]\n");

        printf("Selecione uma opcao: ");
        scanf("%d", &vt);

        switch(vt){
            case 1:
                printf("Digite o numero do cliente: ");
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

int main(){
    int opc;

    do{
        // Mostra ao usuário um menu de opções
        printf("\n=-=-=-=-=-=-=Menu principal=-=-=-=-=-=-=-=\n");
        printf(" [1 - Incluir conta          ]\n");
        printf(" [2 - Realizar busca         ]\n");
        printf(" [3 - Excluir conta          ]\n");
        printf(" [4 - Mostrar todas as opcoes]\n");
        printf(" [5 - Sair                   ]\n");

        // Solicita ao usuário que escolha uma opção
        printf("Digite uma opcao: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                if(quant < 10){
                    printf("----------------Apagar conta do cliente----------------\n");
                    printf("=======================================================\n");
                    cadastrar();
                } else {
                    printf("Nao pode cadastrar mais clientes\n");
                }
                break;

            case 2:
                if(quant > 0){
                    printf("---------------Buscar cadastro de cliente--------------\n");
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
