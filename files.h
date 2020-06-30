#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
#include "LinkedList.h"

/** \brief Carga los datos desde el archivo CSV y los guarda en una estructura LinkedList
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int retorna 1 Si hubo error 0 si se cargó correctamente
 *
 */
int cargarBicisCSV(char* path, LinkedList* lista);


/** \brief Carga los datos desde la estructura Linked List y los guarda en un archivo CSV
 * \param path char*
 * \param lista LinkedList*
 * \return int retorna 1 Si hubo error 0 si se cargó correctamente
 *
 */
int guardarCSV(char* path, LinkedList* lista);


#endif // FILES_H_INCLUDED
