#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "validaciones.h"
#include "simulacion.h"
#include "artemis.h"

int main(){

    int choice=-1;

    while(choice==-1){
         choice = get_uint("elejir opción:\n 1. simulación\n 2. detalles\n 3. salir \n\nElección");

    }

    switch(choice){

        case 1:

            int custom = get_uint("Valores de la simulación\n 1. simulación estandar      (valores del problema)\n 2. simulación personalizada (valores personalizados)\n 3. salir\n\nElección");

            if(custom > 2 || custom == -1) return 0;
            simulacion(custom);

            break;

        case 2: printf("se escribirán los datos del simulador\n"); break;

        default: return 0; break;

    }


    return 0;
}
