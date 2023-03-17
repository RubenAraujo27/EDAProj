#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meiosmob.h"

/**
 * .		Função que lê os dados introduzidos para o registo de um Meio
 * 
 * \param	lista2 lista Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Meios
 */
void inserirMeio(Vehicles** lista2) {
	Vehicles* novo_meio = (Vehicles*)malloc(sizeof(Vehicles));

	while ((getchar()) != '\n');
	printf("Insira o tipo do meio: ");
	fgets(novo_meio->tipo, MAX_TIPO, stdin);
	novo_meio->tipo[strlen(novo_meio->tipo) - 1] = '\0';

	while ((getchar()) != '\n');
	printf("Insira ID do meio: ");
	scanf("%d", &novo_meio->id);

	while ((getchar()) != '\n');
	printf("Insira a autonomia do meio: ");
	scanf("%d", &novo_meio->autonomia);

	while ((getchar()) != '\n');
	printf("Insira a percentagem de bateria do meio: ");
	scanf("%d", &novo_meio->bateria);

	novo_meio->next = *lista2;
	*lista2 = novo_meio;
}

/**
 * .		Função que adiciona um novo Meio a lista de Meios
 * 
 * \param	lista2		Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Meios
 * \param	tipo		Tipo do Meio a ser inserido
 * \param	autonomia	Autonomia do Meio a ser inserido
 * \param	bateria		Percentagem de Bateria do Meio a ser inserido
 * \param	id			ID do Meio a ser inserido
 */
void inserirMeio1(Vehicles** lista2, char tipo[], int autonomia, int bateria, int id) {
	Vehicles* novo_meio = (Vehicles*)malloc(sizeof(Vehicles));

	strcpy(novo_meio->tipo, tipo);
	novo_meio->autonomia = autonomia;
	novo_meio->bateria = bateria;
	novo_meio->id = id;


	novo_meio->next = *lista2;
	*lista2 = novo_meio;
}

/**
 * .		Função para remover um Meio através do seu ID
 * 
 * \param	lista2	Apontador para a variavel que guarda o apontador para a inicio da lista ligada dos Meios
 * \param	id		ID para verificação do Meio
 */
void removerMeio(Vehicles** lista2, int id) {
	//Percorre a lista a procura do meio com o ID introduzido
	Vehicles* atual = *lista2;
	Vehicles* anterior = NULL;

	while (atual != NULL && (atual->id != id)) {
		anterior = atual;
		atual = atual->next;
	}

	//Se o meio não for encontrado, exibe a seguinte mensagem
	if (atual == NULL) {
		printf("Meio nao encontrado.\n");
		return;
	}

	//Remove o meio da lista
	if (anterior == NULL) {
		//O meio a ser removido é o primeiro da lista
		*lista2 = atual->next;
	}
	else {
		anterior->next = atual->next;
	}

	free(atual);
	printf("Meio removido com sucesso.\n");
}

/**
 * .		Função para guardar os dados dos Meios num ficheiro de texto
 * 
 * \param	lista2	Apontador para o inicio da lista ligada dos Meios
 */
void gravarTextoMeio(Vehicles* lista2) {
	FILE* fp;

	fp = fopen("meios.txt", "w");

	if (fp == NULL) {
		printf("Erro ao abrir o ficheiro.\n");
		return;
	}

	while (lista2 != NULL) {

		fprintf(fp, "%s;%d;%d;%d\n", lista2->tipo, lista2->autonomia, lista2->bateria, lista2->id);

		lista2 = lista2->next;
	}

	fclose(fp);
	printf("Dados gravados com sucesso no ficheiro meios.txt.\n");
}

/**
 * .		Função para carregar os dados dos Meios do ficheiro de texto
 * 
 * \param	lista2	Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Meios
 */
void readMeios(Vehicles** lista2) {
	FILE* fp;
	char tipo[MAX_TIPO];
	int autonomia, bateria, id;
	char line[1024];
	char* campo1, * campo2, * campo3, * campo4;

	fp = fopen("meios.txt", "r");

	if (fp != NULL) {
		while (fgets(line, sizeof(line), fp)) {

			campo1 = strtok(line, ";");
			campo2 = strtok(NULL, ";");
			campo3 = strtok(NULL, ";");
			campo4 = strtok(NULL, ";");

			strcpy(tipo, campo1);
			autonomia = atoi(campo2);
			bateria = atoi(campo3);
			id = atoi(campo4);

			inserirMeio1(&(*lista2), tipo, autonomia, bateria, id);
		}
		fclose(fp);
		printf("Dados dos meios carregados com sucesso!\n");
	}
	else {
		printf("Erro ao abrir o ficheiro.\n");
	}
}

/**
 * .		Função que adiciona Autonomia ao Meio com o ID específico
 * 
 * \param	lista2	Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Meios
 */
void adicionarAutonomia(Vehicles** lista2) {
	int id, autonomia;

	printf("Digite o ID do meio: ");
	scanf("%d", &id);
	while ((getchar()) != '\n');

	printf("Digite autonomia a ser adicionado: ");
	scanf("%d", &autonomia);
	while ((getchar()) != '\n');

	Vehicles* meio = *lista2;

	// Percorre a lista de clientes procurando pelo cliente com o NIF especificado
	while (meio != NULL) {
		if ((meio->id == id)) {
			// Atualiza o saldo do cliente
			meio->autonomia += autonomia;
			printf("Autonomia atualizada com sucesso. Autonomia atual: %d\n", meio->autonomia);
			break;
		}
		meio = meio->next;
	}

	if (meio == NULL) {
		printf("Meio nao encontrado na lista.\n");
	}
}

/**
 * .		Função que adiciona percentagem de bateria ao meio com o ID específico, com um máximo de 100%
 * 
 * \param	lista2	Apontador para a variavel que guarda o apontador para o inicio da lista ligada dos Meios
 */
void adicionarBateria(Vehicles** lista2) {
	int id, bateria;

	printf("Digite o ID do meio: ");
	scanf("%d", &id);
	while ((getchar()) != '\n');

	printf("Digite percentagem de bateria a ser adicionado: ");
	scanf("%d", &bateria);
	while ((getchar()) != '\n');

	Vehicles* meio = *lista2;

	// Percorre a lista de clientes a procura do cliente com o NIF especifico
	while (meio != NULL) {
		if ((meio->id == id)) {
			// Atualiza a bateria do meio
			meio->bateria += bateria;
			// Limita o valor da bateria ao máximo de 100
			if (meio->bateria > 100) {
				meio->bateria = 100;
			}
			printf("Autonomia atualizada com sucesso. Autonomia atual: %d\n", meio->bateria);
			break;
		}
		meio = meio->next;
	}

	if (meio == NULL) {
		printf("Meio nao encontrado na lista.\n");
	}
}

/**
 * .
 * 
 * \param lista2
 * \param aluguer
 * \param id
 */
/*void alugarMeio(Vehicles* lista2, Clients* aluguer, int id) {

	while (lista2 != NULL && lista2->id != id) {
		lista2 = lista2->next;
	}

	lista2->aluguer = aluguer;
}
*/

/**
 * .
 * 
 * \param lista2
 * \param aluguer
 * \param id
 */
/*void terminarAluguer(Vehicles* lista2, Clients* aluguer, int id) {

	while (lista2 != NULL && lista2->id != id) {
		lista2 = lista2->next;
	}

	lista2->aluguer = NULL;
}
*/

/**
 * .
 * 
 * \param lista2
 * \param i
 * \return 
 */
/*int listarMeios(Vehicles* lista2, int i) {

	if (!lista2) {
		return 0;
	}



	if (i == 0) {
	}
	printf("|    %-4d    |     %-10s     |     %-3d   |   %-4d   |\n", lista2->id, lista2->tipo, lista2->bateria, lista2->autonomia);


	listarMeios(lista2->next, ++i);
}
*/

/**
 * .
 * 
 * \param lista2
 * \param i
 * \return 
 */
/*int listarMeiosLivres(Vehicles* lista2, int i) {

	if (!lista2) {
		return 0;
	}


	if (lista2->aluguer == NULL) {
		if (i == 0) {
		}
		printf("|    %-4d  |   %-10s    |    %-3d  |  %-4d  |\n", lista2->id, lista2->tipo, lista2->bateria, lista2->autonomia);
		i++;
	}

	listarMeiosLivres(lista2->next, i);
}
*/

/**
 * .
 * 
 * \param lista2
 * \param lista
 * \param i
 * \return 
 */
/*int listarMeiosAlugados(Vehicles* lista2, Clients* lista, int i) {

	if (!lista2) {
		return i;
	}

	if (lista2->aluguer == lista) {
		if (i == 0) {
			printf("|    %-4d  |   %-10s    |    %-3d  |  %-4d  |\n", lista2->id, lista2->tipo, lista2->bateria, lista2->autonomia);
			i++;
		}

		listarMeiosAlugados(lista2->next, lista, i);
	}
}
*/

/**
 * .
 * 
 * \param lista2
 * \param id
 * \return 
 */
/*int existeMeio(Vehicles* lista2, int id) {
	if (!lista2)
		return 0;
	if (lista2->id == id)
		return 1;
	return existeMeio(lista2->next, id);
}
*/

/**
 * .
 * 
 * \param lista2
 * \param id
 * \return 
 */
/*int meioLivre(Vehicles* lista2, int id) {
	if (!lista2)
		return 0;

	if (lista2->id == id) {
		if (lista2->aluguer == NULL)
			return 1;
		else
			return 0;
	}

	return meioLivre(lista2->next, id);
}
*/

/**
 * .
 * 
 * \param lista2
 * \param id
 * \param lista
 * \return 
 */
/*int meioAlugado(Vehicles* lista2, int id, Clients* lista) {

	if (!lista2)
		return 0;

	if (lista2->id == id) {
		if (lista2->aluguer == lista)
			return 1;
		else
			return 0;
	}

	return meioAlugado(lista2->next, id, lista);
}
*/