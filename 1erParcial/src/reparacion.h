#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;//comienza en 20000
	char descripcion[26];
	float precio;
}eServicio;

typedef struct{
	int id;//autoincremental
	int serie;//validar
	int idServicio;//validar
	eFecha fecha;//validar dia mes y anio
	int isEmpty;
}eReparacion;

#endif /* REPARACION_H_ */

int pedirFecha(int* anio, int* mes, int* dia);
void mostrarServicios(eServicio* list, int len);
void mostrarServicio(eServicio servicio);
/*
void mostrarReparacion(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ);
int searchFreeRepar(eReparacion* list, int len);
int cargadoReparaciones(eReparacion* list, int len);
int buscarServicioId(eServicio* list, int len, int id);
int altaReparacion(eReparacion* list, int len, eServicio* listServ, int lenServ, int id, eElectrodomestico* listElectrodomestico, int lenElectrodomestico, eMarca* listMarca, int lenMarca);
void mostrarReparacion(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ);
*/
