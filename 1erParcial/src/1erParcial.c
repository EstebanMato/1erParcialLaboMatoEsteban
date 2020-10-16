#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "reparacion.h"
#include "electrodomestico.h"
#define TAMMARCAS 5
#define TAMELEC 20
#define TAMSERV 4
#define TAMREPAR 100


int main(void) {
	setbuf(stdout, NULL);

	int todoOk;
	int todoOkRepar;
	int idElectrodomestico=1;
	int idReparacion = 0;
	char salir ='n';

	eMarca arrayMarcas[TAMMARCAS]= {{1000,"Whirpool"},
							   {1001,"Sony"},
							   {1002,"Liliana"},
							   {1003,"Gafa"},
							   {1004,"Philips"},
	};


	eServicio arrayServicios [TAMSERV] = {{20000,"Garantia",250},
									 {20001,"Mantenimiento",500},
									 {20002,"Repuesto",400},
									 {20003,"Refaccion",600},
	};


	/*eElectrodomestico arrayElectrodomesticos [TAMELEC] = {{1,1234,1000,2000},
														 {2,5487,1002,1993},
														 {3,1235,1006,2001},
														 {4,8484,1000,2001},
														 {5,1001,1009,2019},
														 {6,3265,1005,2020},
														 {7,1313,1008,2018},
														 {8,1111,1008,2002}
	};*/


	/*
		todoOk = pedirFecha(&anio, &mes, &dia);
		if(todoOk==0)
		{
			printf("\nLa fecha ingresada fue dia %d mes %d anio %d",dia,mes,anio);
		}

		mostrarServicios(arrayServicios, TAMSERV);
		mostrarMarcas(arrayMarcas, TAMMARCAS);
		*/

	eElectrodomestico arrayElectrodomesticos [TAMELEC];
	eReparacion arrayReparaciones [TAMREPAR];
	todoOk = initReparaciones(arrayReparaciones, TAMREPAR);

	todoOkRepar = initElectrodomesticos(arrayElectrodomesticos, TAMELEC);


	if(todoOk==0)
		{

			do{
				switch(menu()){
					case 1:
						if(altaElectrodomestico(arrayElectrodomesticos, TAMELEC, idElectrodomestico, arrayMarcas, TAMMARCAS)==0){
							idElectrodomestico++;
							printf("\nElectrodomestico dado de alta correctamente!");

						}else{
							printf("\nError! (no fue dado de alta ningun electrodomestico)");
						}
						break;

					case 2:
						if(cargadoElectrodomectico(arrayElectrodomesticos, TAMELEC)){
							modifyElectrodomestico(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
						}else{
							printf("\nError! (no fue dado de alta ningun electrodomestico)");
						}
						break;

					case 3:
						if(cargadoElectrodomectico(arrayElectrodomesticos, TAMELEC)){
							lowElectrodomestico(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
						}else{
							printf("\nError! (no fue dado de alta ningun electrodomestico)");
						}
						break;

					case 4:
						if(cargadoElectrodomectico(arrayElectrodomesticos, TAMELEC)){
							mostrarElectrodomesticos(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
						}else{
							printf("\nSe debe cargar primero algun electrodomestico");
						}

						break;

					case 5:
						mostrarMarcas(arrayMarcas, TAMMARCAS);
						break;

					case 6:
						mostrarServicios(arrayServicios, TAMSERV);
						break;

					case 7:/*
						altaReparacion(arrayReparaciones, TAMREPAR, arrayServicios, TAMSERV, idReparacion, arrayElectrodomesticos, TAMELEC,  arrayMarcas, TAMMARCAS);
						*/break;

					case 8:
						/*if(cargadoReparaciones(arrayReparaciones, TAMREPAR)){
							mostrarReparacion(arrayReparaciones, TAMREPAR, arrayReparaciones, TAMREPAR, arrayServicios, TAMSERV);
						}else{
							printf("\nError! (no fue dado de alta ninguna reparacion)");
						}*/
						break;

					case 9:
						printf("\nConfirma que desea salir del sistema? (s/n): ");
						__fpurge(stdin);
						scanf("%c", &salir);
						break;

					default:
						printf("\nOPCION INVALIDA");
				}

				__fpurge(stdin);
				getchar();
			}while(salir!='s');
		}else
		{
			system("clear");
			printf("\nERROR AL INICIAR EL ARRAY\n\n");
			getchar();
		}



	getchar();
	return EXIT_SUCCESS;
}


