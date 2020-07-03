#ifndef MENU_H_
#define MENU_H_

#include "cliente.h"
#include "consumo.h"

/**
    INSTRUCCION VOLVER
**/
void mainMenu();

/**
    INSTRUCCIONES
**/
void help();

/**
    INSTRUCCION VOLVER
**/
void subHelp();

/**
    CONTROLADOR DE INSTRUCCION VOLVER A CLIENTE
**/
void subHelpClienteController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

/**
    CONTROLADOR DE INSTRUCCION VOLVER A CONSUMO
**/
void subHelpConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

/**
    OPCION SELECCIONADA NO VALIDA
**/
void invalidOption();

/**
    LIMPIAR PANTALLA
**/
void clearScreen();

/**
    SUB MENU CLIENTE
**/
void subMenuClient();

/**
    SUB MENU CONSUMO
**/
void subMenuConsumo();

/**
    SELECCION DE OPCION POR TECLADO
**/
int selectedOption();

/**
    CONTROLADOR DEL MENU PRINCIPAL
**/
void mainController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

/**
    CONTROLADOR DEL SUB MENU DE CLIENTES
**/
void subMenuClientController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

/**
    CONTROLADOR DEL SUB MENU DE CONSUMOS
**/
void subMenuConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

/**
    OPCIONES DE BUSQUEDA DE CLIENTES
**/
void findClientOptions();

/**
    CONTROLADOR DE OPCIONES DE BUSQUEDA DE CLIENTES
**/
void findClientController(stCliente clientes[], int validosClientes, int option);

/**
    OPCIONES DE BUSQUEDA DE CONSUMOS
**/
void findConsumoOptions();

/**
    CONTROLADOR DE OPCIONES DE BUSQUEDA DE CONSUMOS
**/
void findConsumoController(stConsumo consumos[], int validosConsumo, int option);

/**
    OPCIONES DE MODIFICACION DE CLIENTES
**/
void modifyClienteOptions();

/**
    CONTROLADOR DE OPCIONES DE MODIFICACION DE CLIENTES
**/
stCliente modifyClientController(stCliente * cliente);

/**
    OPCIONES DE MODIFICACION DE CONSUMOS
**/
void modifyConsumoOptions();

/**
    CONTROLADOR DE OPCIONES DE MODIFICACION DE CONSUMOS
**/
stConsumo modifyConsumoController(stConsumo * consumo);

#endif
