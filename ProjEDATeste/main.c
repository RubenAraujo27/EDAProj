#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "gestores.h"
#include "meiosmob.h"


void menuClientes() {

    Vehicles* lista2 = NULL;
    Clients* lista = NULL;
    Managers* lista1 = NULL;
    int opcao, i, id, num = 0;
    do {
        printf("Menu de Clientes:\n");
        printf("1. Alugar Veiculo\n");
        printf("2. Cancelar Aluguer\n");
        printf("3. Voltar ao menu principal\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            /*i = 0;
            listarMeiosLivres(lista2, 0);
            do {
                if (i == 0)
                    printf("\nIndique um ID para o meio:");
                if (i > 0)
                    printf("\nIndique um ID valido:");
                scanf("%d", &id);
                i++;
            } while ((existeMeio(lista2, id) == 0) && (meioLivre(lista2, id) == 0));
            alugarMeio(lista2, lista, id);
            id = 0;*/
            break;
        case 2:
            /*num = listarMeiosAlugados(lista2, lista, 0);
            if (num == 0) {
                printf("\nEste utilizador nao tem meios alugados\n");
            }
            else {
                i = 0;
                do {
                    if (i == 0)
                        printf("\nIndique o ID do meio que deseja terminar o aluger: ");
                    if (i > 0)
                        printf("\nIndique o ID de um meio que tenha alugado: ");
                    scanf("%d", &id);
                    i++;
                } while ((meioAlugado(lista2, id, lista) == 0));
                terminarAluguer(lista2, lista, id);
            }
            num = 0;
            id = 0;*/
            break;
        case 3:
            return;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao != 3);
}

void menuGestores() {
    char nome[MAX_NOME], NIF[MAX_NIF];
    int id = 0;
    Clients* lista = NULL;
    Managers* lista1 = NULL;
    Vehicles* lista2 = NULL;

    readManagers(&lista1);
    readClientes(&lista);
    readMeios(&lista2);
    int opcao;
    do {
        printf("Menu de Gestores:\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Remover Cliente\n");
        printf("3. Adicionar saldo a um Cliente\n");
        printf("4. Adicionar Gestor\n");
        printf("5. Remover Gestor\n");
        printf("6. Adicionar um Meio\n");
        printf("7. Remover um Meio\n");
        printf("8. Adicionar autonomia a um Meio\n");
        printf("9. Adicionar percentagem de bateria a um Meio\n");
        printf("10. Gravar e voltar ao Menu Principal\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            inserirCliente(&lista);
            break;
        case 2:
            printf("Indique o NIF do cliente que quer remover: ");
            scanf("%s", nome);
            while ((getchar()) != '\n');
            removerCliente(&lista, nome);
            break;
        case 3:
            adicionarSaldoCliente(&lista);
            break;
        case 4:
            inserirGestor(&lista1);
            break;
        case 5:
            printf("Indique o NIF do gestor que quer remover: ");
            scanf("%s", NIF);
            while ((getchar()) != '\n');
            removerGestor(&lista1, NIF);
            break;
        case 6:
            inserirMeio(&lista2);
            break;
        case 7:
            printf("Indique o ID do meio que quer remover: ");
            scanf("%d", &id);
            while ((getchar()) != '\n');
            removerMeio(&lista2, id);
            break;
        case 8:
            adicionarAutonomia(&lista2);
            break;
        case 9:
            adicionarBateria(&lista2);
        case 10:
            gravarTextoClientes(lista);
            gravarTextoMeio(lista2);
            gravarTextoManagers(lista1);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao != 10);
}

int main() {
    int opcao;

    do {
        printf("Menu principal:\n");
        printf("1. Ir para o Menu de Clientes\n");
        printf("2. Ir para o Menu de Gestores\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            menuClientes();
            break;
        case 2:
            menuGestores();
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao != 3);
    return 0;
}
