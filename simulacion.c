#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "artemis.h"
#include "simulacion.h"
#include <math.h>

nave artemis;

int simulacion(int modo){
    artemis.vel = 0.0;
    artemis.posi = 0.0;
    artemis.ac = 20.0;
    double ti = 0;
    double tf = 120;

    double h_final_B = 160000.0;
    double acb = 12.5;

    long int st = 0;

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO A < ---\n");
    printf("=================================================================\n");

    //si el modo es personalizado pregunto todos los parametros
    if (modo == 2){

        artemis.vel  = -1;
        artemis.posi = -1;
        artemis.ac   = -1;
        ti   = -1;
        tf   = -1;

        while(artemis.vel==-1)   artemis.vel  = get_udouble("Ingrese la velocidad inicial (m/s) ->");
        while(artemis.posi==-1)  artemis.posi = get_udouble("Ingrese la posicion inicial (m) ->");
        while(artemis.ac==-1)    artemis.ac   = get_udouble("Ingrese la aceleracion constante (m/s^2) ->");
        while(ti==-1)    ti   = get_ulong("Ingrese el tiempo inicial (s) ->");
        while(tf==-1)    tf   = get_ulong("Ingrese el tiempo final (s) ->");

    }

    while (st == 0 || st == -1.0) {
        st = get_ulong("Ingrese el paso temporal (s) ->");
        if (st == 0) printf("\nPorfavor, ingrese un valor entero distinto de 0\n");
    }

    printf("\n=================================================================\n");
    printf("%-10s | %-15s | %-15s | %-10s\n", "Tiempo (s)", "Velocidad (m/s)", "Altura (m)", "Fuerza (G)");
    printf("=================================================================\n");

    int t;
    for (t = ti; t < tf+st; t += st){

        if(t>tf) t=tf;

        double v_actual = rapidez(artemis.vel, artemis.ac, t);
        double h_actual = altura(artemis.posi, artemis.vel, artemis.ac, t);
        double g_actual = rapidezG(artemis.ac);

        printf("%-10d | %-15.2f | %-15.2f | %-10.2f\n", t, v_actual, h_actual, g_actual);
    }



    printf("=================================================================\n");

    double v_final_A = rapidez(artemis.vel, artemis.ac, tf);
    double h_final_A = altura(artemis.posi, artemis.vel, artemis.ac, tf);

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO B < ---\n");
    printf("=================================================================\n");

    if (modo == 2) {
        h_final_B  = -1;
        acb        = -1;

        while(h_final_B == -1)  h_final_B = get_udouble("Ingrese la altura alcanzada por la nave (m) -> ");
        while(acb == -1)        acb = get_udouble("Ingrese la aceleracion constante del motor principal (m/s^2) -> ");
    }

    double incrementoH = h_final_B - h_final_A;

    double v_final_B = rapidez_tramo2(v_final_A, acb, incrementoH);

    printf("\n=================================================================\n");
    printf("Estado al iniciar Tramo B: Altura = %.2f m | Velocidad = %.2f m/s\n", h_final_A, v_final_A);
    printf("Desplazamiento en Tramo B (Delta Y): %.2f m\n", incrementoH);
    printf("La velocidad alcanzada en la posicion final es de: %.2f m/s\n", v_final_B);
    printf("=================================================================\n\n");

    double v_inicial_C = v_final_B;
    double h_inicial_C = h_final_B;

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO C < ---\n");
    printf("=================================================================\n");

    printf("\n=================================================================\n");
    printf("Los motores del cohete empezaron a fallar (!!!)\n");

    double h_max = altura_max( h_inicial_C, v_inicial_C);
    printf("Altura maxima alcazada por el cohete luego de la falla: %f m", h_max);
    printf("\n=================================================================\n");
    return 0;
}
