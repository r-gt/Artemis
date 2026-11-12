#include <stdio.h>

#include "validaciones.h"
#include "simulacion.h"
#include "artemis.h"

int main(){


    for(;;){ // bucle hasta que el usuario corta la ejecución (ctrl+c, ctrl+z o eligiendo 3)

        int choice=-1;

        printf("\n----------------\n");

        while(choice==-1){

            choice = get_uint("elejir opción:\n 1. simulación\n 2. detalles\n 3. salir \n\nElección");

        }

        switch(choice){

            case 1:

                int custom = get_uint("Valores de la simulación\n 1. simulación estandar      (valores del problema)\n 2. simulación personalizada (valores personalizados)\n 3. salir\n\nElección");

                if(custom > 2 || custom == -1) return 0;
                simulacion(custom);

                break;

            case 2: printf("     Durante el despegue desde el Centro Espacial Kennedy, el cohete Space Launch System (SLS) eleva a la nave Orion partiendo del reposo (v₀=0,0m/s) en la plataforma de lanzamiento (y₀=0,0m). En la primera fase de ascenso vertical rectilíneo, el cohete acelera hacia arriba con una aceleración constante de a₁=20,0m/s² impulsado por los motores principales y los dos cohetes de combustible sólido (SRB). A los t₁=120,0s (2,00min) de vuelo, los cohetes SRB agotados se desacoplan limpiamente. A partir de ese instante, el motor del núcleo principal continúa acelerando la nave a a₂=12,5m/s² hasta alcanzar una altitud de h=160,0 km (160.000,0 m), donde los motores se apagan. Se desprecia la resistencia del aire en la alta atmósfera.\n"); break;

            default: printf("\nHasta luego!\n"); return 0; break;

        }
    }

    return 0;
}
