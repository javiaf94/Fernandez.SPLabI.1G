#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "files.h"
#include "inputs.h"
#include <time.h>



int menuPrincipal();
int getRandom();


int main()
{
    srand(time(NULL));
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaTiempos = NULL;
    LinkedList* listaSort = NULL;
    LinkedList* listaFiltros = NULL;
    int flagCargaCSV = 0;
    int flagTiempos = 0;
    int flagSort = 0;
    int opcion;

    do{
        opcion = menuPrincipal();
        switch(opcion)
        {
            case 1:
            {
                char path[20];
                getString(path, "\nIngrese el nombre del archivo desde donde se cargaran los datos: ", 300);
                if(cargarBicisCSV(path, lista))
                    printf("\n\nError al cargar los datos del archivo.\n\n");
                else
                {
                    printf("\n\nDatos cargados correctamente desde el archivo.\n\n");
                    flagCargaCSV = 1;
                }

                system("pause");
                break;
            }

            case 2:
            {
                if(flagCargaCSV)
                {
                    system("cls");
                    mostrarBicis(lista);
                }
                else
                {
                    printf("\n\nDebe cargarse el archivo con la opcion 1 antes de mostrar el listado.\n\n");
                }
                system("pause");
                break;

            }

            case 3:
            {
                if(flagCargaCSV)
                {
                    listaTiempos = ll_map(lista, mapTiempo);
                    if(listaTiempos!=NULL)
                    {
                        printf("\n\nSe cargaron los tiempos correctamente. A continuacion se mostrara el listado.\n");
                        system("pause");
                        system("cls");
                        mostrarBicis(listaTiempos);
                        flagTiempos = 1;
                    }
                    else
                    {
                        printf("\n\nError al realizar la carga de tiempos.\n\n");
                    }
                }
                else
                {
                    printf("\n\nDebe cargarse el archivo con la opcion 1 antes de poder acceder a este menu.\n\n");
                }

                system("pause");
                break;
            }

            case 4:
            {
                if(flagCargaCSV)
                {
                    system("cls");
                    int tipo;
                    printf("***Tipos de bicicleta***\n\n\n");
                    printf("1. Playera.\n");
                    printf("2. BMX.\n");
                    printf("3. MBT.\n");
                    printf("4. Paseo.\n\n");
                    getInt(&tipo, "Ingrese el numero correspondiente al tipo que desea filtrar: \n", "\nError, ingrese un numero entre 1 y 4", 1, 4);
                    if(tipo==1)
                    {
                        listaFiltros =  ll_filter(lista, filtrarPlayeras);
                    }
                    else if(tipo==2)
                    {
                        listaFiltros = ll_filter(lista, filtrarBmx);
                    }
                    else if(tipo==3)
                    {
                        listaFiltros = ll_filter(lista, filtrarMtb);
                    }
                    else
                    {
                        listaFiltros = ll_filter(lista, filtrarMtb);
                    }

                    if(!guardarCSV("bicisXtipo.csv", listaFiltros))
                        printf("\n\nSe genero correctamente el archivo bicisXtipo.csv.\n\n");
                    else
                        printf("\n\nNo se pudo generar el archivo con las bicis filtradas.\n\n");
                }
                else
                {
                    printf("\n\nDebe cargarse el archivo con la opcion 1 antes de poder acceder a este menu.\n\n");
                }

                system("pause");
                break;
            }

            case 5:
            {
                if(flagTiempos && listaTiempos!=NULL)
                {
                    system("cls");
                    listaSort = ll_clone(listaTiempos);
                    if(listaSort!=NULL)
                    {
                        ll_sort(listaSort, compararTipo, 0);
                        ll_sort(listaSort, compararTiempo, 1);
                        mostrarBicis(listaSort);
                        flagSort = 1;
                    }
                    else
                        printf("\nError al generarse la lista ordenada.\n");
                }
                else
                {
                    printf("\n\nDebe cargarse el archivo con la opcion 1 y realizar el mapeo con la opcion 3 antes de poder acceder a este menu.\n\n");
                }
                system("pause");
                break;
            }

            case 6:
            {
                if(flagSort && listaTiempos!=NULL)
                {
                    if(!guardarCSV("BicisXposicion.csv", listaSort))
                    {
                        printf("\nSe guardo correctamente el archivo BicisXposicion.csv.\n\n");
                    }
                    else
                    {
                        printf("\nNo se pudo guardar correctamente el archivo BicisXposicion.csv.\n\n");
                    }
                }
                else
                {
                    printf("\n\nDebe cargarse el archivo con la opcion 1 y realizar el ordenamiento con la opcion 5 antes de poder acceder a este menu.\n\n");
                }

                system("pause");
                break;
            }

            case 7:
            {
                break;
            }

            default:
            {
                printf("\n\nIngrese un numero de opcion valido.\n\n");
                system("pause");
            }

        }
    }while(opcion!=7);

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaTiempos);
    ll_deleteLinkedList(listaSort);
    ll_deleteLinkedList(listaFiltros);

    return 0;
}


int menuPrincipal()
{
     int auxInt;
     system("cls");
     printf("*****  MENU PRINCIPAL   *****\n\n");
     printf("1.  Cargar los datos de las bicicletas desde archivo csv.\n\n");
     printf("2.  Listar Bicicletas.\n\n");
     printf("3.  Asignar tiempos e imprimirlos por pantalla .\n\n");
     printf("4.  Filtrar bicicletas por tipo .\n\n");
     printf("5.  Ordenar bicis por tipo y posicion\n\n");
     printf("6.  Guardar lista de bicis ordenadas por posicion en archivo csv.\n\n");
     printf("7. Salir.\n\n");
     printf("Ingrese el numero de opcion a la que quiere acceder: ");
     fflush(stdin);
     scanf("%d", &auxInt);
     return auxInt;
}

int getRandom()
{

	int aleatorio;

	aleatorio = rand() % (71)+50
	;

	return aleatorio;
}
