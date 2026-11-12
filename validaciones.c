#include "validaciones.h"


#include <stdio.h>
#include <stdlib.h>

// las funciones reciben un string de entrada.
// entonces podemos recibir comandos además de solo numeros




int get_uint(char* label){

	char input[16];

	printf("\n%s: ", label);
	scanf("%15s", input); // hay que dejar un espacio para el final del string "\0"


	for (int i = 0; input[i]; i++) {



		if ( !(input[i] >= '0' && input[i] <= '9')  || (input[i]==',' || input[i]=='.') || input[i]==EOF) {

			printf("entrada invalida\n");
			return -1;

		}
	}

    return atoi(input);

}


float get_ufloat(char* label){

	char input[32];

	printf("\n%s: ", label);
	scanf("%31s", input); // hay que dejar un espacio para el final del string "\0"

	char comma = 0; // usado para ver si hay mas de una coma flotante

	for (int i = 0; input[i]; i++) {

		if(input[i]==',') input[i]='.';

		if(input[i]=='.') comma++;

		if (
			  (!(input[i] >= '0' && input[i] <= '9') &&
			   !(input[i]=='.' && comma < 2))
			   || input[i]==EOF
		) {

			printf("entrada invalida \n");
			return -1.0;

		}
	}

	return atof(input);

}

