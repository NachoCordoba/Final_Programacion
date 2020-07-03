#ifndef MENU_H_
#define MENU_H_

#include "cliente.h"

void mainMenu();

void help();

void subHelp();

void subHelpClienteController(stCliente clientes[], int validosClientes);

void invalidOption();

void clearScreen();

void subMenuClient();

int selectedOption();

void mainController(stCliente clientes[], int validosClientes);

void subMenuClientController(stCliente clientes[], int validosClientes);

void findClientOptions();

void findClientController(stCliente clientes[], int validosClientes, int option);

void modifyClienteOptions();

stCliente modifyClientController(stCliente * cliente);


#endif
