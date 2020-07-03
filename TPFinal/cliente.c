#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 30
#define FILE_NAME "clientes.dat"

/**
    Crea un Cliente
**/
stCliente createCliente(int nroCliente, char nombre[MAX_SIZE], char apellido[MAX_SIZE], int dni, char email[MAX_SIZE], char domicilio[MAX_SIZE], int movil){
    stCliente cliente;
    cliente.id = 0;
    cliente.nroCliente = nroCliente;
    strcpy(cliente.nombre, nombre);
    strcpy(cliente.apellido, apellido);
    cliente.dni = dni;
    strcpy(cliente.email, email);
    strcpy(cliente.domicilio, domicilio);
    cliente.movil = movil;
    cliente.baja = 0;

    return cliente;
}

/**
    Agrega un Cliente a la Lista
**/
int addCliente(stCliente clientes[], int validos, stCliente cliente){
    cliente.id = getLastId(clientes, validos);

    if( validateNewClient(clientes, validos, cliente) == 1){
        clientes[validos] = cliente;
        validos = validos + 1;
        printf("\n Agregado Correctamente \n");
    }
    else
        printf("\n No se agrego correctamente el cliente: Existe coincidencia en DNI o Numero Cliente \n");


    return validos;
}

/**
    Obtiene parametros para agregar un Cliente
**/
stCliente getParamsCliente(){
    int nroCliente, dni, movil;
    char nombre[MAX_SIZE], apellido[MAX_SIZE], email[MAX_SIZE], domicilio[30];
    char temp;

    printf("\n Numero Cliente: ");
    scanf("%d", &nroCliente);

    printf("\n Nombre del Cliente: ");
    scanf("%s", nombre);

    printf("\n Apellido del Cliente: ");
    scanf("%s", apellido);

    printf("\n DNI: ");
    scanf("%d", &dni);

    printf("\n Email: ");
    scanf("%s", email);

    printf("\n Domicilio: ");
    scanf("%c",&temp);
    scanf("%[^\n]",domicilio);
    //domicilio = d;

    printf("\n Telefono Movil: ");
    scanf("%d", &movil);

    return createCliente(nroCliente, nombre, apellido, dni, email, domicilio, movil);
}

/**
    Visualiza un Cliente
**/
void viewClient(stCliente cliente){
    printf("\n // ------- Cliente ID: %d -------// \n", cliente.id);
    printf(" - Numero Cliente: %d \n", cliente.nroCliente);
    printf(" - Nombre        : %s \n", cliente.nombre);
    printf(" - Apellido      : %s \n", cliente.apellido);
    printf(" - DNI           : %d \n", cliente.dni);
    printf(" - Email         : %s \n", cliente.email);
    printf(" - Domicilio     : %s \n", cliente.domicilio);
    printf(" - Movil         : %d \n", cliente.movil);
    printf(" - Estado Baja   : %d \n", cliente.baja);
    printf("//------------------------------// \n");
}

/**
    Visualiza una lista de Clientes
**/
void viewClientList(stCliente clientes[], int validos){
    printf("//------------- LISTADO DE CLIENTES -------------// \n");
    int i = 0;

    while(i < validos){
        viewClient(clientes[i]);
        i++;
    }
}

/**
    Dar de Baja Cliente
**/
stCliente unsubscribeClient(stCliente * cliente){

    cliente->baja = 1;
    return *cliente;
}

/**
    Modifica un Cliente
**/
stCliente modifyClient(stCliente * cliente, int intValue, char charValue[MAX_SIZE], int field){
    switch(field){
        case 1:
            cliente->nroCliente = intValue;
            break;
        case 2:
            strcpy(cliente->nombre, charValue);
            break;
        case 3:
            strcpy(cliente->apellido, charValue);
            break;
        case 4:
            cliente->dni = intValue;
            break;
        case 5:
            strcpy(cliente->email, charValue);
            break;
        case 6:
            strcpy(cliente->domicilio, charValue);
            break;
        case 7:
            cliente->movil = intValue;
            break;
        case 8:
            cliente->baja = 0;
            break;
    }

    return *cliente;
}

/**
    Buscar Cliente
**/
stCliente * findClientById(stCliente clientes[], int validos, int id){
    int i = 0;
    int flag = 0;

    stCliente * clienteResponse;
    while( i < validos){
        if (clientes[i].id == id){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        clienteResponse = &clientes[i];
    }
    else{
        clienteResponse->id = -1;
    }

    return clienteResponse;
}


stCliente * findClientByNro(stCliente clientes[], int validos, int nroCliente){
    int i = 0;
    int flag = 0;

    stCliente * clienteResponse;
    while( i < validos){
        if (clientes[i].nroCliente == nroCliente){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        clienteResponse = &clientes[i];
    }
    else{
        clienteResponse->id = -1;
    }

    return clienteResponse;
}

stCliente * findClientByApellido(stCliente clientes[], int validos, char apellido[MAX_SIZE]){
    int i = 0;
    int flag = 0;

    stCliente * clienteResponse;

    while( i < validos){
        if (strcmp(clientes[i].apellido,apellido) == 0){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        clienteResponse = &clientes[i];
    }
    else{
        clienteResponse->id = -1;
    }

    return clienteResponse;
}


stCliente * findClientByDNI(stCliente clientes[], int validos, int dni){
    int i = 0;
    int flag = 0;

    stCliente * clienteResponse;
    while( i < validos){
        if (clientes[i].dni == dni){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        clienteResponse = &clientes[i];
    }
    else{
        clienteResponse->id = -1;
    }

    return clienteResponse;
}

void saveOnFileClientes(stCliente clientes[], int validos){
    int i = 0;
    FILE * file;
    file = fopen(FILE_NAME, "wb");

    while(i < validos){
            fwrite(&clientes[i], sizeof(stCliente),1,file);
            i++;
    }
    fclose(file);
}

int loadFromFileClientes(stCliente clientes[]){
    int validos = 0;
    FILE * file;
    if((file = fopen(FILE_NAME, "rb"))!= NULL){
        while(!feof(file)){
            fread(&clientes[validos], sizeof(stCliente),1, file);
            validos++;
        }
        validos--;
        fclose(file);
    }

    return validos;
}

int getLastId(stCliente clientes[], int validos){
    int i = 0, lastId = 0;
    while(i < validos){
        if(lastId <= clientes[i].id){
            lastId = clientes[i].id + 1;
        }
        i++;
    }
    return lastId;
}

int validateNewClient(stCliente clientes[], int validos, stCliente cliente){
    int flag = 1, i = 0;

    while(i < validos){
        if(cliente.nroCliente == clientes[i].nroCliente || cliente.dni == clientes[i].dni){
            flag = 0;
        }
        i++;
    }
    return flag;
}

int getRandomClient(stCliente clientes[], int validos){
    int r = rand() % validos;
    return clientes[r].id;
}
