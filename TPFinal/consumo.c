#include "consumo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILE_NAME "consumos.dat"

/**
    Crea un Consumo
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
    Agrega un Consumo a la Lista
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
    Obtiene parametros para agregar un Consumo
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
    Visualiza un Consumo
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
    Visualiza una lista de Consumos
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
    Dar de Baja Consumo
**/
stConsumo unsubscribeConsumo(stConsumo * consumo){

    consumo->baja = 1;
    return *consumo;
}

/**
    Modifica un Consumo
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
    Buscar Consumo
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

