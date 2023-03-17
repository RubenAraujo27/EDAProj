#ifndef CLIENTES	//Guarda de ficheiros
#define CLIENTES	//Guarda de ficheiros

#include "helper.h"

typedef struct clientslist {		//Declaração da estrutura de Clientes
	char NIF[MAX_NIF];				//NIF do Cliente
	char nome[MAX_NOME];			//Nome do Cliente
	char morada[MAX_MORADA];		//Morada do Cliente
	char password[MAX_PASSWORD];	//Palavra-passe do Cliente
	int idade;						//Idade do Cliente
	float saldo;					//Saldo do Cliente
	struct clientslist* next;		//next Nó (node)
}Clients;

//Le os dados fornecidos para registo dos clientes
void inserirCliente(Clients**);

//Regista os dados dos clientes
void inserirCliente1(Clients** lista, char NIF[], char nome[], char morada[], char senha[], int idade, float saldo);

//Remover um cliente através do seu NIF
void removerCliente(Clients** lista, char NIF[]);

//Grava os dados dos clientes em um ficheiro de texto
void gravarTextoClientes(Clients* lista);

//Carrega para a memoria os dados dos clientes guardados no ficheiro de texto
void readClientes(Clients** lista);

//Adicionar saldo a um cliente atraves do seu NIF
void adicionarSaldoCliente(Clients** lista);

#endif	//Final da guarda de ficheiros
