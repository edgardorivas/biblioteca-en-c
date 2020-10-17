#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Z 30

	
typedef struct {
	
	char nombre[Z];
	char autor_libro[Z];
	int lleno_libro;
	
}libro;

typedef struct{
	
	char nombre_bi[Z];
	libro  lib [10];
	int lleno_bi;
}biblioteca;

biblioteca bi[3];

void anadebi();
void vacio(); 
void cambio(char palabra[Z]);
void anadelib();
void consulta();

int main () {
	int op;
	char i;
	
	vacio();
	
do{
	do{	
	printf("\n\t\t\t\t menu princupal \t");
	printf("\n\t\t\t\t---------------\t\n");
	printf("\n (1) añadir una nueva biblioteca \t ");
	printf(" (2)añadir uun libro en una biblioteca ");
	printf("(3) cunsultar un libro");
	scanf("%i",&op);
	switch (op) {
		case 1:
			anadebi();
		break;
		case 2:
			anadelib();
		break;	
		case 3:
		  consulta();
		break;
	}
	} while(op<1 || op>3 );
	
	system("cls");
	printf("necesita hacer algo mas(s/n):");
	fflush(stdin);
	scanf("%c",&i);

}	while(i=='s'|| i=='S');
	
	system("pause");
	return 0;
}

void vacio() {
	
	int i,j;
		
	for(i=0; i<3; i++){
		bi[i].lleno_bi=0;
		
		for(j=0; j<10; j++){
			bi[i].lib[j].lleno_libro=0;
		}
		
	}
}

	void cambio(char palabra[Z]){
		
		int i;
		
		for(i=0; i<Z; i++){
			
			if(palabra[i]=='\n'){
				palabra[i]='\0';
			}
		}
	}
void anadebi() {
	
	int i,aux;
	
	aux=0;
	
	for(i=0; i<3 && aux==0; i++) {
		
		if(bi[i].lleno_bi==0) {
			
			printf("introduce un nombre para la biblioteca");
			fflush(stdin);
			fgets(bi[i].nombre_bi,Z,stdin);
			cambio(bi[i].nombre_bi);
			
			bi[i].lleno_bi=1;
			aux=1;
		}	
		
	}
	
	if(aux==0){
		
		printf("no queda ningun hueco para meter una nueva biblioteca");
		
	}
}

void anadelib() {
	
	int i,op,aux;
	aux=0;
	
	for(i=0; i<=3; i++) {
	 
	  if(bi[i].lleno_bi==1){
	  	
	  	printf("(%i)%s.\n",i,bi[i].nombre_bi);
	  }
	scanf("%i",&op);
	
	for(i=0; i<10 && aux==0; i++){
		
		if(bi[op].lib[i].lleno_libro == 0) {
			
			printf("introduce el nombre del libro.");
			fflush(stdin);
			fgets(bi[op].lib[i].nombre,Z,stdin);
			cambio(bi[op].lib[i].nombre);
			
			printf("introduce el nombre del autor.");
			fflush(stdin);
			fgets(bi[op].lib[i].autor_libro,Z,stdin);
			cambio(bi[op].lib[i].autor_libro);
			
			bi[op].lib[i].lleno_libro=1;
			aux=1;
		}
		
	 }
  }
	
}
void consulta() {
	
	int op,i,j,aux;
	char buscar[Z];
	
	aux=1;
	
	do{
	
	printf("que quieres buscar nombre del libro o nombre del autor.");
	printf("(1) nombre del libro.\n");
	printf("(2) nombre del autor. \n");
	scanf("%i",&op);
		
	}while(op<1 || op>2);
	
	switch (op) {
		
		case 1:
			printf("introduce el nombre del libro:");
			fflush(stdin);
			fgets(buscar,Z,stdin);
			cambio(buscar);
		for(i=0; i<3; i++){
			aux=1;
			for(j=0; j<10; j++){
				
				aux=strcmp(buscar,bi[i].lib[j].nombre);
				if(aux==0){
					
					printf("el libro %s, se encuentra en la biblioteca %s.",buscar,bi[i].nombre_bi);
					printf("el autor del libro es: %s.",bi[i].lib[j].autor_libro);
				}
			}
		}
		break;
		
		case 2: 
			printf("introduce el nombre del autor:");
			fflush(stdin);
			fgets(buscar,Z,stdin);
			cambio(buscar);
		for(i=0; i<3; i++){
			aux=1;
			for(j=0; j<10; j++){
				
				aux= strcmp(buscar,bi[i].lib[j].autor_libro);
				if(aux==0){
					
					printf("el libro %s, se encuentra en la biblioteca %s.",bi[i].lib[j].nombre,bi[i].nombre_bi);
					printf("el autor del libro es: %s.",bi[i].lib[j].autor_libro);
				}
			}
		}
		break;
	}
	
}
