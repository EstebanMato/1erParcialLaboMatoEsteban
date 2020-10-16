#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

typedef struct{
	int id;//comienza en 1000
	char descripcion[21];
}eMarca;

typedef struct{
	int id;
	int serie;
	int idMarca; //validar
 	int modelo; //año de fabricacion
 	int isEmpty;
}eElectrodomestico;

#endif /* ELECTRODOMESTICO_H_ */

void mostrarMarcas(eMarca* list, int len);
void mostrarMarca(eMarca marca);
int altaElectrodomestico(eElectrodomestico* listElectro, int lenElec, int id, eMarca* listMarcas, int lenMarca);
void mostrarElectrodomesticos(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);
void mostrarElectrodomestico(eElectrodomestico electrodomestico, eMarca* listMarca, int lenMarca);
int initElectrodomesticos(eElectrodomestico* list, int len);
int searchMarca(eMarca* list, int len, int id);
int buscarElectrodomesticoId(eElectrodomestico* list, int len, int id);
int cargadoElectrodomectico(eElectrodomestico* list, int len);
void modifyElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);
int removeElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca, int idElectrodomestico);
int lowElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);
