#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// prototipos de funciones

void mostrarSeparador(void);

void abrirMenuPrincipal(void);
void abrirMenuSimulacion(int *continuar);
void mostrarInformacion(void);

int leerOpcion(int min, int max);
OpcionInicial pedirOpcionInicial(void);

// funciones de presentación

void mostrarSeparador(void){
    printf("\n----------------------------------\n");
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
    printf("\nINFORMACIÓN DE SIMULACIÓN:\n");
    printf("aceleración del tramo A: 20 m/s^2\n");
    printf("tiempo de desprendimiento: 120 segundos\n");
    printf("aceleración del tramo B: 12,5 m/s^2\n");
}

// menú de simulación

void abrirMenuSimulacion(int *continuar){

    OpcionSimulacion opcion;
    int volver;

    volver = 0;

    while (*continuar && !volver){
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
                // iniciarSimulacion(MODO_ESTANDAR);
                break;
            case OP_SIMULACION_PERSONALIZADA:
                printf("\nIniciando simulación personalizada...\n");
                // iniciarSimulacion(MODO_PERSONALIZADO);
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

// proceso principal

int main(){
    OpcionInicial opcion;

    int continuar = 1;

    printf("\nBIENVENIDO AL SIMULADOR ARTEMIS\n");

    while (continuar){
        opcion = pedirOpcionInicial();

        switch (opcion){
            case OP_INICIAL_SIMULACION:
                abrirMenuSimulacion(&continuar);
                break;
            case OP_MOSTRAR_INFORMACION:
                mostrarInformacion();
                break;
            case OP_INICIAL_SALIR:
                continuar = 0;
                break;
        }
    }

    printf("\n¡Hasta el próximo viaje!\n");

    return 0;
}
