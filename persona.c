#include "persona.h"

tpersona persona_get(){
	tpersona p;
	printf("+Nueva persona:\n");
	printf("___ Nombre:");
	fgets(p.nombre,sizeof(p.nombre),stdin);
	eliminar_caracter(p.nombre,'\n');
	printf("___ DNI   :");
	scanf("%d",&p.dni);
	printf("___ Legajo:");
	scanf("%d",&p.legajo);
	printf("___ Edad  :");
	scanf("%d",&p.edad);
	FLUSH()
	return p;
}


void persona_show(const tpersona * p ,FILE * fp, int bin){
    if(!bin)
        fprintf(fp,"%-20.20s %.8d %.6d %-3d\n",p->nombre,p->dni,p->legajo,p->edad);
    else
        fwrite(p,sizeof(tpersona),1,fp);
}

int persona_compare(const tpersona * p1,const tpersona * p2){
    if( p1->dni == p2->dni)
        return 0;
    if(p1->dni > p2->dni)
        return 1;
    return -1;
}

void persona_load_txt(const char * s, tpersona * p){
    char tmp[15];
    strncpy(p->nombre,s,sizeof(p->nombre));
    strncpy(tmp,s+21,8);
    sscanf(tmp,"%d",&p->dni);
    tmp[8]='\n';
    strncpy(tmp,s+30,6);
    tmp[6]='\n';
    sscanf(tmp,"%d",&p->legajo);
    strncpy(tmp,s+37,3);
    tmp[3]='\n';
    sscanf(tmp,"%d",&p->edad);
}
