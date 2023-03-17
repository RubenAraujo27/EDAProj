#ifndef GESTORES	//Guarda de ficheiros
#define GESTORES	//Guarda de ficheiros

#include "helper.h"

typedef struct managerslist {		//Declaração da estrutura gestores
	char nome[MAX_NOME];			//Nome do Gestor
	char password[MAX_PASSWORD];	//Palavra-passe do Gestor
	char NIF[MAX_NIF];				//NIF do Gestor
	struct managerslist* next;		//next Nó (node)
}Managers;

//Le os dados fornecidos para registo dos gestores
void inserirGestor(Managers** lista1);

//Regista os dados dos gestores
void inserirGestores1(Managers** lista1, char NIF[], char nome[], char password[]);

//Remover um gestor através do seu NIF
void removerGestor(Managers** lista1, char nome[]);

//Grava os dados dos clientes em um ficheiro de texto
void gravarTextoManagers(Managers* lista1);

//Carrega para a memoria os dados dos clientes guardados no ficheiro de texto
void readManagers(Managers** lista1);

#endif	//Final da guarda de ficheiros
