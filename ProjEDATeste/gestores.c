#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestores.h"

/**
 * .        Função que lê os dados introduzidos para o registo de um Gestor
 * 
 * \param   lista1 Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Gestores
 */
void inserirGestor(Managers** lista1) {
    Managers* novo_gestor = (Managers*)malloc(sizeof(Managers));

    printf("Insira o NIF do gestor: ");
    scanf("%s", novo_gestor->NIF);
    while ((getchar()) != '\n');

    printf("Insira o nome do gestor: ");
    scanf("%s", novo_gestor->nome);
    while ((getchar()) != '\n');

    printf("Insira a senha do gestor: ");
    scanf("%s", novo_gestor->password);
    while ((getchar()) != '\n');

    novo_gestor->next = *lista1;
    *lista1 = novo_gestor;
}

/**
 * .        Função que adiciona um novo Gestor e os seus dados a lista de Gestores
 * 
 * \param   lista1    Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Gestores
 * \param   NIF       NIF do Gestor a ser inserido
 * \param   nome      Nome do Gestor a ser inserido
 * \param   password  Palavra-passe do Gestor a ser inserido
 */
void inserirGestores1(Managers** lista1, char NIF[], char nome[], char password[]) {
    Managers* novo_gestor = (Managers*)malloc(sizeof(Managers));

    strcpy(novo_gestor->NIF, NIF);
    strcpy(novo_gestor->nome, nome);
    strcpy(novo_gestor->password, password);


    novo_gestor->next = *lista1;
    *lista1 = novo_gestor;
}

/**
 * .        Função para remover um Gestor através do seu NIF
 * 
 * \param   lista1    Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Gestores
 * \param   NIF       NIF para verificação do Gestor
 */
void removerGestor(Managers** lista1, char NIF[]) {
    //Percorre a lista a procura do cliente com determinado NIF
    Managers* atual = *lista1;
    Managers* anterior = NULL;

    while (atual != NULL && strcmp(atual->NIF, NIF) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    //Se o cliente não for encontrado, exibe a seguinte mensagem
    if (atual == NULL) {
        printf("Gestor nao encontrado.\n");
        return;
    }

    //Remove o cliente da lista
    if (anterior == NULL) {
        //O cliente a ser removido é o primeiro da lista
        *lista1 = atual->next;
    }
    else {
        anterior->next = atual->next;
    }

    free(atual);
    printf("Gestor removido com sucesso.\n");
}

/**
 * .        Função para guardar os dados dos Gestores num ficheiro de texto
 * 
 * \param   lista1 Apontador para o inicio da lista ligada dos Gestores
 */
void gravarTextoManagers(Managers* lista1) {
    FILE* fp;

    fp = fopen("gestores.txt", "w");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (lista1 != NULL) {

        fprintf(fp, "%s;%s;%s\n", lista1->NIF, lista1->nome, lista1->password);

        lista1 = lista1->next;
    }

    fclose(fp);
    printf("Dados gravados com sucesso no ficheiro gestores.txt.\n");
}

/**
 * .        Função para carregar os dados dos gestores do ficheiro de texto
 * 
 * \param   lista1 Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Gestores
 */
void readManagers(Managers** lista1) {
    FILE* fp;
    char nome[MAX_NOME], NIF[MAX_NIF], password[MAX_PASSWORD];
    char line[1024];
    char* campo1, * campo2, * campo3;

    fp = fopen("gestores.txt", "r");

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {

            campo1 = strtok(line, ";");
            campo2 = strtok(NULL, ";");
            campo3 = strtok(NULL, ";");

            strcpy(NIF, campo1);
            strcpy(nome, campo2);
            strcpy(password, campo3);
            NIF[strlen(NIF) - 1] = '\0';
            nome[strlen(nome) - 1] = '\0';
            password[strlen(password) - 1] = '\0';

            inserirGestores1(&(*lista1), NIF, nome, password);
        }
        fclose(fp);
        printf("Dados de gestores carregados com sucesso!\n");
    }
    else {
        printf("Erro ao abrir o ficheiro.\n");
    }
}