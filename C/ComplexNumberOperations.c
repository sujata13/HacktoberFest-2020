#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

//Declaración de la estructura

typedef struct {
	float real;
	float imga;
	
}num_Complejo;

//Esta función regresa una estructura referente a num_Complejo
num_Complejo* Captura_numComplejo();

//Declaración de los prototipos a manera de apuntadores 
void muestra_numComplejo(num_Complejo *w);

num_Complejo* sumaComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo* restaComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo* producComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo* diviComplejo (num_Complejo *w, num_Complejo *z);

int main (void){
	
	//Las variables serán apuntadores
	num_Complejo *z1, *z2, *r;
	
	//Pedimos ingresar los valores reales e imaginarios
	printf ("\nIngrese el numero z1: ");
	z1 = Captura_numComplejo();
	
	printf ("\nIngrese el numero z2: ");
	z2 = Captura_numComplejo();
	
	//Mostramos los numeros capturados en z1 y z2
	printf ("\nLos numeros capturado son: ");
	muestra_numComplejo(z1);
	printf ("\n");	
	muestra_numComplejo(z2);
	
	//Mostrar el resultado de la suma y liberar la memoria
	r = sumaComplejo (z1,z2);
	printf ("\n\nLa suma es:");
	muestra_numComplejo(r);
	free(r);
	
	//Mostrar el resultado de la resta y liberar la memoria
	r = restaComplejo(z1,z2);
	printf("\n\nLa resta es: ");
	muestra_numComplejo(r);
	free(r);
	
	//Mostrar el resultado de la multiplicacion y liberar la memoria
	r = producComplejo(z1,z2);
	printf("\n\nEl producto es: ");
	muestra_numComplejo(r);
	free(r);
	
	//Mostrar el resultado de la división y liberar la memoria
	r = diviComplejo(z1,z2);
	printf("\n\nLa division es: ");
	muestra_numComplejo(r);
	free(r);
	
	//Elimanamos la memoria que ya no volvermos a usar
	free(z1);
	free(z2);
	free(r);
	getchar ();
	return 0;
}

//DivisionComplejo
num_Complejo* diviComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo *divi; //Declaración de nuesta variable en forma de apuntador
	
	//Declarar apuntador para guardar la dirección de memoria
	divi = (num_Complejo *)malloc(sizeof(num_Complejo)); //Cantidad de Bytes que utilizará
	
	//Verificar si se asignó la memoria correctamente 
	if (divi == NULL){
		printf("Error al asignar memoria para el [num_Complejo]\n");
		exit (0);
	}
	
	divi->real= ((w->real * z->real) + (w->imga * z->imga)) / (pow(z->real, 2) + pow(z->imga, 2));
	divi->imga= ((w->imga * z->real) - (w->real * z->imga)) / (pow(z->real, 2) + pow(z->imga, 2));
	
	return divi;
}

//ProductoComplejo
num_Complejo* producComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo *produc; //Declaración de nuesta variable en forma de apuntador
	
	//Declarar apuntador para guardar la dirección de memoria
	produc = (num_Complejo *)malloc(sizeof(num_Complejo)); //Cantidad de Bytes que utilizará
	
	//Verificar si se asignó la memoria correctamente 
	if (produc == NULL){
		printf("Error al asignar memoria para el [num_Complejo]\n");
		exit (0);
	}
	
	produc->real = (w->real * z->real) - (w->imga * z->imga);
	produc->imga = (w->real * z->imga) + (w->imga * z->real);
	
	return produc;
}

//SumaComplejo
num_Complejo* sumaComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo *suma; //Declaración de nuesta variable en forma de apuntador
	
	//Declarar apuntador para guardar la dirección de memoria
	suma = (num_Complejo *)malloc(sizeof(num_Complejo)); //Cantidad de Bytes que utilizará
	
	//Verificar si se asignó la memoria correctamente 
	if (suma == NULL){
		printf("Error al asignar memoria para el [num_Complejo]\n");
		exit (0);
	}
	
	suma->real = w->real + z->real;
	suma->imga = w->imga + z->imga;
	
	return suma;
}

//RestaComplejo
num_Complejo* restaComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo *resta; //Declaración de nuesta variable en forma de apuntador
	
	//Declarar apuntador para guardar la dirección de memoria
	resta = (num_Complejo *)malloc(sizeof(num_Complejo)); //Cantidad de Bytes que utilizará
	
	//Verificar si se asignó la memoria correctamente 
	if (resta == NULL){
		printf("Error al asignar memoria para el [num_Complejo]\n");
		exit (0);
	}
	
	resta->real = w->real - z->real;
	resta->imga = w->imga - z->imga;
	
	return resta;
}

void muestra_numComplejo(num_Complejo *w){
	if (w->imga < 0){
		printf ("\n%2.1f %2.1f i", w->real, w->imga);
	}else{
		printf ("\n%2.1f + %2.1f i", w->real, w->imga);
	}	
}

num_Complejo* Captura_numComplejo(){
	num_Complejo *w; //Declaración de nuesta variable en forma de apuntador
	
	//Declarar apuntador para guardar la dirección de memoria
	w = (num_Complejo *)malloc(sizeof(num_Complejo)); //Cantidad de Bytes que utilizará
	
	//Verificar si se asignó la memoria correctamente 
	if (w == NULL){
		printf("Error al asignar memoria para el [num_Complejo]\n");
		exit (0);
	}
	
	//Apuntador hacia estructura w->real
	printf ("\nReal: ");
	scanf ("%f", &w->real); fflush (stdin);
	
	//Apuntador hacia estructura w->imga
	printf ("Imaginaria: ");
	scanf ("%f", &w->imga); fflush (stdin);
	
	return w;
}

