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
stCliente createCliente(int nroCliente, char nombre[30], char apellido[30], int dni, char email[30], char domicilio[30], int movil);

/**
    Funcion: Agrega un Cliente a la Lista
    Descripcion: Agrega la estructura de un cliente a la lista.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param cliente : Cliente a agregar (stCliente)

    @return validos : Nueva cantidad de Validos (int)

**/
int addCliente(stCliente clientes[], int validos, stCliente cliente);

/**
    Funcion: Parametros de Cliente
    Descripcion: Obtiene los parametros necesarios para la creacion de un cliente.

    @return cliente : Devuelve el nuevo cliente (stCliente)

**/
stCliente getParamsCliente();

/**
    Funcion: Ver Cliente
    Descripcion: Visualiza un cliente en cuestion.

    @param cliente : Cliente a ver (stCliente)

**/
void viewClient(stCliente cliente);

/**
    Funcion: Ver Lista Clientes
    Descripcion: Muestra la Lista de Clientes.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)

**/
void viewClientList(stCliente clientes[], int validos);

/**
    Funcion: Baja Cliente
    Descripcion: Da de baja un cliente, cambiando su propiedad.

    @param cliente : Cliente a modificar (stCliente)

    @return cliente : Cliente Modificado (stCliente)

**/
stCliente unsubscribeClient(stCliente * cliente);

/**
    Funcion: Modifica un Cliente.
    Descripcion: Modifica un Cliente.

    @param cliente : Cliente a agregar (stCliente)
    @param intValue: Valor entero a modificar (int)
    @param charValue: Valor cadena a modificar (char)
    @param field : Campo  a modificar (int) 1-- Numero Cliente  2-- Nombre 3-- Apellido  4-- DNI 5-- Email  6-- Domicilio 7-- Habilitar

    @return cliente : Cliente Modificado (stCliente)

**/
stCliente modifyClient(stCliente * cliente, int intValue, char charValue[30], int field);

/**
    Funcion: Busca un Cliente por ID.
    Descripcion: Busca un cliente en una lista por ID.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param id : id del cliente a buscar (int)

    @return cliente : Cliente encontrado (stCliente)

**/
stCliente * findClientById(stCliente clientes[], int validos, int id);

/**
    Funcion: Busca un Cliente por Numero.
    Descripcion: Busca un cliente en una lista por Numero Cliente.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param nroCliente : Numero del Cliente (int)

    @return cliente : Cliente encontrado (stCliente)

**/
stCliente * findClientByNro(stCliente clientes[], int validos, int nroCliente);

/**
    Funcion: Busca un Cliente por DNI.
    Descripcion: Busca un cliente en una lista por DNI.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param DNI : DNI del Cliente (int)

    @return cliente : Cliente encontrado (stCliente)

**/
stCliente * findClientByApellido(stCliente clientes[], int validos, char apellido[]);

/**
    Funcion: Busca un Cliente por DNI.
    Descripcion: Busca un cliente en una lista por DNI.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)
    @param DNI : DNI del Cliente (int)

    @return cliente : Cliente encontrado (stCliente)

**/
stCliente * findClientByDNI(stCliente clientes[], int validos, int dni);

/**
    Funcion: Guardar.
    Descripcion: Guarda la informacion de la lista de clientes en un archivo.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista(int)


**/
void saveOnFileClientes(stCliente clientes[], int validos);

/**
    Funcion: Leer.
    Descripcion: Lee la informacion la lista de clientes de un archivo.

    @param clientes : Lista de Clientes (char[])

    @return validos : Clientes Validos de la lista(int)


**/
int loadFromFileClientes(stCliente clientes[]);

/**
    Funcion: Obtener Ultimo ID.
    Descripcion: Obtiene el ultimo ID de la lista de clientes.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)

    @return lastId : El mayor ID encontrado (int)

**/
int getLastId(stCliente clientes[], int validos);

/**
    Funcion: Validacion Nuevo.
    Descripcion: Valida el nuevo cliente.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)
    @param cliente : Cliente a insertar.

    @return flag : Si paso o no la validacion (int) 1-- Paso.  0-- No Paso.

**/
int validateNewClient(stCliente clientes[], int validos, stCliente cliente);

/**
    Funcion: Obtiene random.
    Descripcion: Obtiene un Cliente Random de la lista.

    @param clientes : Lista de Clientes (char[])
    @param validos : Clientes Validos de la lista (int)

    @return id : el id obtenido random (int)

**/
int getRandomClient(stCliente clientes[], int validos);


#endif
