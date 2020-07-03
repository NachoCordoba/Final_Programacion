#ifndef MENU_H_
#define MENU_H_

#include "cliente.h"
#include "consumo.h"

void mainMenu();

void help();

void subHelp();

void subHelpClienteController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

void subHelpConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

void invalidOption();

void clearScreen();

void subMenuClient();

void subMenuConsumo();

int selectedOption();

void mainController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

void subMenuClientController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

void subMenuConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos);

void findClientOptions();

void findClientController(stCliente clientes[], int validosClientes, int option);

void findConsumoOptions();

void findConsumoController(stConsumo consumos[], int validosConsumo, int option);

void modifyClienteOptions();

stCliente modifyClientController(stCliente * cliente);

void modifyConsumoOptions();

stConsumo modifyConsumoController(stConsumo * consumo);

#endif
