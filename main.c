#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

void update_olderThan(int, FILE *);

void loadMtx(int [][5]);

int main()
{
    int v[2][5] = {
        {1,1,1,1,1},{1,1,1,1,1}
    };
    loadMtx(v);
    printf("v 1 1 %d",v[1][2]);

    //FILE * f = fopen("personas_data","r+b");
    //update_olderThan(0,f);
}

void loadMtx(int v [][5]){
    v[1][2]=3;

}


void update_olderThan(int e, FILE * f){

    tpersona d;
    fread(&d,sizeof(tpersona),1,f);
    while(!feof(f)){
        if(d.edad>e){
            d.edad += 100;
            fseek(f,sizeof(tpersona)*(-1),SEEK_CUR);
            fread(&d,sizeof(tpersona),1,f);
            //fwrite(&d,sizeof(tpersona),1,f);
            persona_show(&d,stdout,0);
        }
        fread(&d,sizeof(tpersona),1,f);
    }

}
