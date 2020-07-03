#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menu.h"

int main()
{
    stCliente clientes[300];
    stConsumo consumos[600];
    int validosClientes = loadFromFileClientes(clientes);
    int validosConsumos = loadFromFileConsumo(consumos);
    mainController(clientes, validosClientes, consumos, validosConsumos);
    return 0;
}
