#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_



#endif /* UTNINPUTS_H_ */

/** \brief Pide un numero al usuario y recibe como parametro un mensaje, un mensaje de error,
 * 		   un minimo, un maximo y la cantidad de reintentos para el ingreso del numero
 * 		   realizando la validaciones necesarias por medio de funciones
 *
 * @param pResultado int*
 * @param mensaje char*
 * @param mensajeError char*
 * @param minimo int
 * @param maximo int
 * @param reintentos int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Pide un numero flotante al usuario y recibe como parametro un mensaje, un mensaje de error,
 * 		   un minimo, un maximo y la cantidad de reintentos para el ingreso del numero flotante
 * 		   realizando la validaciones necesarias por medio de funciones
 *
 * @param pFlotante float*
 * @param mensaje char*
 * @param mensajeError char*
 * @param minimo int
 * @param maximo int
 * @param intentos int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int utn_getFloat(float* pFlotante, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);


/** \brief Pide un string al usuario y recibe como parametro un mensaje, un mensaje de error,
 * 		   un minimo, un maximo y la cantidad de reintentos para el ingreso del string
 * 		   realizando la validaciones necesarias por medio de funciones
 *
 * @param pPalabra char*
 * @param mensaje char*
 * @param mensajeError char*
 * @param len char*
 * @param reintentos int
 * @return Retorna -1 ERROR, 0 EXITO
 */
int utn_getString(char* pPalabra, char* mensaje, char* mensajeError, int len, int reintentos);


/** \brief Llama a myGets y valida que el ingreso sea un numero, de serlo lo copia a
 * 		   un puntero a int, int*, que lo recibe como parametro
 *
 * @param pResultado int*, Puntero a int
 * @return Retorna -1 ERROR, 0 EXITO
 */
int getInt(int* pResultado);


/** \brief Llama a myGets y valida que el ingreso sea un numero flotante, de serlo lo copia a
 * 		   un puntero a float, float*, que lo recibe como parametro
 *
 * @param pResultado float*, Puntero a float
 * @return Retorna -1 ERROR, 0 EXITO
 */
int getFloat(float* pResultado);


/** \brief Llama a myGets y valida que el ingreso sea una cadena de caracteres, de serlo lo copia a
 *         un puntero de char, char*, que lo recibe como parametro
 *
 * @param pResultado char* Puntero a char
 * @return Retorna -1 ERROR, 0 EXITO
 */
int getString(char* pResultado);


/**\brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en string un maximo
 *        de 'len - 1' caracteres
 *
 * @param string Puntero al espacio de memoria donde se copiara la cadena obtenida
 * @param len Longitud define el tamaño de la cadena
 * @return Retorna 0 EXITO, -1 ERROR
 */
int myGets(char* string, int len);


/**\brief verifica si la cadena ingresada es numerica
 *
 * @param string char*, String a ser analizado
 * @param len int, Longitud de la cadena
 * @return int Retorna 0 EXITO, -1 ERROR
 */
int isNumber(char* string, int len);


/** \brief verifica si la cadena ingresada es flotante
 *
 * @param string char*, string a ser analizado
 * @param len int, Longitud de la cadena
 * @return int Retonra -1 ERROR, 0 EXITO
 */
int isFloatNumber(char* string, int len);


/** \brief verificada si la cadena ingresada de tipo char
 *
 * @param string char*, string a ser analizado
 * @param len int, longitud de la cadena
 * @return int Retonra -1 ERROR, 0 EXITO
 */
int isWord(char* string, int len);

/**
 *
 * @return
 */
int menu();
