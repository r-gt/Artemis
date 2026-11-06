#include "validaciones.h"
#include <stdio.h>

int get_int(char* label){

    int output=0;

    do{
        printf("\n%s: ", label);


    }while(scanf("%d", &output)<1);

    return output;

}
