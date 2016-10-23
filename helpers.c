#include "helpers.h"

void eliminar_caracter(char * cad, char c){

    while((cad = strchr(cad,(int)c)) != NULL){
        strcpy(cad,cad+1);
    }

}
