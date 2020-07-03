#include "menu.h"

void mainMenu(){
    printf(" ¡Bienvenido! \n");
    printf(" Sistema de Clientes y Consumos. \n");

    help();

    printf(" 1.- Clientes \n");
}

void help(){
    printf(" Para continuar, debe seleccionar una de las opciones mostradas en pantalla. \n");
}

void subHelp(){
    printf("\n 9.- Volver. ");
}

void subHelpClienteController(stCliente clientes[], int validosClientes){
    help();
    subHelp();
    switch(selectedOption()){
        case 9:
           subMenuClientController(clientes, validosClientes);
           break;
        default:
            invalidOption();
            subHelpClienteController(clientes, validosClientes);
            break;
    }
}

void invalidOption(){
    printf(" La opcion que selecciono, no corresponde a ninguna de las anteriores. Por favor, vuelva a intentar. \n");
}

void clearScreen(){
    system("cls");
}

void subMenuClient(){
    printf("//------- SECCION DE CLIENTES -------//\n");
    printf(" 1.- Agregar un nuevo Cliente. \n");
    printf(" 2.- Modificar un Cliente. \n");
    printf(" 3.- Dar de Baja un Cliente. \n");
    printf(" 4.- Buscar un Cliente. \n");
    printf(" 5.- Listar todos los Clientes. \n");
    printf(" 9.- Volver \n");

    help();
}

int selectedOption(){
    int option;

    printf("\n Opcion: ");
    scanf("%d", &option);

    return option;
}


void mainController(stCliente clientes[], int validosClientes){
    clearScreen();
    mainMenu();

    switch(selectedOption()){
        case 1:
            subMenuClientController(clientes, validosClientes);
            break;
        default:
            invalidOption();
            sleep(3);
            mainController(clientes, validosClientes);
            break;
    }
}


void subMenuClientController(stCliente clientes[], int validosClientes){
    clearScreen();
    subMenuClient();

    switch(selectedOption()){
        case 1:
            validosClientes = addCliente(clientes, validosClientes, getParamsCliente());
            break;
        case 2:
            findClientController(clientes, validosClientes, 1);
            break;
        case 3:
            findClientController(clientes, validosClientes, 2);
            break;
        case 4:
            findClientController(clientes, validosClientes, 0);
            break;
        case 5:
            viewClientList(clientes, validosClientes);
            break;
        case 9:
            mainController(clientes, validosClientes);
            break;
        default:
            invalidOption();
            sleep(3);
            break;
    }

    subHelpClienteController(clientes, validosClientes);
}

void findClientOptions(){
    printf("\n //-- Busqueda de Cliente --//");
    printf("\n 1.- Buscar por ID.");
    printf("\n 2.- Buscar por Numero de Cliente.");
    printf("\n 3.- Buscar por Apellido.");
    printf("\n 4.- Buscar por DNI.");
    printf("\n 9.- Volver.");
}

void findClientController(stCliente clientes[], int validosClientes, int option){
    clearScreen();
    findClientOptions();
    int number;
    char cadena[30];
    stCliente * cliente;

    switch(selectedOption()){
        case 1:
            printf("\n Ingrese el ID:");
            scanf("%d", &number);
            cliente = findClientById(clientes, validosClientes, number);
            if(option == 1)
                modifyClientController(cliente);
            if(option == 2)
                unsubscribeClient(cliente);
            viewClient(*cliente);
            break;
        case 2:
            printf("\n Ingrese el Numero del Cliente:");
            scanf("%d", &number);
            cliente = findClientByNro(clientes, validosClientes, number);
            if(option == 1)
                modifyClientController(cliente);
            if(option == 2)
                unsubscribeClient(cliente);
            viewClient(*cliente);
            break;
        case 3:
            printf("\n Ingrese el Apellido:");
            scanf("%s", cadena);
            cliente = findClientByApellido(clientes, validosClientes, cadena);
            if(option == 1)
                modifyClientController(cliente);
            if(option == 2)
                unsubscribeClient(cliente);
            viewClient(*cliente);
            break;
        case 4:
            printf("\n Ingrese el DNI:");
            scanf("%d", &number);
            cliente = findClientByDNI(clientes, validosClientes, number);
            if(option == 1)
                modifyClientController(cliente);
            if(option == 2)
                unsubscribeClient(cliente);
            viewClient(*cliente);
            break;
        case 9:
            subMenuClientController(clientes, validosClientes);
            break;
    }
    subHelpClienteController(clientes, validosClientes);
    //subMenuClientController(clientes, validosClientes);
}

void modifyClienteOptions(){
    printf("\n //----- MODIFICA CLIENTE -----//");
    printf("\n 1.- Modificar Numero Cliente.");
    printf("\n 2.- Modificar Nombre.");
    printf("\n 3.- Modificar Apellido.");
    printf("\n 4.- Modificar DNI.");
    printf("\n 5.- Modificar Email.");
    printf("\n 6.- Modificar Domicilio.");
    printf("\n 7.- Modificar Movil.");
    printf("\n 8.- Habilitar.");
}

stCliente modifyClientController(stCliente * cliente){
    clearScreen();
    viewClient(*cliente);
    modifyClienteOptions();
    subHelp();
    help();

    int intValue;
    char charValue[30];

    switch(selectedOption()){
        case 1:
            printf("\n Seleccione el nuevo valor de Numero Cliente: ");
            scanf("%d", &intValue);
            modifyClient(cliente,intValue,charValue,1);
            break;
        case 2:
            printf("\n Seleccione el nuevo valor de Nombre: ");
            scanf("%s", charValue);
            modifyClient(cliente,intValue,charValue,2);
            break;
        case 3:
            printf("\n Seleccione el nuevo valor de Apellido: ");
            scanf("%s", charValue);
            modifyClient(cliente,intValue,charValue,3);
            break;
        case 4:
            printf("\n Seleccione el nuevo valor de DNI: ");
            scanf("%d", &intValue);
            modifyClient(cliente,intValue,charValue,4);
            break;
        case 5:
            printf("\n Seleccione el nuevo valor de Email: ");
            scanf("%s", charValue);
            modifyClient(cliente,intValue,charValue,5);
            break;
        case 6:
            printf("\n Seleccione el nuevo valor de Domicilio: ");
            scanf("%s", charValue);
            modifyClient(cliente,intValue,charValue,6);
            break;
        case 7:
            printf("\n Seleccione el nuevo valor de Movil: ");
            scanf("%d", &intValue);
            modifyClient(cliente,intValue,charValue,7);
            break;
        case 8:
            modifyClient(cliente,intValue,charValue,8);
            break;
    }
}


