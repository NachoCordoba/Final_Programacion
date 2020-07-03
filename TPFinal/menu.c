#include "menu.h"

/**
    MENU PRINCIPAL
**/
void mainMenu(){
    printf(" ¡Bienvenido! \n");
    printf(" Sistema de Clientes y Consumos. \n");

    help();

    printf(" 1.- Clientes \n");
    printf(" 2.- Consumos \n");
}

/**
    INSTRUCCIONES
**/
void help(){
    printf("\n Para continuar, debe seleccionar una de las opciones mostradas en pantalla. \n");
}

/**
    INSTRUCCION VOLVER
**/
void subHelp(){
    printf("\n 9.- Volver. ");
}

/**
    CONTROLADOR DE INSTRUCCION VOLVER A CLIENTE
**/
void subHelpClienteController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos){
    help();
    subHelp();
    switch(selectedOption()){
        case 9:
           subMenuClientController(clientes, validosClientes, consumos, validosConsumos);
           break;
        default:
            invalidOption();
            subHelpClienteController(clientes, validosClientes, consumos, validosConsumos);
            break;
    }
}

/**
    CONTROLADOR DE INSTRUCCION VOLVER A CONSUMO
**/
void subHelpConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos){
    help();
    subHelp();
    switch(selectedOption()){
        case 9:
           subMenuConsumoController(clientes, validosClientes, consumos, validosConsumos);
           break;
        default:
            invalidOption();
            subHelpConsumoController(clientes, validosClientes, consumos, validosConsumos);
            break;
    }
}

/**
    OPCION SELECCIONADA NO VALIDA
**/
void invalidOption(){
    printf(" La opcion que selecciono, no corresponde a ninguna de las anteriores. Por favor, vuelva a intentar. \n");
}

/**
    LIMPIAR PANTALLA
**/
void clearScreen(){
    system("cls");
}

/**
    SUB MENU CLIENTE
**/
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

/**
    SUB MENU CONSUMO
**/
void subMenuConsumo(){
    printf("//------- SECCION DE CONSUMOS -------//\n");
    printf(" 1.- Agregar un nuevo Consumo. \n");
    printf(" 2.- Modificar un Consumo. \n");
    printf(" 3.- Dar de Baja un Consumo. \n");
    printf(" 4.- Buscar un Consumo. \n");
    printf(" 5.- Listar todos los Consumos. \n");
    printf(" 6.- Generar Consumos Aleatorios (1000). \n");
    printf(" 9.- Volver \n");

    help();
}

/**
    SELECCION DE OPCION POR TECLADO
**/
int selectedOption(){
    int option;

    printf("\n Opcion: ");
    scanf("%d", &option);

    return option;
}

/**
    CONTROLADOR DEL MENU PRINCIPAL
**/
void mainController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos){
    clearScreen();
    mainMenu();

    switch(selectedOption()){
        case 1:
            subMenuClientController(clientes, validosClientes, consumos, validosConsumos);
            break;
        case 2:
            subMenuConsumoController(clientes, validosClientes, consumos, validosConsumos);
            break;
        default:
            invalidOption();
            sleep(3);
            mainController(clientes, validosClientes, consumos, validosConsumos);
            break;
    }
}

/**
    CONTROLADOR DEL SUB MENU DE CLIENTES
**/
void subMenuClientController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos){
    clearScreen();
    subMenuClient();

    switch(selectedOption()){
        case 1:
            validosClientes = addCliente(clientes, validosClientes, getParamsCliente());
            saveOnFileClientes(clientes, validosClientes);
            break;
        case 2:
            findClientController(clientes, validosClientes, 1);
            saveOnFileClientes(clientes, validosClientes);
            break;
        case 3:
            findClientController(clientes, validosClientes, 2);
            saveOnFileClientes(clientes, validosClientes);
            break;
        case 4:
            findClientController(clientes, validosClientes, 0);
            break;
        case 5:
            viewClientList(clientes, validosClientes);
            break;
        case 9:
            mainController(clientes, validosClientes, consumos, validosConsumos);
            break;
        default:
            invalidOption();
            sleep(3);
            break;
    }

    subHelpClienteController(clientes, validosClientes, consumos, validosConsumos);
}

/**
    CONTROLADOR DEL SUB MENU DE CONSUMOS
**/
void subMenuConsumoController(stCliente clientes[], int validosClientes, stConsumo consumos[], int validosConsumos){
    clearScreen();
    subMenuConsumo();

    int i = 0;

    switch(selectedOption()){
        case 1:
            validosConsumos = addConsumo(consumos, validosConsumos, getParamsConsumo());
            saveOnFileConsumo(consumos, validosConsumos);
            break;
        case 2:
            findConsumoController(consumos, validosConsumos, 1);
            saveOnFileConsumo(consumos, validosConsumos);
            break;
        case 3:
            findConsumoController(consumos, validosConsumos, 2);
            saveOnFileConsumo(consumos, validosConsumos);
            break;
        case 4:
            findConsumoController(consumos, validosConsumos, 0);
            break;
        case 5:
            viewConsumoList(consumos, validosConsumos);
            break;
        case 6:
            while(i < 1000){
                validosConsumos = addRandomConsumo(consumos, validosConsumos, getRandomClient(clientes, validosClientes));
                i++;
            }
            saveOnFileConsumo(consumos, validosConsumos);
            break;
        case 9:
            mainController(clientes, validosClientes, consumos, validosConsumos);
            break;
        default:
            invalidOption();
            sleep(3);
            break;
    }

    subHelpConsumoController(clientes, validosClientes, consumos, validosConsumos);
}

/**
    OPCIONES DE BUSQUEDA DE CLIENTES
**/
void findClientOptions(){
    printf("\n //-- Busqueda de Cliente --//");
    printf("\n 1.- Buscar por ID.");
    printf("\n 2.- Buscar por Numero de Cliente.");
    printf("\n 3.- Buscar por Apellido.");
    printf("\n 4.- Buscar por DNI.");
    printf("\n 9.- Volver.");
}

/**
    OPCIONES DE BUSQUEDA DE CONSUMOS
**/
void findConsumoOptions(){
    printf("\n //-- Busqueda de Consumo --//");
    printf("\n 1.- Buscar por ID.");
    printf("\n 2.- Buscar por Fecha.");
    printf("\n 3.- Buscar por Cliente.");
    printf("\n 9.- Volver.");
}

/**
    CONTROLADOR OPCIONES DE BUSQUEDA DE CLIENTES
**/
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
            //subMenuClientController(clientes, validosClientes, consumos, validosCo);
            break;
    }
    //subHelpClienteController(clientes, validosClientes);
    //subMenuClientController(clientes, validosClientes);
}

/**
    CONTROLADOR DE OPCIONES DE BUSQUEDA DE CONSUMOS
**/
void findConsumoController(stConsumo consumos[], int validosConsumos, int option){
    clearScreen();
    findConsumoOptions();
    int number, number2, number3;
    stConsumo * consumo;

    switch(selectedOption()){
        case 1:
            printf("\n Ingrese el ID:");
            scanf("%d", &number);
            consumo = findConsumoById(consumos, validosConsumos, number);
            if(option == 1)
                modifyConsumoController(consumo);
            if(option == 2)
                unsubscribeConsumo(consumo);
            viewConsumo(*consumo);
            break;
        case 2:
            printf("\n Ingrese el anio: ");
            scanf("%d", &number);
            printf("\n Ingrese el mes: ");
            scanf("%d", &number2);
            printf("\n Ingrese el dia: ");
            scanf("%d", &number3);
            consumo = findConsumoByFecha(consumos, validosConsumos, number, number2, number3);
            if(option == 1)
                modifyConsumoController(consumo);
            if(option == 2)
                unsubscribeConsumo(consumo);
            viewConsumo(*consumo);
            break;
        case 3:
            printf("\n Ingrese el Numero del Cliente:");
            scanf("%d", &number);
            consumo = findConsumoByCliente(consumos, validosConsumos, number);
            if(option == 1)
                modifyConsumoController(consumo);
            if(option == 2)
                unsubscribeConsumo(consumo);
            viewConsumo(*consumo);
            break;
        case 9:
            //subMenuConsumoController(consumos, validosConsumos);
            break;
    }
    //subHelpConsumoController(consumos, validosConsumos);
}

/**
    OPCIONES DE MODIFICACION DE CLIENTES
**/
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

/**
    OPCIONES DE MODIFICACION DE CONSUMOS
**/
void modifyConsumoOptions(){
    printf("\n //----- MODIFICA CONSUMO -----//");
    printf("\n 1.- Modificar el ID del Cliente.");
    printf("\n 2.- Modificar Anio.");
    printf("\n 3.- Modificar Mes.");
    printf("\n 4.- Modificar Dia.");
    printf("\n 5.- Modificar Datos Consumidos.");
    printf("\n 6.- Habilitar.");
}

/**
    CONTROLADOR DE OPCIONES DE MODIFICACION DE CLIENTES
**/
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


/**
    CONTROLADOR DE OPCIONES DE MODIFICACION DE CONSUMOS
**/
stConsumo modifyConsumoController(stConsumo * consumo){
    clearScreen();
    viewConsumo(*consumo);
    modifyConsumoOptions();
    subHelp();
    help();

    int intValue;

    switch(selectedOption()){
        case 1:
            printf("\n Seleccione el nuevo valor de ID Cliente: ");
            scanf("%d", &intValue);
            modifyConsumo(consumo,intValue,1);
            break;
        case 2:
            printf("\n Seleccione el nuevo valor de Anio: ");
            scanf("%d", &intValue);
            modifyConsumo(consumo,intValue,2);
            break;
        case 3:
            printf("\n Seleccione el nuevo valor de Mes: ");
            scanf("%d", &intValue);
            modifyConsumo(consumo,intValue,3);
            break;
        case 4:
            printf("\n Seleccione el nuevo valor de Dia: ");
            scanf("%d", &intValue);
            modifyConsumo(consumo,intValue,4);
            break;
        case 5:
            printf("\n Seleccione el nuevo valor de Datos Consumidos: ");
            scanf("%d", &intValue);
            modifyConsumo(consumo,intValue,5);
            break;
        case 6:
            modifyConsumo(consumo,intValue,6);
            break;
    }
}


