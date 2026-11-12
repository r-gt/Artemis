#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "validaciones.h"
// #include "simulador.h"
#include "artemis.h"

typedef enum {
    OP_INICIAL_SALIR = 0,
    OP_INICIAL_SIMULACION = 1,
    OP_MOSTRAR_INFORMACION = 2
} OpcionInicial;

typedef enum {
    OP_SIMULACION_SALIR = 0,
    OP_SIMULACION_ESTANDAR = 1,
    OP_SIMULACION_PERSONALIZADA = 2,
    OP_VOLVER = 3
} OpcionSimulacion;

typedef enum {
    MODO_ESTANDAR = 1,
    MODO_PERSONALIZADO = 2
} ModoSimulacion;

typedef struct {
    float aceleracionTramoA;
    int tiempoDesprendimiento;
    float aceleracionTramoB;
} DatosSimulacion;

/* Prototipos de las funciones que se usan antes de definirse. */

int leerConfirmacion(void);
void iniciarSimulacion(ModoSimulacion modo, int *continuar);
void iniciarDespegue(
    DatosSimulacion datos,
    long instanteDespegue,
    int *continuar
);
void mostrarEventos(void);
void mostrarEstadoActual(void);
void mostrarInforme(void);

// funciones de presentación

void mostrarSeparador(void){
    printf("\n----------------------------------\n");
}

void limpiarPantalla(void){
    /* Borra lo que hay en la consola y deja el cursor arriba. */
    printf("\033[2J\033[H");
    fflush(stdout);
}

void abrirMenuPrincipal(void){
    mostrarSeparador();
    printf("\nMENÚ PRINCIPAL\n");
    printf("\t1. Iniciar simulación\n");
    printf("\t2. Mostrar información\n");
    printf("\t0. Salir\n");
}

// funciones de lectura

int leerOpcion(int min, int max){
    int opcion;
    int resultado;
    int caracter;

    do {
        printf("\nSeleccione una opcion: ");
        resultado = scanf("%d", &opcion);

        // se eliminan los caracteres restantes de la línea

        do {
            caracter = getchar();
        } while (caracter != '\n' && caracter != EOF);

        if (resultado != 1){
            printf("Entrada no valida. Debe ingresar un número.\n");
        } else if (opcion < min || opcion > max) {
            printf("Opcion no valida. Ingrese un valor entre %d y %d.\n", min, max);
        };
    } while (resultado != 1 || opcion < min || opcion > max);

    return opcion;
}

OpcionInicial pedirOpcionInicial(void){
    int opcion;

    abrirMenuPrincipal();

    opcion = leerOpcion(0, 2);

    return (OpcionInicial)opcion;
}

// mostrar información

void mostrarInformacion(void){
    mostrarSeparador();
    printf("\nINFORMACIÓN DE SIMULACIÓN:\n");
    printf("\t* aceleración del tramo A: 20 m/s^2\n");
    printf("\t* tiempo de desprendimiento: 120 segundos\n");
    printf("\t* aceleración del tramo B: 12,5 m/s^2\n");
}

// menú de simulación

void abrirMenuSimulacion(int *continuar){

    OpcionSimulacion opcion;
    int volver;

    volver = 0;

    while (*continuar && !volver){
        limpiarPantalla();
        mostrarSeparador();
        printf("\nSIMULADOR ARTEMIS\n");
        printf("\t1. Simulación estándar\n");
        printf("\t2. Simulación personalizada\n");
        printf("\t3. Volver\n");

        // mover a validaciones

        opcion = (OpcionSimulacion) leerOpcion(0, 3);

        switch (opcion){
            case OP_SIMULACION_ESTANDAR:
                printf("\nIniciando simulación estándar...\n");
                sleep(3);
                iniciarSimulacion(MODO_ESTANDAR, continuar);
                break;
            case OP_SIMULACION_PERSONALIZADA:
                printf("\nIniciando simulación personalizada...\n");
                sleep(3);
                iniciarSimulacion(MODO_PERSONALIZADO, continuar);
                break;
            case OP_VOLVER:
                volver = 1;
                break;
            case OP_SIMULACION_SALIR:
                *continuar = 0;
                break;
        }
    }
}

// preparación de los datos

DatosSimulacion cargarDatos(ModoSimulacion modo)
{
    DatosSimulacion datos;

    // inicializa campos mientras artemis.c no proporciona los datos

    datos.aceleracionTramoA = 0.0f;
    datos.tiempoDesprendimiento = 0.0f;
    datos.aceleracionTramoB = 0.0f;

    if (modo == MODO_ESTANDAR)
    {

        // datos = obtenerDatosEstandar();
        // función de artemis.c

        printf("\nSe cargarán los datos desde artemis.c ...\n");
        sleep(3);

        return datos;
    }

    /*
    * do {
    *   a1 = leerRealPositivo(...);
    *   t = leerEnteroPositivo(...);
    *   a2 = leerRealPositivo(...);
    *
    *   datos = crearDatosPersonalizados(a1, t, a2);
    *   datosValidos = validarDatosSimulacion(datos);
    *} while(!datosValidos);
    *
    */

    printf("\nSe solicitarán y validarán valores personalizados...\n");

    return datos;
}

// secuencia de lanzamiento

void cuentaRegresiva(void) {
    int i;

    printf("\nPreparando despegue...\n");
    fflush(stdout);

    for(i = 10; i >= 1; i --) {
        printf("\r%2d", i);
        fflush(stdout);
        sleep(1);
    }
}

void pedirSenalDespegue(void)
{
    printf("\nAquí el programa pedirá señal de despegue...\n");
}

void iniciarSimulacion(ModoSimulacion modo, int *continuar)
{
    DatosSimulacion datos;
    long instanteDespegue;

    datos = cargarDatos(modo);

    mostrarSeparador();
    pedirSenalDespegue();
    sleep(3);

    // instanteDespegue = obtenerInstanteActual();

    instanteDespegue = 0;

    iniciarDespegue(datos, instanteDespegue, continuar);
}

void iniciarDespegue(
    DatosSimulacion datos,
    long instanteDespegue,
    int *continuar
)
{
    (void) datos;
    (void) instanteDespegue;

    mostrarSeparador();
    printf("\n¡Despegando!\n");
    sleep(3);

    mostrarEstadoActual();
    sleep(3);

    mostrarEventos();
    sleep(3);

    mostrarInforme();
    sleep(3);

    if (!leerConfirmacion()) {
        *continuar = 0;
    }
}

void mostrarEventos(void)
{
    printf("\nDurante la simulación se mostrará:\n");
    printf("\n\t* desprendimiento de SRB");
    printf("\n\t* fallo del motor principal");
    printf("\n\t* altura máxima alcanzada");
    printf("\n\t* impacto de la nave\n");
}

void mostrarEstadoActual(void)
{
    // muestras calculadas por artemis.c
    printf("\nSe muestra altura actual y velocidad actual...\n");
    sleep(3);
}

void mostrarInforme(void)
{
    mostrarSeparador();
    printf("\nINFORME FINAL:\n");
    printf("\t* velocidad final tramo A\n");
    printf("\t* altura final tramo A\n");
    printf("\t* aceleración en función de la gravedad\n");
    printf("\t* velocidad final tramo B\n");
    printf("\t* altura máxima tramo C\n");

    // resultados obtenidos desde artemis.c
}

int leerConfirmacion(void)
{
    char respuesta;
    int resultado;
    int caracter;
    int condicion;

    do {
        printf("\n¿Desea continuar? (s/n)\n");
        resultado = scanf(" %c", &respuesta);

        do {
            caracter = getchar();
        } while (caracter != '\n' && caracter != EOF);

        condicion = (respuesta != 's'
            && respuesta != 'S'
            && respuesta != 'n'
            && respuesta != 'N');

        if (resultado != 1 || condicion) {
            printf("\nEntrada no válida. Reintente.\n");
        }
    } while (resultado != 1 || condicion);

    return (respuesta == 's' || respuesta == 'S');
}

// proceso principal

int main(){
    OpcionInicial opcion;

    int continuar = 1;
    int mostrarBienvenida = 1;

    while (continuar){
        limpiarPantalla();

        if (mostrarBienvenida){
            printf("\nBIENVENIDO AL SIMULADOR ARTEMIS\n");
            mostrarBienvenida = 0;
        }

        opcion = pedirOpcionInicial();

        switch (opcion){
            case OP_INICIAL_SIMULACION:
                abrirMenuSimulacion(&continuar);
                break;
            case OP_MOSTRAR_INFORMACION:
                limpiarPantalla();
                mostrarInformacion();
                if(!leerConfirmacion()) {
                    continuar = 0;
                }
                break;
            case OP_INICIAL_SALIR:
                continuar = 0;
                break;
        }
    }

    limpiarPantalla();
    printf("\n¡Hasta el próximo viaje!\n\n");

    return 0;
}
