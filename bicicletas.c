#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"


void mostrarBici(eBicicleta* bici)
{
   if(bici!=NULL)
   printf("%5d     %15s     %15s     %5d\n", bici->id_bike, bici->nombre, bici->tipo, bici->tiempo);
}

void mostrarBicis(LinkedList* lista)
{
   if(lista!=NULL)
   {
        int tam = ll_len(lista);
        printf("***  Lista de bicis  ***\n\n");
        printf(" ID           NOMBRE_DUENIO             TIPO      TIEMPO \n");

        if(tam==0)
        {
            printf("No hay bicis en la lista\n\n");
        }

        else
        {
            for(int i=0; i< tam; i++)
            {
                mostrarBici(ll_get(lista, i));
            }
        }

   }

}

int bici_setId(eBicicleta* this,int id)
{
    int error = 1;
    if(this!=NULL)
    {
        error = 0;
        this->id_bike = id;
    }
    return error;
}

int bici_getId(eBicicleta* this,int* pId)
{
    int error = 1;
    if(this!=NULL && pId!= NULL)
    {
        error = 0;
        *pId = this->id_bike;
    }
    return error;
}

int bici_setNombre(eBicicleta* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && strlen(nombre) > 0 && strlen(nombre) < 30)
    {
        error = 0;
        strcpy(this->nombre, nombre);
    }
    return error;
}



int bici_getNombre(eBicicleta* this,char* pNombre)
{
    int error = 1;
    if(this!=NULL && pNombre!= NULL)
    {
        error = 0;
        strcpy(pNombre, this->nombre);
    }
    return error;
}


int bici_setTipo(eBicicleta* this,char* tipo)
{
    int error = 1;
    if(this!=NULL && strlen(tipo) > 0 && strlen(tipo) < 30)
    {
        error = 0;
        strcpy(this->tipo, tipo);
    }
    return error;
}

int bici_getTipo(eBicicleta* this,char* pTipo)
{
    int error = 1;
    if(this!=NULL && pTipo!= NULL)
    {
        error = 0;
        strcpy(pTipo, this->tipo);
    }
    return error;
}

int bici_setTiempo(eBicicleta* this,int tiempo)
{
    int error = 1;
    if(this!=NULL)
    {
        error = 0;
        this->tiempo = tiempo;
    }
    return error;
}

int bici_getTiempo(eBicicleta* this,int* pTiempo)
{
    int error = 1;
    if(this!=NULL && pTiempo!= NULL)
    {
        error = 0;
        *pTiempo = this->tiempo;
    }
    return error;
}

eBicicleta* newBiciParam(char* id, char* nombre, char* tipo, char* tiempo)
{
    eBicicleta* auxBici = (eBicicleta*) malloc(sizeof(eBicicleta));
    if(auxBici!=NULL && id != NULL && nombre != NULL && tipo != NULL && tiempo != NULL)
    {
        if(bici_setId(auxBici, atoi(id)) || bici_setNombre(auxBici, nombre) ||
           bici_setTipo(auxBici, tipo) || bici_setTiempo(auxBici, atoi(tiempo) ))
        {
            free(auxBici);
            auxBici = NULL;
        }
    }
    return auxBici;
}

void* mapTiempo(void* pElement)
{
    eBicicleta* element = (eBicicleta*) pElement;
    eBicicleta* x = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(x!=NULL)
    {
        bici_setId(x, element->id_bike );
        bici_setNombre(x, element->nombre);
        bici_setTipo(x, element->tipo);
        bici_setTiempo(x, getRandom());
    }
    return x;
}

int filtrarPlayeras(void* pElement)
{
    int auxResult = 0;
    eBicicleta* x = (eBicicleta*) pElement;
    if(x!=NULL)
    {
        if(!strcmp(x->tipo, "PLAYERA"))
            auxResult = 1;
    }
    return auxResult;
}

int filtrarBmx(void* pElement)
{
    int auxResult = 0;
    eBicicleta* x = (eBicicleta*) pElement;
    if(x!=NULL)
    {
        if(!strcmp(x->tipo, "BMX"))
            auxResult = 1;
    }
    return auxResult;
}

int filtrarPaseo(void* pElement)
{
    int auxResult = 0;
    eBicicleta* x = (eBicicleta*) pElement;
    if(x!=NULL)
    {
        if(!strcmp(x->tipo, "PASEO"))
            auxResult = 1;
    }
    return auxResult;
}

int filtrarMtb(void* pElement)
{
    int auxResult = 0;
    eBicicleta* x = (eBicicleta*) pElement;
    if(x!=NULL)
    {
        if(!strcmp(x->tipo, "MTB"))
            auxResult = 1;
    }
    return auxResult;
}

int compararTipo(void* bici1, void* bici2)
{
    int rta;
    eBicicleta* a = (eBicicleta*) bici1;
    eBicicleta* b = (eBicicleta*) bici2;

    if(strcmp(a->tipo, b->tipo)== 0)
    {
        rta = 0;
    }
    else if(strcmp(a->tipo, b->tipo)== 1)
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}

int compararTiempo(void* bici1, void* bici2)
{
    int rta;
    eBicicleta* a = (eBicicleta*) bici1;
    eBicicleta* b = (eBicicleta*) bici2;

    if(a->tiempo == b->tiempo && (strcmp(a->tipo, b->tipo)== 0) )
    {
        rta = 0;
    }
    else if(a->tiempo > b->tiempo && (strcmp(a->tipo, b->tipo)== 0))
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}
