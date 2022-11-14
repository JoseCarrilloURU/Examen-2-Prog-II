#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Examen #2 de Programacion II. Jose Carrillo

struct datos{
	
char nombre[20];	
int cedula;
float saldo;	
float ganancias;
float saldobs, gananciasbs;	
	
}clientes[4];

void Menu();
void IngresarDatos();
void MostrarDatos();
void Buscador();
void Ganancias();
void Conversion();
void Salir();

int e, n; //Error, numero de clientes

int main(){
	
Menu();
	
return 0;
};

void IngresarDatos(){

if (n<4){

	
fflush (stdin);
printf ("Ingrese el nombre del cliente #%d: ", n+1);
scanf ("%s", &clientes[n].nombre);	

do{	
printf ("Ingrese el numero de cedula del cliente #%d: ", n+1);
scanf ("%d", &clientes[n].cedula);

if (clientes[n].cedula<5000000 || clientes[n].cedula>35000000){
printf ("\nValor no dentro del rango determinado. \n\nPulse una tecla para continuar...\n\n");
getch();
e = 1;		
}else{
e = 0;	
}
}while (e==1);	

do{	
printf ("Ingrese el saldo actual del cliente #%d : $", n+1);
scanf ("%f", &clientes[n].saldo);	
if (clientes[n].saldo<=0){
printf ("\nValor no disponible. \n\nPulse una tecla para continuar...\n\n");
getch();
e = 1;		
}else{
e = 0;	
clientes[n].ganancias = clientes[n].saldo * 0.01;
printf ("\nDatos del cliente guardados correctamente.\nPulse una tecla para continuar...\n\n");
getch();
}
}while (e==1);
fflush (stdin);
	
n++;	

}else{

printf ("Se ha alcanzado el maximo permitido de clientes. \n\nPulse una tecla para continuar...\n\n");
getch();	
}

}

void MostrarDatos(){

if(n!=0){
	
printf ("Mostrando los datos de los clientes:");
for (int i=0; i<n; i++){
printf("\n");
printf("Cliente #%d: \n\n", i+1);
printf ("Nombre: %s\n", clientes[i].nombre);
printf ("Numero de Cedula: %d\n", clientes[i].cedula);	
printf ("Saldo disponible: $%.2f\n", clientes[i].saldo);
}

printf ("\n\nPulse una tecla para continuar...\n\n");
getch();		
	
}else{

printf ("No se han ingresado los datos de ningun cliente. \n\nPulse una tecla para continuar...\n\n");
getch();
	
}	
}

void Buscador(){

int cedula, v=0; // Verdadero	
	
if(n!=0){	
	
printf("\n");
printf ("Ingrese la cedula a buscar: ");
scanf ("%d", &cedula);
for (int i=0; i<n; i++){
if (clientes[i].cedula==cedula){
v = 1;	
printf("\n\n");
printf ("Cliente #%d: \n", i+1);
printf ("Nombre: %s\n", clientes[i].nombre);
printf ("Edad: %d\n", clientes[i].cedula);
printf ("Saldo disponible: $%.2f\n", clientes[i].saldo);
printf ("\n\nPulse una tecla para continuar...");	
getch();
}	

}

if(v==0){
printf ("No existen clientes en el sistema con el numero de cedula: %d", cedula);	
printf ("\n\nPulse una tecla para continuar...\n\n");	
getch();
}	

}else{

printf ("No se han ingresado los datos de ningun cliente. \n\nPulse una tecla para continuar...\n\n");
getch();
	
}	
	
}

void Ganancias(){
	
if(n!=0){

for (int i=0; i<n; i++){

printf("\n");
printf("Cliente #%d: \n\n", i+1);
printf ("Nombre: %s\n", clientes[i].nombre);
printf ("Saldo disponible: $%.2f\n", clientes[i].saldo);
printf ("Ganancias mensuales del banco por la cuenta: $%.2f\n", clientes[i].ganancias);
}
printf ("\n\nPulse una tecla para continuar...\n\n");	
getch();

}else{

printf ("No se han ingresado los datos de ningun cliente. \n\nPulse una tecla para continuar...\n\n");
getch();
}	

}

void Conversion(){

if(n!=0){

for (int i=0; i<n; i++){

clientes[i].saldobs = clientes[i].saldo * 8.75;
clientes[i].gananciasbs = clientes[i].ganancias * 8.75;

printf("\n");
printf("Cliente #%d: \n\n", i+1);
printf ("Nombre: %s\n", clientes[i].nombre);
printf ("Saldo disponible en Bolivares: Bs. %.2f\n", clientes[i].saldobs);
printf ("Ganancias mensuales del banco en Bolivares: Bs. %.2f\n", clientes[i].gananciasbs);
}
printf ("\n\nPulse una tecla para continuar...\n\n");	
getch();

}else{

printf ("No se han ingresado los datos de ningun cliente. \n\nPulse una tecla para continuar...\n\n");
getch();
}	

}

void Salir(){
system ("cls");
printf ("Hasta luego!");
}

void Menu(){
int opc;
do{
system ("cls");	
printf("Bienvenido a la Base de Datos del Banco:\n\n");
printf ("Menu de opciones\n");
printf ("1. Ingresar datos de los clientes\n");
printf ("2. Mostrar datos de todos los clientes\n");
printf ("3. Buscar un cliente por su Numero de Cedula\n");
printf ("4. Calculo de Ganancias del Banco\n");
printf ("5. Conversion a Bolivares de Saldos y Ganancias\n");
printf ("6. Salir del sistema\n\n");
printf ("Seleccione una opcion: ");
scanf ("%d", &opc);
printf ("\n");
	
switch(opc){
case 1: IngresarDatos(); break;
case 2: MostrarDatos(); break;
case 3: Buscador(); break;	
case 4: Ganancias(); break;
case 5: Conversion(); break;
case 6: Salir(); break;
default: printf ("Su valor no corresponde a ninguna opcion.\n\nPulse una tecla para continuar...\n\n");	
getch(); break;
	
}
	
}while(opc!=6);
	
	
}

