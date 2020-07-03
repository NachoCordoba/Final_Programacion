#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 30
#define FILE_NAME "clientes.dat"

/**
    Funcion: Crea un Cliente
    Descripcion: Crea la estructura de un cliente.

    @param nroCliente : Numero del Cliente (int)
    @param nombre : Nombre del Cliente (char)
    @param apellido : Apellido del Cliente (char)
    @param dni : Documento (int)
    @param email : Email (char)
    @param domicilio : Direccion (char)
    @param movil : Telefono (char)

    @return cliente : Estructura con datos Nuevo Cliente (stCliente)

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
    Funcion: Agrega un Cliente a la Lista
    Descripcion: Agrega la estructura de un cliente a la lista.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param cliente : Cliente a agregar (stCliente)

    @return validos : Nueva cantidad de Validos (int)

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
    Funcion: Parametros de Cliente
    Descripcion: Obtiene los parametros necesarios para la creacion de un cliente.

    @return cliente : Devuelve el nuevo cliente (stCliente)

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
    Funcion: Ver Cliente
    Descripcion: Visualiza un cliente en cuestion.

    @param cliente : Cliente a ver (stCliente)

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
    Funcion: Ver Lista Clientes
    Descripcion: Muestra la Lista de Clientes.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)

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
    Funcion: Baja Cliente
    Descripcion: Da de baja un cliente, cambiando su propiedad.

    @param cliente : Cliente a modificar (stCliente)

    @return cliente : Cliente Modificado (stCliente)

**/
stCliente unsubscribeClient(stCliente * cliente){

    cliente->baja = 1;
    return *cliente;
}

/**
    Funcion: Modifica un Cliente.
    Descripcion: Modifica un Cliente.

    @param cliente : Cliente a agregar (stCliente)
    @param intValue: Valor entero a modificar (int)
    @param charValue: Valor cadena a modificar (char)
    @param field : Campo  a modificar (int) 1-- Numero Cliente  2-- Nombre 3-- Apellido  4-- DNI 5-- Email  6-- Domicilio 7-- Habilitar

    @return cliente : Cliente Modificado (stCliente)

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
    Funcion: Busca un Cliente por ID.
    Descripcion: Busca un cliente en una lista por ID.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param id : id del cliente a buscar (int)

    @return cliente : Cliente encontrado (stCliente)

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

/**
    Funcion: Busca un Cliente por Numero.
    Descripcion: Busca un cliente en una lista por Numero Cliente.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param nroCliente : Numero del Cliente (int)

    @return cliente : Cliente encontrado (stCliente)

**/
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

/**
    Funcion: Busca un Cliente por Apellido.
    Descripcion: Busca un cliente en una lista por Apellido.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param apellido : Apellido del Cliente (char)

    @return cliente : Cliente encontrado (stCliente)

**/
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

/**
    Funcion: Busca un Cliente por DNI.
    Descripcion: Busca un cliente en una lista por DNI.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param DNI : DNI del Cliente (int)

    @return cliente : Cliente encontrado (stCliente)

**/
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

/**
    Funcion: Guardar.
    Descripcion: Guarda la informacion de la lista de clientes en un archivo.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)


**/
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

/**
    Funcion: Leer.
    Descripcion: Lee la informacion la lista de clientes de un archivo.

    @param clientes : Lista de Clientes (char[])

    @return validos : Clientes Validos de la lista(int)


**/
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

/**
    Funcion: Obtener Ultimo ID.
    Descripcion: Obtiene el ultimo ID de la lista de clientes.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)

    @return lastId : El mayor ID encontrado (int)

**/
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

/**
    Funcion: Validacion Nuevo.
    Descripcion: Valida el nuevo cliente.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)
    @param cliente : Cliente a insertar.

    @return flag : Si paso o no la validacion (int) 1-- Paso.  0-- No Paso.

**/
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

/**
    Funcion: Obtiene random.
    Descripcion: Obtiene un Cliente Random de la lista.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)

    @return id : el id obtenido random (int)

**/
int getRandomClient(stCliente clientes[], int validos){
    int r = rand() % validos + 1;
    return clientes[r].id;
}
