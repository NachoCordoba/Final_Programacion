#ifndef CLIENTE_H_
#define CLIENTE_H_

/**
    ESTRUCTURA CLIENTE
**/

typedef struct {
    int id; // Unico , Autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[30];
    int movil;
    int baja; // 0 si esta activo - 1 si esta eliminado
} stCliente;

/**
    Crea un Cliente
**/
stCliente createCliente(int nroCliente, char nombre[30], char apellido[30], int dni, char email[30], char domicilio[30], int movil);

/**
    Agrega un Cliente a la Lista
**/
int addCliente(stCliente clientes[], int validos, stCliente cliente);

/**
    Obtiene parametros para agregar un Cliente
**/
stCliente getParamsCliente();

/**
    Visualiza un Cliente
**/
void viewClient(stCliente cliente);

/**
    Visualiza una lista de Clientes
**/
void viewClientList(stCliente clientes[], int validos);

/**
    Dar de Baja Cliente
**/
stCliente unsubscribeClient(stCliente * cliente);

/**
    Modifica un Cliente
**/
stCliente modifyClient(stCliente * cliente, int intValue, char charValue[30], int field);

/**
    Buscar Cliente
**/
stCliente * findClientById(stCliente clientes[], int validos, int id);

stCliente * findClientByNro(stCliente clientes[], int validos, int nroCliente);

stCliente * findClientByApellido(stCliente clientes[], int validos, char apellido[]);

stCliente * findClientByDNI(stCliente clientes[], int validos, int dni);




#endif
