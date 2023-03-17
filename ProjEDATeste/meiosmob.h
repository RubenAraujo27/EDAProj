#ifndef MEIOS	//Guarda de ficheiros
#define MEIOS	//Guarda de ficheiros

#include "helper.h"		
#include "clientes.h"

typedef struct vehicleslist {	//Declaração da estrutura dos Meios de mobilidade
	char tipo[MAX_TIPO];		//Tipo de meio de mobilidade
	int autonomia;				//Autonomia do meio de mobilidade
	int bateria;				//Bateria do meio de mobilidade
	int id;						//ID do meio de mobilidade
	//Clients* aluguer;			
	struct vehicleslist* next;	//next Nó (node)
}Vehicles;

//Le os dados fornecidos para registo de meios
void inserirMeio(Vehicles** lista2);

//Regista os dados dos meios
void inserirMeio1(Vehicles** lista2, char tipo[], int autonomia, int bateria, int id);

//Remover um meio através do seu ID
void removerMeio(Vehicles** lista2, int id);

//Grava os dados dos meios em um ficheiro de texto
void gravarTextoMeio(Vehicles* lista2);

//Carrega para a memoria os dados dos meios guardados no ficheiro de texto
void readMeios(Vehicles** lista2);

//Adiciona autonomia a um meio
void adicionarAutonomia(Vehicles** lista2);

//Adiciona bateria a um meio num maximo de 100
void adicionarBateria(Vehicles** lista2);

//void alugarMeio(Vehicles* lista2, Clients* aluguer, int id);

//void terminarAluguer(Vehicles* lista2, Clients* aluguer, int id);

//int listarMeios(Vehicles* lista2, int i);

//int listarMeiosLivres(Vehicles* lista2, int i);

//int listarMeiosAlugados(Vehicles* lista2, Clients* lista, int i);

//int existeMeio(Vehicles* lista2, int id);

//int meioLivre(Vehicles* lista2, int id);

//int meioAlugado(Vehicles* lista2, int id, Clients* lista);

#endif	//Final da guarda de ficheiros
