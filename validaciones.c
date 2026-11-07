#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>

// las funciones reciben un string de entrada.





int get_int(char* label, int def){

	char input[16];

	printf("\n%s: ", label);
	scanf("%15s", input); // hay que dejar un espacio para el final del string "\0"

	for (int i = 0; input[i]; i++) {

			if(input[i]==',' || input[i]=='.') break;

		if (!(input[i] >= '0' && input[i] <= '9') && !(i == 0 && input[i] == '-')) {

			printf("entrada no valida, usando valor por defecto (%d)", def);
			return def;

		}
	}

    return atoi(input);

}


float get_float(char* label, float def){

	char input[32];

	printf("\n%s: ", label);
	scanf("%31s", input); // hay que dejar un espacio para el final del string "\0"

	char comma = 0; // usado para ver si hay mas de una coma flotante

	for (int i = 0; input[i]; i++) {

		_Bool comma_verif = input[i]==',' || input[i]=='.';

		if(comma_verif) comma++;

		if (
			( !(input[i] >= '0' && input[i] <= '9') &&
			  !(i == 0 && input[i] == '-') ) &&
			  !(comma_verif && comma < 2)
		) {

			printf("entrada no valida, usando valor por defecto (%.3f)", def);
			return def;

		}
	}

	return atof(input);

}

