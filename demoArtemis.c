#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "artemis.h"
#include <math.h>

int simulacion(){
    float h_final_B;
    float acb;
    int st = 0;

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO A < ---\n");
    printf("=================================================================\n");

    vel = get_ufloat("Ingrese la velocidad inicial (m/s) ->");
    posi = get_ufloat("Ingrese la posicion inicial (m) ->");
    ac = get_ufloat("Ingrese la aceleracion constante (m/s^2) ->");
    ti = get_uint("Ingrese el tiempo inicial (s) ->");
    tf = get_uint("Ingrese el tiempo final (s) ->");
    
    while (st == 0 || st == -1.0) {  
        st = get_uint("Ingrese el paso temporal (s) ->");
        if (st == 0) printf("\nPorfavor, ingrese un valor entero distinto de 0\n");
    }
    
    
    printf("\n=================================================================\n");
    printf("%-10s | %-15s | %-15s | %-10s\n", "Tiempo (s)", "Velocidad (m/s)", "Altura (m)", "Fuerza (G)");
    printf("=================================================================\n");

    for (int t = ti; t <= tf; t += st){
        float v_actual = rapidez(vel, ac, t);
        float h_actual = altura(posi, vel, ac, t);
        float g_actual = rapidezG(ac);

        printf("%-10d | %-15.2f | %-15.2f | %-10.2f\n", t, v_actual, h_actual, g_actual);
    }
    
    printf("=================================================================\n");

    float v_final_A = rapidez(vel, ac, tf);
    float h_final_A = altura(posi, vel, ac, tf);

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO B < ---\n");
    printf("=================================================================\n");
    
    printf("Ingrese la altura alcanzada por la nave (m) -> ");
    scanf("%f", &h_final_B);
    printf("Ingrese la aceleracion constante del motor principal (m/s^2) -> ");
    scanf("%f", &acb);
    
    float incrementoH = h_final_B - h_final_A; 
    
    float v_final_B = rapidez_tramo2(v_final_A, acb, incrementoH);

    printf("\n=================================================================\n");
    printf("Estado al iniciar Tramo B: Altura = %.2f m | Velocidad = %.2f m/s\n", h_final_A, v_final_A);
    printf("Desplazamiento en Tramo B (Delta Y): %.2f m\n", incrementoH);
    printf("La velocidad alcanzada en la posicion final es de: %.2f m/s\n", v_final_B);
    printf("=================================================================\n\n");
    
    float v_inicial_C = v_final_B;
    float h_inicial_C = h_final_B;

    printf("\n=================================================================\n");
    printf("                       --- > TRAMO C < ---\n");
    printf("=================================================================\n");
    
    printf("\n=================================================================\n");
    printf("Los motores del cohete empezaron a fallar (!!!)\n");
    
    float h_max = altura_max(v_inicial_C, h_inicial_C);
    printf("Altura maxima alcazada por el cohete luego de la falla: %f m", h_max);
    printf("\n=================================================================\n");    
    return 0;
}