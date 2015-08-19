#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct informacion{
char nombre[20];
char apellido[20];
char carrera[20];
int codigo;
int edad;
int estado;
float papa;
char sexo;
};

void cargar(struct informacion *estudiante){
strcpy(estudiante->nombre,"Daniel");
strcpy(estudiante->apellido,"Moncada");
strcpy(estudiante->carrera,"ing. sistemas");
estudiante->codigo=25768;
estudiante->edad=26;
estudiante->estado=1;
estudiante->papa=3.7;
estudiante->sexo='m';
}

void mostrar(struct informacion *estudiante) {
printf("nombre: %s\n", estudiante->nombre);
printf("apellido: %s\n", estudiante->apellido);
printf("carrera: %s\n", estudiante->carrera);
printf("codigo: %d\n", estudiante->codigo);
printf("edad: %d\n", estudiante->edad);
printf("estado: %d\n", estudiante->estado);
printf("papa: %f\n", estudiante->papa);
printf("sexo: %c\n", estudiante->sexo);
}

void guardar(struct informacion *estudiante){
size_t r;
FILE* ap;
ap=fopen("datos.txt","w+");
if(ap==NULL){
	perror("Error al leer archivo");
	exit(-1);
	}
r=fwrite(estudiante,sizeof(struct informacion),1,ap);
if(r!=10){
	perror("error datos");
	exit(-1);
	}
r=fclose(ap);
if(r!=0){
	perror("error al cerrar archivo");
	exit(-1);
	}
}

int main(){
struct informacion *estudiante;
estudiante=malloc(sizeof(*estudiante));
cargar(estudiante);
mostrar(estudiante);
guardar(estudiante);
free(estudiante);
fflush(stdout);
return 0;
}
