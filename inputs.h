#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief Genera un bucle donde se recibe un entero por teclado, se repite hasta que el mismo se encuentre en el rango especificado
           Hecho esto, actualiza el entero en la variable indicada por parametro.
 *
 * \param pResult int* Puntero a la direccion de memoria de la variable donde se actualizará el entero.
 * \param msg[100] char Mensaje mediante el cual se solicitará la entrada por teclado.
 * \param errorMsg[100] char Mensaje de error en caso de que el entero ingresado no se encuentre en el rango especificado.
 * \param mini int Valor minimo que puede tomar el entero ingresado.
 * \param maxi int Valor maximo que peude tomar el entero ingresado.
 * \return void
 *
 */
void getInt(int* pResult , char msg[100], char errorMsg[100], int mini, int maxi);

void getIntMin(int* pResult , char msg[100], char errorMsg[100], int mini);


/** \brief Solicita al usuario que ingrese un caracter, genera un bucle del cual se sale una vez que el caracter ingresado sea 's' o 'n'
 *
 * \param msg[100] char Mensaje mostrado para solicitar el ingreso por teclado.
 * \param errorMsg[100] char Mensaje de error, mostrado en caso de que el caracter ingresado no sea 's' ni 'n'
 * \return int Retorna 1 si se ingreso 's' y 0 y se ingreso 'n'.
 *
 */
int getYesOrNo(char msg[100], char errorMsg[100]);



/** \brief Recibe una cadena de caracteres por teclado, hasta que la misma sea menor al tamaño maximo indicado.
           Hecho esto, copia la cadena ingresada en la variable indicada por parametro
 *
 * \param name[] char Variable donde se almacenara la cadena ingresada.
 * \param msg[] char  Mensaje mostrado por pantalla para solicitar el ingreso por teclado.
 * \param maxLen int  Largo maximo de la cadena a ingresar.
 * \return void
 *
 */
void getString(char name[], char msg[], int maxLen);
