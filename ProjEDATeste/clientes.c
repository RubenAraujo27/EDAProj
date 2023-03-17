#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

/**
 * .        Função que lê os dados introduzidos para o registo de um Cliente
 * 
 * \param   lista Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Clientes
 */
void inserirCliente(Clients** lista) {
    Clients* novo_cliente = (Clients*)malloc(sizeof(Clients));

    while ((getchar()) != '\n');
    printf("Insira o NIF do cliente: ");
    fgets(novo_cliente->NIF, MAX_NIF, stdin);
    novo_cliente->NIF[strlen(novo_cliente->NIF) - 1] = '\0';

    while ((getchar()) != '\n');
    printf("Insira o nome do cliente: ");
    fgets(novo_cliente->nome, MAX_NOME, stdin);
    novo_cliente->nome[strlen(novo_cliente->nome) - 1] = '\0';

    while ((getchar()) != '\n');
    printf("Insira a morada do cliente: ");
    scanf("%s", novo_cliente->morada);


    while ((getchar()) != '\n');
    printf("Insira a senha do cliente: ");
    scanf("%s", novo_cliente->password);


    while ((getchar()) != '\n');
    printf("Insira a idade do cliente: ");
    scanf("%d", &novo_cliente->idade);


    while ((getchar()) != '\n');
    printf("Insira o saldo do cliente: ");
    scanf("%f", &novo_cliente->saldo);



    novo_cliente->next = *lista;
    *lista = novo_cliente;
}

/**
 * .        Função que adiciona um novo Cliente e os seus dados a lista de Clientes  
 * 
 * \param   lista       Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Clientes
 * \param   NIF         NIF do Cliente a ser inserido
 * \param   nome        Nome do Cliente a ser inserido
 * \param   morada      Morada do Cliente a ser inserido
 * \param   password    Palavra-passe do Cliente a ser inserido
 * \param   idade       Idade do Cliente a ser inserido
 * \param   saldo       Saldo do Cliente a ser inserido
 */
void inserirCliente1(Clients** lista, char NIF[], char nome[], char morada[], char password[], int idade, float saldo) {
    Clients* novo_cliente = (Clients*)malloc(sizeof(Clients));

    strcpy(novo_cliente->NIF, NIF);
    strcpy(novo_cliente->nome, nome);
    strcpy(novo_cliente->morada, morada);
    strcpy(novo_cliente->password, password);
    novo_cliente->idade = idade;
    novo_cliente->saldo = saldo;


    novo_cliente->next = *lista;
    *lista = novo_cliente;
}

/**
 * .        Função para remover um Cliente através do seu NIF
 * 
 * \param   lista   Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Clientes
 * \param   NIF     NIF para verificação do Cliente
 */
void removerCliente(Clients** lista, char NIF[]) {
    //Percorre a lista a procura do cliente com determinado NIF
    Clients* atual = *lista;
    Clients* anterior = NULL;

    while (atual != NULL && strcmp(atual->NIF, NIF) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    //Se o cliente não for encontrado, exibe a seguinte mensagem
    if (atual == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    //Remove o cliente da lista
    if (anterior == NULL) {
        //O cliente a ser removido é o primeiro da lista
        *lista = atual->next;
    }
    else {
        anterior->next = atual->next;
    }

    free(atual);
    printf("Cliente removido com sucesso.\n");
}

/**
 * .        Função para guardar os dados dos Clientes num ficheiro de texto
 * 
 * \param   lista   Apontador para o inicio da lista ligada dos Clientes
 */
void gravarTextoClientes(Clients* lista) {
    FILE* fp;

    fp = fopen("clientes.txt", "w");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (lista != NULL) {

        fprintf(fp, "%s;%s;%s;%s;%d;%.2f\n", lista->NIF, lista->nome, lista->morada, lista->password, lista->idade, lista->saldo);

        lista = lista->next;
    }

    fclose(fp);
    printf("Dados gravados com sucesso no ficheiro clientes.txt.\n");
}

/**
 * .        Função para carregar os dados dos clientes do ficheiro de texto
 * 
 * \param   lista   Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Clientes
 */
void readClientes(Clients** lista) {
    FILE* fp;
    float saldo;
    char nome[MAX_NOME], morada[MAX_MORADA], NIF[MAX_NIF], password[MAX_PASSWORD];
    int idade;
    char line[1024];
    char* campo1, * campo2, * campo3, * campo4, * campo5, * campo6;

    fp = fopen("clientes.txt", "r");

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {

            campo1 = strtok(line, ";");
            campo2 = strtok(NULL, ";");
            campo3 = strtok(NULL, ";");
            campo4 = strtok(NULL, ";");
            campo5 = strtok(NULL, ";");
            campo6 = strtok(NULL, ";");

            strcpy(NIF, campo1);
            strcpy(nome, campo2);
            strcpy(morada, campo3);
            strcpy(password, campo4);
            idade = atoi(campo5);
            saldo = atof(campo6);

            inserirCliente1(&(*lista), NIF, nome, morada, password, idade, saldo);
        }
        fclose(fp);
        printf("Dados de clientes carregados com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o ficheiro.\n");
    }
}

/**
 * .        Função que adiciona saldo ao cliente com o NIF específico
 * 
 * \param   lista   Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Clientes
 */
void adicionarSaldoCliente(Clients** lista) {
    char NIF[9];
    float saldo;

    printf("Digite o NIF do cliente: ");
    scanf("%s", NIF);
    while ((getchar()) != '\n');

    printf("Digite o saldo a ser adicionado: ");
    scanf("%f", &saldo);
    while ((getchar()) != '\n');

    Clients* cliente = *lista;

    //Percorre a lista de clientes a procura do cliente com o NIF introduzido
    while (cliente != NULL) {
        if (strcmp(cliente->NIF, NIF) == 0) {
            //Atualiza o saldo do cliente
            cliente->saldo += saldo;
            printf("Saldo atualizado com sucesso. Saldo atual: %.2f\n", cliente->saldo);
            break;
        }
        cliente = cliente->next;
    }

    if (cliente == NULL) {
        printf("Cliente nao encontrado na lista.\n");
    }
}
