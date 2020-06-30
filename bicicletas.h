#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[30];
    int tiempo;
    char tipo[30];
} eBicicleta;

void mostrarBici(eBicicleta* bici);
void mostrarBicis(LinkedList* lista);

void* mapTiempo(void* pElement);

int filtrarPlayeras(void* pElement);
int filtrarBmx(void* pElement);
int filtrarPaseo(void* pElement);
int filtrarMtb(void* pElement);

int bici_setId(eBicicleta* this,int id);
int bici_getId(eBicicleta* this,int* pId);
int bici_setNombre(eBicicleta* this,char* nombre);
int bici_getNombre(eBicicleta* this,char* pNombre);
int bici_setTipo(eBicicleta* this,char* tipo);
int bici_getTipo(eBicicleta* this,char* pTipo);
int bici_setTiempo(eBicicleta* this,int tiempo);
int bici_getTiempo(eBicicleta* this,int* pTiempo);
eBicicleta* newBiciParam(char* id, char* nombre, char* tipo, char* tiempo);

int compararTipo(void* bici1, void* bici2);
int compararTiempo(void* bici1, void* bici2);

#endif // BICICLETAS_H_INCLUDED


