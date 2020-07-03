#ifndef CONSUMO_H_
#define CONSUMO_H_

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
    Crea un Consumo
**/
stConsumo createConsumo(int idCliente, int anio, int mes, int dia, int datosConsumidos);

/**
    Agrega un Consumo a la Lista
**/
int addConsumo(stConsumo consumos[], int validos, stConsumo consumo);

/**
    Obtiene parametros para agregar un Consumo
**/
stConsumo getParamsConsumo();

/**
    Visualiza un Consumo
**/
void viewConsumo(stConsumo consumo);

/**
    Visualiza una lista de Consumo
**/
void viewConsumoList(stConsumo consumos[], int validos);

/**
    Dar de Baja Consumo
**/
stConsumo unsubscribeConsumo(stConsumo * consumo);

/**
    Modifica un Consumo
**/
stConsumo modifyConsumo(stConsumo * consumo, int intValue, int field);

/**
    Buscar Consumo
**/
stConsumo * findConsumoById(stConsumo consumos[], int validos, int id);

stConsumo * findConsumoByFecha(stConsumo consumos[], int validos, int anio, int mes, int dia);

stConsumo * findConsumoByCliente(stConsumo consumos[], int validos, int cliente);

void saveOnFileConsumo(stConsumo consumos[], int validos);

int loadFromFileConsumo(stConsumo consumos[]);

int getLastIdConsumo(stConsumo consumos[], int validos);

int validateNewConsumo(stConsumo consumos[], int validos, stConsumo consumo);

int addRandomConsumo(stConsumo consumos[], int validos, int id);
#endif
