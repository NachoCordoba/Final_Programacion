#include "cliente.h"


/**
    Crea un Cliente
**/
stCliente createCliente(int nroCliente, char nombre[30], char apellido[30], int dni, char email[30], char domicilio[30], int movil){
    stCliente cliente;

    /** BUSQUEDA ULTIMO ID **/

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

    clientes[validos] = cliente;

    validos = validos + 1;
    /** AÑADIR EN ARCHIVO **/

    return validos;
}

/**
    Obtiene parametros para agregar un Cliente
**/
stCliente getParamsCliente(){
    int nroCliente, dni, movil;
    char nombre[30], apellido[30], email[30], domicilio[30];

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
    scanf("%s", domicilio);

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
stCliente modifyClient(stCliente * cliente, int intValue, char charValue[30], int field){
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

stCliente * findClientByApellido(stCliente clientes[], int validos, char apellido[30]){
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
