#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menu.h"

int main()
{
    stCliente clientes[300];
    int validosClientes = 0;
    mainController(clientes, validosClientes);
    return 0;
}
