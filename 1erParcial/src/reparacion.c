#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdio.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "utnInputs.h"

int pedirFecha(int* anio, int* mes, int* dia)
{
	int retorno=-1;
	int dia_maximo;

	if(anio != NULL && mes != NULL && dia != NULL)
	{
		retorno = utn_getNumber(mes, "\nIngrese el mes(numerico): ", "\nError (Rango entre 1-12)", 1, 12, 3);

		if ( *mes >= 1 && *mes <= 12 && retorno == 0)
		{
			retorno =-1;
			switch ( *mes )
			{
			case  1 :
			case  3 :
			case  5 :
			case  7 :
			case  8 :
			case 10 :
			case 12 :
				dia_maximo = 31;
				retorno = utn_getNumber(dia, "\nIngrese el dia: ", "\nError (Rango entre 1-31)", 1, dia_maximo, 3);
				break;

			case  4 :
			case  6 :
			case  9 :
			case 11 :
				dia_maximo = 30;
				retorno = utn_getNumber(dia, "\nIngrese el dia: ", "\nError (Rango entre 1-30)", 1, dia_maximo, 3);
				break;

			case  2 :
				if( (*anio % 4 == 0 && *anio % 100 != 0) || *anio % 400 == 0)
				{
					dia_maximo=29;
					retorno = utn_getNumber(dia, "\nIngrese el dia: ", "\nError (Rango entre 1-29)", 1, dia_maximo, 3);
				}else
				{
					dia_maximo=28;
					retorno = utn_getNumber(dia, "\nIngrese el dia: ", "\nError (Rango entre 1-28)", 1, dia_maximo, 3);
				}
				break;
			}

			if(retorno == 0)
			{
				retorno = utn_getNumber(anio, "\nIngrese el anio: ", "\nError (Rango entre 2000 - 2020)", 2000, 2020, 3);
			}
		}
	}

	return retorno;

}

void mostrarServicios(eServicio* list, int len)
{
	if(list != NULL)
	{
		printf("\n**Listado de servicios**");
		printf("\n   Id               Descripcion     Precio");

		for(int i=0; i<len; i++)
		{
			mostrarServicio(list[i]);
		}
	}
}

void mostrarServicio(eServicio servicio)
{
	printf("\n%5d %25s %10.3f",servicio.id, servicio.descripcion, servicio.precio);
}

int searchFreeRepar(eReparacion* list, int len)
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


int cargadoReparaciones(eReparacion* list, int len)
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

int buscarServicioId(eServicio* list, int len, int id)
{
	int indice=-1;
		if(list != NULL)
		{
			for(int i=0;i<len;i++)
			{
				if (list[i].id==id)
				{
					indice=i;
				}
			}
		}
		return indice;
}
/*

int altaReparacion(eReparacion* list, int len, eServicio* listServ, int lenServ, int id, eElectrodomestico* listElectrodomestico, int lenElectrodomestico, eMarca* listMarca, int lenMarca)
{

	int todoOk=-1;
	int indice;
	int idElectrodomestico;
	int indiceElectrodomestico;
	int idServicio;
	int indiceServicio;
	int anio;
	int mes;
	int dia;


	if((indice = searchFreeRepar(list, len))!=-1)
	{
		system("clear");
		printf("\n***Alta de reparacion***\n");

		mostrarElectrodomesticos(list, len, listMarca, lenMarca);

		printf("\n\nIngrese el Id del electrodomestico a cargar: ");
		__fpurge(stdin);
		scanf("%d",&idElectrodomestico);
		indiceElectrodomestico = buscarElectrodomesticoId(list, len, idElectrodomestico);
		if(indiceElectrodomestico == -1)
		{
			printf("\nNo existe electrodomestico con numero de Id ingresado");
		}
		else
		{
			mostrarServicios(listServ, lenServ);
			printf("\n\nIngrese el Id del servicio a cargar: ");
			__fpurge(stdin);
			scanf("%d",&idServicio);
			indiceServicio = buscarServicioId(listServ, lenServ, idServicio);
			if(indiceServicio == -1)
			{
				printf("\nNo existe servicio con numero de Id ingresado");
			}
			else
			{
				todoOk=  pedirFecha(&anio, &mes, &dia);
				if(todoOk==-1)
				{
					printf("\nERROR al dar de alta una reparacion");
				}
				else
				{
					list[indice].fecha.dia=dia;
					list[indice].fecha.anio=anio;
					list[indice].fecha.mes=mes;
					list[indice].idServicio=idServicio;
					list[indice].serie=listElectrodomestico[idElectrodomestico].serie;
					todoOk=0;
				}
			}
		}
	}
return todoOk;
}

void mostrarReparacion(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ)
{
	int idServicio;
	if(list != NULL)
	{
		printf("\n**Listado de reparaciones**");
		printf("\n  Id          Descripcion");

		for(int i=0; i<len; i++)
		{
			idServicio = buscarServicioId(listServ, lenServ, list[i].idServicio);
			if(list[i].isEmpty==0)
			{
				printf("\n%4d       %d04     %s      %02d/%02d/%02d",list[i].id, listServ[idServicio].descripcion, list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
			}
		}
	}
}*/
