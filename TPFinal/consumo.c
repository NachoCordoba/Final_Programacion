#include "consumo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILE_NAME "consumos.dat"

/**
    Funcion: Crea un consumo
    Descripcion: Crea la estructura de un consumo.

    @param idCliente : ID del Cliente (int)
    @param anio (char)
    @param mes (char)
    @param dia  (int)
    @param datosConsumidos  (char)

    @return consumo : Estructura con datos Nuevo Consumo (stConsumo)

**/
stConsumo createConsumo(int idCliente, int anio, int mes, int dia, int datosConsumidos){
    stConsumo consumo;
    consumo.id = 0;
    consumo.idCliente = idCliente;
    consumo.anio = anio;
    consumo.mes = mes;
    consumo.dia = dia;
    consumo.datosConsumidos = datosConsumidos;
    consumo.baja = 0;

    return consumo;
}

/**
    Funcion: Agrega un consumo a la Lista
    Descripcion: Agrega la estructura de un consumo a la lista.

    @param consumos : Lista de consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param consumo : Consumo a agregar (stConsumo)

    @return validos : Nueva cantidad de Validos (int)

**/
int addConsumo(stConsumo consumos[], int validos, stConsumo consumo){
    consumo.id = getLastIdConsumo(consumos, validos);

    if( validateNewConsumo(consumos, validos, consumo) == 1){
        consumos[validos] = consumo;
        validos = validos + 1;
        printf("\n Agregado Correctamente \n");
    }
    else
        printf("\n El Consumo existia, fueron agregados los datos Consumidos a su respectivo consumo. \n");


    return validos;
}

/**
    Funcion: Parametros de Consumo
    Descripcion: Obtiene los parametros necesarios para la creacion de un consumo.

    @return consumo : Devuelve el nuevo consumo (stConsumo)

**/
stConsumo getParamsConsumo(){
    int idCliente, anio, mes, dia, datosConsumidos;

    printf("\n ID del Cliente: ");
    scanf("%d", &idCliente);

    printf("\n Anio del Consumo: ");
    scanf("%d", &anio);

    printf("\n Mes del Consumo: ");
    scanf("%d", &mes);

    printf("\n Dia del Consumo: ");
    scanf("%d", &dia);

    printf("\n Datos Consumidos: ");
    scanf("%d", &datosConsumidos);



    return createConsumo(idCliente, anio, mes, dia, datosConsumidos);
}

/**
    Funcion: Ver Consumo
    Descripcion: Visualiza un consumo en cuestion.

    @param consumo : Consumo a ver (stConsumo)

**/
void viewConsumo(stConsumo consumo){
    printf("\n // ------- Consumo ID: %d -------// \n", consumo.id);
    printf(" - ID Cliente: %d \n", consumo.idCliente);
    printf(" - Fecha: %02d-%02d-%d \n", consumo.dia, consumo.mes, consumo.anio);
    printf(" - Datos Consumidos: %d \n", consumo.datosConsumidos);
    printf(" - Baja: %d \n", consumo.baja);
    printf("//------------------------------// \n");
}

/**
    Funcion: Ver Lista Consumos
    Descripcion: Muestra la Lista de Consumos.

    @param consumos : Lista de consumos (char[])
    @param validos : Consumos Validos de la lista(int)

**/
void viewConsumoList(stConsumo consumos[], int validos){
    printf("//------------- LISTADO DE CONSUMOS -------------// \n");
    int i = 0;

    while(i < validos){
        viewConsumo(consumos[i]);
        i++;
    }
}

/**
    Funcion: Baja Consumo
    Descripcion: Da de baja un consumo, cambiando su propiedad.

    @param consumo : Consumo a modificar (stConsumo)

    @return consumo : Consumo Modificado (stConsumo)

**/
stConsumo unsubscribeConsumo(stConsumo * consumo){

    consumo->baja = 1;
    return *consumo;
}

/**
    Funcion: Modifica un Consumo.
    Descripcion: Modifica un Consumo.

    @param consumo : Consumo a Modificar (stConsumo)
    @param intValue: Valor entero a modificar (int)
    @param field : Campo  a modificar (int) 1-- Id cliente  2-- anio 3-- mes  4-- dia 5-- datosConsumidos 6-- habilitar

    @return consumo : Consumo Modificado (stConsumo)

**/
stConsumo modifyConsumo(stConsumo * consumo, int intValue, int field){
    switch(field){
        case 1:
            consumo->idCliente = intValue;
            break;
        case 2:
            consumo->anio = intValue;
            break;
        case 3:
            consumo->mes = intValue;
            break;
        case 4:
            consumo->dia = intValue;
            break;
        case 5:
            consumo->datosConsumidos = intValue;
            break;
        case 6:
            consumo->baja = 0;
            break;
    }

    return *consumo;
}

/**
    Funcion: Busca un Consumo por ID.
    Descripcion: Busca un consumo en una lista por ID.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param id : id del consumo a buscar (int)

    @return consumo : Consumo encontrado (stConsumo)

**/
stConsumo * findConsumoById(stConsumo consumos[], int validos, int id){
    int i = 0;
    int flag = 0;

    stConsumo * consumoResponse;
    while( i < validos){
        if (consumos[i].id == id){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        consumoResponse = &consumos[i];
    }
    else{
        consumoResponse->id = -1;
    }

    return consumoResponse;
}

/**
    Funcion: Busca un Consumo por Fecha.
    Descripcion: Busca un consumo en una lista por Fecha.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param anio : anio del consumo a buscar (int)
    @param mes : mes del consumo a buscar (int)
    @param dia : dia del consumo a buscar (int)

    @return consumo : Consumo encontrado (stConsumo)

**/
stConsumo * findConsumoByFecha(stConsumo consumos[], int validos, int anio, int mes, int dia){
    int i = 0;
    int flag = 0;

    stConsumo * consumoResponse;
    while( i < validos){
        if (consumos[i].anio == anio && consumos[i].mes == mes && consumos[i].dia == dia){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        consumoResponse = &consumos[i];
    }
    else{
        consumoResponse->id = -1;
    }

    return consumoResponse;
}

/**
    Funcion: Busca un Consumo por Cliente.
    Descripcion: Busca un consumo en una lista por Cliente.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param id : id cliente del consumo a buscar (int)

    @return consumo : Consumo encontrado (stConsumo)

**/
stConsumo * findConsumoByCliente(stConsumo consumos[], int validos, int id){
    int i = 0;
    int flag = 0;

    stConsumo * consumoResponse;

    while( i < validos){
        if (consumos[i].idCliente == id){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        consumoResponse = &consumos[i];
    }
    else{
        consumoResponse->id = -1;
    }

    return consumoResponse;
}

/**
    Funcion: Guardar.
    Descripcion: Guarda la informacion de la lista de consumos en un archivo.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)


**/
void saveOnFileConsumo(stConsumo consumos[], int validos){
    int i = 0;
    FILE * file;
    file = fopen(FILE_NAME, "wb");

    while(i < validos){
            fwrite(&consumos[i], sizeof(stConsumo),1,file);
            i++;
    }
    fclose(file);
}

/**
    Funcion: Obtener Ultimo ID.
    Descripcion: Obtiene el ultimo ID de la lista de consumos.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista (int)

    @return lastId : El mayor ID encontrado (int)

**/
int loadFromFileConsumo(stConsumo consumos[]){
    int validos = 0;
    FILE * file;
    if((file = fopen(FILE_NAME, "rb"))!= NULL){
        while(!feof(file)){
            fread(&consumos[validos], sizeof(stConsumo),1, file);
            validos++;
        }
        validos--;
        fclose(file);
    }

    return validos;
}

/**
    Funcion: Obtener Ultimo ID.
    Descripcion: Obtiene el ultimo ID de la lista de consumos.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista (int)

    @return lastId : El mayor ID encontrado (int)

**/
int getLastIdConsumo(stConsumo consumo[], int validos){
    int i = 0, lastId = 0;
    while(i < validos){
        if(lastId <= consumo[i].id){
            lastId = consumo[i].id + 1;
        }
        i++;
    }
    return lastId;
}

/**
    Funcion: Validacion Nuevo.
    Descripcion: Valida el nuevo consumos.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista (int)
    @param consumo : Consumo a insertar.

    @return flag : Si paso o no la validacion (int) 1-- Paso.  0-- Se agrega al existente.

**/
int validateNewConsumo(stConsumo consumos[], int validos, stConsumo consumo){
    int flag = 1, i = 0;

    while(i < validos){
        if(consumos[i].anio == consumo.anio && consumos[i].mes == consumo.mes && consumos[i].dia == consumo.dia && consumos[i].idCliente == consumo.idCliente){
            flag = 0;
            consumos[i].datosConsumidos = consumos[i].datosConsumidos + consumo.datosConsumidos;
            break;
        }
        i++;
    }
    return flag;
}

/**
    Funcion: Genera random.
    Descripcion: Genera un Consumo Random a la lista.

    @param consumos : Lista de Consumo (char[])
    @param validos : Consumos Validos de la lista (int)
    @param id : ID del cliente (int)

    @return validos: validos nuevo tamaño (int)

**/
int addRandomConsumo(stConsumo consumos[], int validos, int id){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int r = rand() % 999;

    int year = rand() % ((tm.tm_year + 1900) - 2000 + 1) + 2000;
    int mes = rand() % (12 - 1 + 1) + 1;
    int dia = rand() % (31 - 1 + 1) + 1;

    stConsumo consumo = createConsumo(id, year , mes, dia, r);

    return addConsumo(consumos, validos, consumo);
}

