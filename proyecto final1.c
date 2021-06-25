//Lizeth Avendaño Garcia
//Este programa funciona como inventario de una tienda de abarrotes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALTO 30 //cantidad de productos máximos en almacen

struct INVENTARIO  //estructura de los datos de los productos
{
	char producto[25];
	float precio;
	int codigo;
};

//Funciones con paso de parámetros
void capturar(struct INVENTARIO inv[], int i);
void mostrar(struct INVENTARIO inv[],int capt);
int buscar(struct INVENTARIO inv[], char buscar_nom[25],int capt, int encontrado);
void modificar(struct INVENTARIO inv[]);
int eliminar(struct INVENTARIO inv[],int capt);

int main(int argc, char *argv[]) { //funcion principal
	
	struct INVENTARIO prod[ALTO];
	int opcion,captura=0,indice=0,i,encontrado,modifica,num_mod;
	char buscar_nombre[25];
	
	do{
		printf("=======================\n");
		printf("     Seleccione:\n    1.Capturar\n    2.Mostrar\n    3.Buscar\n    4.Modificar\n    5.Eliminar\n    6.Salir\n");
		printf("=======================\n");
		scanf("%d",&opcion);
		system("cls"); //limpia la pantalla
		switch(opcion) //casos segun el menu
		{
		 case 1:if (captura==ALTO)
				   	{
				   		printf("\nBASE DE DATOS LLENA!\n"); //mostrar mensaje que se ha llegado al maximo de capturas
					}
					
				else
					{
						capturar(prod,indice); //iniciar la captura llamando a la funcion con paso de parámetros
						indice++; //contador 
				   		captura++; //mientras incrementa podremos saber cuando llega al maximo de capturas
				   }
				break;
		 case 2:if (captura==0) //quiere decir que no hay capturas
		 			{
		 				printf("No hay registros capturados \n");
		 				break;
					 }
		 		mostrar(prod, captura); //llamada a la funcion 
				break;
		 case 3:if (captura==0)
		 			{
		 				printf("No hay registros capturados \n");
		 				break;
					 }
		 		printf("Ingrese el nombre de un producto a buscar: ");
		 		scanf("%s",&buscar_nombre);
		 		encontrado=0; 
		 		encontrado=buscar(prod,buscar_nombre,captura,encontrado); //si se encontró se llama a la función 
         		if(encontrado==0)
         		{
         			printf("No se hallaron coincidencias\n");
				 }
				break;
		 case 4:if (captura==0)
		 			{
		 				printf("No hay registros capturados \n");
		 				break;
					 }
		 		printf("Ingrese un producto a buscar: ");
		 		scanf("%s",&buscar_nombre);
		 		encontrado=0;
		 		encontrado=buscar(prod,buscar_nombre,captura,encontrado); //se llama a la funcion buscar, para saber si esta en existencia el producto ingresado
				if(encontrado==0)
				 	printf("No se hallaron coincidencias\n");
				if(encontrado==1)
				{
					modificar(prod); //si la variable retorna  1, sí existe el producto y se llama a la funcion modificar 
					printf("Datos actualizados: \n");
					mostrar(prod,captura); //llamada a la funcion para mostrar datos actualizados
				}
				break;
		 case 5:if (captura==0)
		 			{
		 				printf("No hay registros capturados \n");
		 				break;
					 }
		 		printf("Ingrese el producto a eliminar: ");
		 		scanf("%s",&buscar_nombre);
		 		encontrado=0;
		 		encontrado=buscar(prod,buscar_nombre,captura,encontrado); //llamada a la funcion
				if(encontrado==0)
				 	printf("No se hallaron coincidencias\n");
				if(encontrado==1)
				{
					captura=eliminar(prod,captura); //se iguala con la variable captura y se llama a la funcion para eliminar
					indice=captura; 
					printf("Datos actualizados: \n");
					mostrar(prod,captura); //llamada a la funcion para mostrar los datos actualizados	
		 	    }
		         break;
		 case 6:break;
		 default:printf("Opcion no valida, intentelo nuevamente\n");
		}
	} while(opcion != 6);
	
	system("PAUSE");
	return 0;
}

void capturar(struct INVENTARIO inv[], int i2)
{
	printf("Ingrese el nombre del producto: ");	//Ingresar datos en la estructura
	scanf("%s",inv[i2].producto);	
	printf("Ingrese el precio: $");	
	scanf("%f",&inv[i2].precio);
	fflush(stdin);
	printf("Ingrese el codigo: ");	
	scanf("%i",&inv[i2].codigo);
}

void mostrar(struct INVENTARIO inv[],int capt)
{
	int i;
	for(i=0;i<capt;i++)
		printf("Producto: %s | Precio: $%.2f | Codigo: %i\n",inv[i].producto,inv[i].precio,inv[i].codigo); //se muestran los datos capturados
}

int buscar(struct INVENTARIO inv[], char buscar_nom[25],int capt, int encontrado)
{	
	int i;
	for(i=0;i<capt;i++)
		{
		 	if (strcmp(buscar_nom,inv[i].producto)==0) //busca la coincidencia en la cadena de caracteres con strcmp
		 		{
		 			printf("[%i] Producto: %s | Precio: $%.2f | Codigo: %i\n",i+1,inv[i].producto,inv[i].precio,inv[i].codigo);
		 			encontrado=1; //toma el valor de 1 si son iguales
				}
		}
	return encontrado;	//se retorna la variable para usarla en la funcion principal
}

void modificar(struct INVENTARIO inv[])
{
	int num_mod,modifica;
	printf("Seleccione el indice del producto que desea modificar[?]: "); //de los productos existentes se pide seleccionar uno 
	scanf("%i",&num_mod);
	printf("Seleccione lo que desea modificar del producto:\n1)Nombre\n2)Precio\n3)Codigo\n"); //se muestra lo que se puede modificar de la estructura
	scanf("%i",&modifica);
	switch(modifica) //segun la opcion los siguientes casos:
		{
			case 1:printf("Ingrese el nuevo nombre del producto : ");
			       scanf("%s",inv[num_mod-1].producto); //se lee y se modifica en el arreglo que contiene esos datos
			       break;
			case 2:printf("Ingrese el nuevo precio : $");
				   scanf("%f",&inv[num_mod-1].precio);
			       break;
			case 3:printf("Ingrese el nuevo codigo : ");
				   scanf("%i",&inv[num_mod-1].codigo);
			       break;
			
			default:printf("Opcion no valida \n");
		}
	
}

int eliminar(struct INVENTARIO inv[],int capt)
{
	int num_mod,i;
	printf("Seleccione el indice del producto que desea eliminar?[?]: ");
	scanf("%i",&num_mod);
	for(i=num_mod-1;i<capt;i++)
		{
			strcpy(inv[i].producto,inv[i+1].producto); //para asignar una cadena se utiliza strcpy
			inv[i].precio=inv[i+1].precio;
			inv[i].codigo=inv[i+1].codigo;
		}
	return capt=capt-1; //se decrementa la variable que se retorna utilizada en la funcion principal para el conteo de las capturas, por lo tanto restarla cuando se ejecute.
}


