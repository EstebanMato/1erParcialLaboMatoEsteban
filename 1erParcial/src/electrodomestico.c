#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnInputs.h"
#include "electrodomestico.h"
#include "reparacion.h"

int cargadoElectrodomectico(eElectrodomestico* list, int len)
{
	int loaded=0;

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			loaded=1;
			break;
		}
	}
	return loaded;
}

int addElectrodomestico(eElectrodomestico* list, int id, int indice, int serie, int idMarca, int modelo)
{
	int retorno =-1;

	if(list != NULL)
	{
		list[indice].id=id;
		list[indice].idMarca=idMarca;
		list[indice].modelo=modelo;
		list[indice].serie=serie;
		list[indice].isEmpty=0;
		retorno=0;
	}
	return retorno;
}

int searchFree(eElectrodomestico* list, int len)
{
	int retorno = -1;

	if(list != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}

int searchMarca(eMarca* list, int len, int id)
{
	int retorno = -1;
	if (list != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id==id)
			{
				retorno=i;
				break;
			}

		}
	}
	return retorno;
}

void mostrarMarcas(eMarca* list, int len)
{
	if(list != NULL)
	{
		printf("\n**Listado de marcas**");
		printf("\n  Id          Descripcion");

		for(int i=0; i<len; i++)
		{
			mostrarMarca(list[i]);
		}
	}
}

void mostrarMarca(eMarca marca)
{
	printf("\n%4d %20s",marca.id, marca.descripcion);
}

void mostrarElectrodomesticos(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	int flagSwap;
	int i;

	eElectrodomestico auxElectrodomestico;

	if(list != NULL && len >0)
	{
		do
		{
			flagSwap=0;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}

				if(list[i].modelo > list[i+1].modelo)
				{
					flagSwap = 1;
					auxElectrodomestico=list[i];
					list[i]=list[i+1];
					list[i+1]=auxElectrodomestico;
				}
				else
				{
					if(list[i].modelo == list[i+1].modelo)
					{
						if(list[i].serie > list[i+1].serie)
						{
							flagSwap = 1;
							auxElectrodomestico=list[i];
							list[i]=list[i+1];
							list[i+1]=auxElectrodomestico;
						}
					}
				}
			}
			len--;
		}while(flagSwap);
	}

	if(list != NULL)
	{
		printf("\n**Listado de electrodomesticos**");
		printf("\n  Id   NumSerie   Marca    Modelo(anio)");

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				mostrarElectrodomestico(list[i],listMarca, lenMarca);
			}

		}
	}
}

void mostrarElectrodomestico(eElectrodomestico electrodomestico, eMarca* listMarca, int lenMarca)
{
	int indiceMarca;

	for(int i=0; i<lenMarca; i++)
	{
		if(searchMarca(listMarca, lenMarca, electrodomestico.idMarca))
		{
			indiceMarca=i;
			break;
		}
	}

	printf("\n%4d       %d04     %s      %4d",electrodomestico.id, electrodomestico.serie, listMarca[indiceMarca].descripcion, electrodomestico.modelo);
}

int initElectrodomesticos(eElectrodomestico* list, int len)
{
	int retorno =-1;
	if(list != NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int initReparaciones(eReparacion* list, int len)
{
	int retorno =-1;
		if(list != NULL && len>0)
		{
			for (int i=0; i<len; i++)
			{
				list[i].isEmpty=1;
			}
			retorno=0;
		}
		return retorno;
}

int altaElectrodomestico(eElectrodomestico* listElectro, int lenElec, int id, eMarca* listMarcas, int lenMarca)
{
	int todoOk=-1;
	int indice;
	int serie;
	int idMarca;
	int modelo;


	if((indice = searchFree(listElectro, lenElec))!=-1)
	{
		system("clear");
		printf("\n***Alta de electrodomestico***\n");

		todoOk=utn_getNumber(&serie, "\nIngrese el numero de serie (Rango entre 0001-9999): ", "\nERROR (Rango entre 0001-9999)", 1, 9999, 3);
		if(todoOk==0)
		{
			int reintentos = 3;

			do
			{

				mostrarMarcas(listMarcas, lenMarca);
				printf("\n\nIngrese el numero de ID de marca: ");
				scanf("%d", &idMarca);
				todoOk=searchMarca(listMarcas, lenMarca, idMarca);
				if(todoOk!=-1)
				{
					todoOk=0;
					break;
				}
				else
				{
					printf("\n\nERROR. Numero de marca no encontrado");
					reintentos--;
				}
			}while(reintentos>0);

			if(todoOk==0)
			{
				todoOk=utn_getNumber(&modelo, "\nIngrese el modelo del electrodomestico(1980-2020): ", "\nERROR (Rango entre 1980 - 2020", 1980, 2020, 3);
			}
		}

		if(todoOk==0)
		{
			todoOk=addElectrodomestico(listElectro,id, indice,serie,idMarca,modelo);
		}
	}
	else
	{
		printf("\nSistema de empleados completo\n");
	}


	return todoOk;
}

int buscarElectrodomesticoId(eElectrodomestico* list, int len, int id)
{
	int indice=-1;
	if(list != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].id==id && list[i].isEmpty==0)
			{
				indice=i;
			}
		}
	}
	return indice;
}

void modifyElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	int idElectrodomestico;
	int indiceElectrodomestico;
	int option;
	int todoOk=-1;
	int serie;
	int modelo;
	char change = 'n';
	char salir='n';

	system("clear");
	printf("***Modificar electrodomestico***");
	mostrarElectrodomesticos(list, len, listMarca, lenMarca);

	printf("\n\nIngrese el Id del electrodomestico a modificar: ");
	__fpurge(stdin);
	scanf("%d",&idElectrodomestico);
	indiceElectrodomestico = buscarElectrodomesticoId(list, len, idElectrodomestico);
	if(indiceElectrodomestico == -1)
	{
		printf("\nNo existe electrodomectico con numero de Id ingresado");
	}else
	{
		do{
			todoOk=-1;
			change='n';
			system("clear");
			printf("\n***Modificar electrodomestico***\n");
			printf("\n  Id   NumSerie   Marca    Modelo(anio)");
			mostrarElectrodomestico(list[indiceElectrodomestico], listMarca, lenMarca);
			printf("\n\nQue desea modificar?");
			printf("\n1-Serie");
			printf("\n2-Modelo");
			printf("\n\n3-Salir");
			printf("\nIngrese opcion: ");
			scanf("%d",&option);

			switch(option)
			{

			case 1:
				todoOk=utn_getNumber(&serie, "\nIngrese el numero de serie (Rango entre 0001-9999): ", "\nERROR (Rango entre 0001-9999)", 1, 9999, 3);
				if(todoOk==0)
				{
					printf("\nEl nuevo numero de serie es '%d', desea continuar y efectuar el cambio? (s/n): ",serie);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						list[indiceElectrodomestico].serie=serie;
						printf("\nSe realizo el cambio corectamente!");
					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 2:
				todoOk=utn_getNumber(&modelo, "\nIngrese el modelo del electrodomestico(1980-2020): ", "\nERROR (Rango entre 1980 - 2020)", 1980, 2020, 3);
				if(todoOk==0)
				{
					printf("\nEl nuevo numero de modelo es '%d', desea continuar y efectuar el cambio? (s/n): ",modelo);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						list[indiceElectrodomestico].modelo=modelo;
						printf("\nSe realizo el cambio corectamente!");
					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;
			case 3:
				printf("\nConfirma que desea salir del sistema? (s/n): ");
				__fpurge(stdin);
				scanf("%c", &salir);
				break;
			default:
				printf("\nOpcion invalida");
			}

			__fpurge(stdin);
			getchar();
		}while(salir!='s');
	}
}

int lowElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	int retorno=-1;
	int idElectrodomestico;

	system("clear");
	printf("\n***Baja de electrodomestico***\n");
	mostrarElectrodomesticos(list, len, listMarca, lenMarca);
	printf("\n\nIngrese el Id del electrodomestico a dar de baja: ");
	__fpurge(stdin);
	scanf("%d",&idElectrodomestico);

	if(!(removeElectrodomestico(list, len, listMarca, lenMarca, idElectrodomestico)))
	{
		printf("\nBaja exitosa!! ");
	}
	else
	{
		printf("\nERROR en la baja!! ");
	}


	return retorno;
}


int removeElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca, int idElectrodomestico)
{
	int retorno=-1;
	int indiceElectrodomestico;
	char borrar;

	indiceElectrodomestico = buscarElectrodomesticoId(list, len, idElectrodomestico);

	if(indiceElectrodomestico==-1)
	{
		printf("\nNo existe el empleado con numero de Id ingresado");
	}
	else
	{
		printf("\n  Id   NumSerie   Marca    Modelo(anio)");
		mostrarElectrodomestico(list[indiceElectrodomestico], listMarca, lenMarca);
		printf("\n\nConfirma la baja del electrodomestico(s/n): ");
		__fpurge(stdin);
		scanf("%c",&borrar);

		if(borrar=='s')
		{
			list[indiceElectrodomestico].isEmpty=1;
			retorno=0;
		}
		else
		{
			printf("\nLa operacion se ha cancelado ");
		}
	}

	return retorno;
}

