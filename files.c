#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#include "LinkedList.h"
#include "bicicletas.h"



int cargarBicisCSV(char* path, LinkedList* lista)
{
    int auxReturn = 1;
    if(path!= NULL && lista != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f != NULL)
        {
            char buffer[4][128];
            eBicicleta* auxBici;
            int cant;

            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
            while(!feof(f))
            {
                cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
                if(cant==4)
                {
                    auxBici = newBiciParam(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(lista,auxBici);
                    auxReturn = 0;
                }

            }
        }
    }
    return auxReturn;
}


int guardarCSV(char* path, LinkedList* lista)
{
    int auxReturn = 1;
    if(path!= NULL && lista != NULL)
    {
        FILE* f = fopen(path, "w");
        if(f != NULL)
        {
            eBicicleta* auxBici;
            int len = ll_len(lista);
            fprintf(f, "id_bike,nombre,tipo,tiempo\n");

            for(int i= 0; i<len; i++)
            {
                auxBici = (eBicicleta*) ll_get(lista, i);
                fprintf(f, "%d,%s,%s,%d\n", auxBici->id_bike, auxBici->nombre, auxBici->tipo, auxBici->tiempo);
            }
            auxReturn = 0;
            free(auxBici);
            fclose(f);

        }
    }
    return auxReturn;
}

