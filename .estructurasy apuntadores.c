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



int main(){

	struct informacion *estudiante;
	estudiante=malloc(sizeof(*estudiante));
	cargar(estudiante);
	mostrar(estudiante);
	free(estudiante);
	fflush(stdout);
	return 0;
}
