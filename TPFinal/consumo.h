#ifndef CONSUMO_H_
#define CONSUMO_H_

/**
    ESTRUCTURA CONSUMO
**/

typedef struct {
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int baja;
} stConsumo;

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
stConsumo createConsumo(int idCliente, int anio, int mes, int dia, int datosConsumidos);

/**
    Funcion: Agrega un consumo a la Lista
    Descripcion: Agrega la estructura de un consumo a la lista.

    @param consumos : Lista de consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param consumo : Consumo a agregar (stConsumo)

    @return validos : Nueva cantidad de Validos (int)

**/
int addConsumo(stConsumo consumos[], int validos, stConsumo consumo);

/**
    Funcion: Parametros de Consumo
    Descripcion: Obtiene los parametros necesarios para la creacion de un consumo.

    @return consumo : Devuelve el nuevo consumo (stConsumo)

**/
stConsumo getParamsConsumo();

/**
    Funcion: Ver Consumo
    Descripcion: Visualiza un consumo en cuestion.

    @param consumo : Consumo a ver (stConsumo)

**/
void viewConsumo(stConsumo consumo);

/**
    Funcion: Ver Lista Consumos
    Descripcion: Muestra la Lista de Consumos.

    @param consumos : Lista de consumos (char[])
    @param validos : Consumos Validos de la lista(int)

**/
void viewConsumoList(stConsumo consumos[], int validos);


/**
    Funcion: Baja Consumo
    Descripcion: Da de baja un consumo, cambiando su propiedad.

    @param consumo : Consumo a modificar (stConsumo)

    @return consumo : Consumo Modificado (stConsumo)

**/
stConsumo unsubscribeConsumo(stConsumo * consumo);

/**
    Funcion: Modifica un Consumo.
    Descripcion: Modifica un Consumo.

    @param consumo : Consumo a Modificar (stConsumo)
    @param intValue: Valor entero a modificar (int)
    @param field : Campo  a modificar (int) 1-- Id cliente  2-- anio 3-- mes  4-- dia 5-- datosConsumidos 6-- habilitar

    @return consumo : Consumo Modificado (stConsumo)

**/
stConsumo modifyConsumo(stConsumo * consumo, int intValue, int field);

/**
    Funcion: Busca un Consumo por ID.
    Descripcion: Busca un consumo en una lista por ID.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param id : id del consumo a buscar (int)

    @return consumo : Consumo encontrado (stConsumo)

**/
stConsumo * findConsumoById(stConsumo consumos[], int validos, int id);

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
stConsumo * findConsumoByFecha(stConsumo consumos[], int validos, int anio, int mes, int dia);

/**
    Funcion: Busca un Consumo por Cliente.
    Descripcion: Busca un consumo en una lista por Cliente.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)
    @param id : id cliente del consumo a buscar (int)

    @return consumo : Consumo encontrado (stConsumo)

**/
stConsumo * findConsumoByCliente(stConsumo consumos[], int validos, int cliente);

/**
    Funcion: Guardar.
    Descripcion: Guarda la informacion de la lista de consumos en un archivo.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista(int)


**/
void saveOnFileConsumo(stConsumo consumos[], int validos);

/**
    Funcion: Leer.
    Descripcion: Lee la informacion la lista de consumos de un archivo.

    @param consumos : Lista de consumos (char[])

    @return validos : Consumos Validos de la lista(int)


**/
int loadFromFileConsumo(stConsumo consumos[]);

/**
    Funcion: Obtener Ultimo ID.
    Descripcion: Obtiene el ultimo ID de la lista de consumos.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista (int)

    @return lastId : El mayor ID encontrado (int)

**/
int getLastIdConsumo(stConsumo consumos[], int validos);

/**
    Funcion: Validacion Nuevo.
    Descripcion: Valida el nuevo consumos.

    @param consumos : Lista de Consumos (char[])
    @param validos : Consumos Validos de la lista (int)
    @param consumo : Consumo a insertar.

    @return flag : Si paso o no la validacion (int) 1-- Paso.  0-- Se agrega al existente.

**/
int validateNewConsumo(stConsumo consumos[], int validos, stConsumo consumo);

/**
    Funcion: Genera random.
    Descripcion: Genera un Consumo Random a la lista.

    @param consumos : Lista de Consumo (char[])
    @param validos : Consumos Validos de la lista (int)
    @param id : ID del cliente (int)

    @return validos: validos nuevo tamaño (int)

**/
int addRandomConsumo(stConsumo consumos[], int validos, int id);
#endif
