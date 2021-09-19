#include <stdio.h>
#include <string.h>

struct producto{ char nombre[40]; float precio; int ventas_mes[12]; };

#define CANT_PRODUCTOS 4

void inicializar(struct producto[], int);
void mostrar_ventas_anio(struct producto[], int , char[]);
void mostrar_precio(struct producto[], int);
void mostrar_alfabetico(struct producto[], int);
float calcular_ventas_totales(struct producto[], int);
void mostrar_mas_vendido(struct producto[], int);

int main() {

struct producto ventas[CANT_PRODUCTOS];

float aux = 0.0;

/* PUNTO 1: Inicializar el vector de ventas_mes con ceros, para todos los productos */

 inicializar(ventas, CANT_PRODUCTOS);

/* ahora cargo algunos productos para poder trabajar, no modificar esto */

strcpy(ventas[0].nombre, "Arandela");
ventas[0].precio = 1.5;
ventas[0].ventas_mes[0] = 300; /* cantidad de arandelas vendidas en enero */
ventas[0].ventas_mes[5] = 100; /* cantidad de arandelas vendidas en junio */
ventas[0].ventas_mes[11] = 50; /* cantidad de arandelas vendidas en diciembre */
strcpy(ventas[1].nombre, "Tuerca");
ventas[1].precio = 2.2;
ventas[1].ventas_mes[0] = 200; ventas[1].ventas_mes[5] = 100; ventas[1].ventas_mes[11] = 50;
strcpy(ventas[2].nombre, "Tornillo");
ventas[2].precio = 3.5;
ventas[2].ventas_mes[0] = 400; ventas[2].ventas_mes[5] = 200; ventas[2].ventas_mes[11] = 150;
strcpy(ventas[3].nombre, "Tarugo");
ventas[3].precio = 5.2;
ventas[3].ventas_mes[0] = 500; ventas[3].ventas_mes[5] = 300; ventas[3].ventas_mes[11] = 250;


/* PUNTO 2: Mostrar las ventas que tuvo un producto en todo el año, dado su nombre */
/* Resultado esperado: Tornillo 750 unidades */

mostrar_ventas_anio(ventas, CANT_PRODUCTOS, "Tornillo");

/* PUNTO 3: Mostrar todos los productos en orden decreciente de precio (más caros primero). */
/* Resultado esperado: Tarugo Tornillo Tuerca Arandela */

 mostrar_precio(ventas, CANT_PRODUCTOS);

/* PUNTO 4: Mostrar todos los productos en orden alfabético. */
/* Resultado esperado: Arandela Tarugo Tornillo Tuerca */

 mostrar_alfabetico(ventas, CANT_PRODUCTOS);


/* PUNTO 5: Calcular y retornar el dinero total vendido en el año */
/* Resultado esperado: $ 9530.00 */

 aux = calcular_ventas_totales(ventas, CANT_PRODUCTOS);
 printf("$ %.2f", aux);

/* PUNTO 6: Mostrar el nombre del producto más vendido (en cantidad) en el año */
/* Resultado esperado: Tarugo 1050 unidades */


 mostrar_mas_vendido(ventas, CANT_PRODUCTOS);


}


void inicializar(struct producto venta[], int size){
    int i ,j;
    for(i=0;i<size;i++){
        for(j=0;j<12;j++){
            venta[i].ventas_mes[j]=0;
        }
    }
}

void mostrar_ventas_anio(struct producto ventas[], int size, char valor []){

    int i ,j ,ventasAnio;
    ventasAnio=0;

    for(i=0;i<size;i++){
        if(!strcmpi(ventas[i].nombre,valor)){
            for(j=0;j<12;j++){
            ventasAnio=ventasAnio+ventas[i].ventas_mes[j];
            }
           printf("%s %d unidades\n" , valor ,ventasAnio);
           return;
        }
    }
     printf("No se encuentra el producto: %s " , valor);
}

void mostrar_precio(struct producto ventas[], int size){
    int i , j;
    struct producto aux;

    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(ventas[i].precio<ventas[j].precio){
                aux = ventas[i];
                ventas[i]=ventas[j];
                ventas[j]=aux;
            }
        }
    }
    printf("\n");
    for(i=0;i<size;i++){
        printf("%s  ",ventas[i].nombre,ventas[i].precio);
    }
}



void mostrar_alfabetico(struct producto ventas[], int size){
    int i , j;
    struct producto aux;

    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(strcmpi(ventas[i].nombre,ventas[j].nombre)>0){
                aux = ventas[i];
                ventas[i]=ventas[j];
                ventas[j]=aux;
            }
        }
    }
    printf("\n\n");
    for(i=0;i<size;i++){
        printf("%s  ",ventas[i].nombre,ventas[i].precio);
    }
    printf("\n\n");
}

float calcular_ventas_totales(struct producto ventas[], int size){
    float ventasanio= 0.0;
    int i,j;

    for(i=0;i<size;i++){
        for(j=0;j<12;j++){
            ventasanio=ventasanio+(ventas[i].precio * ventas[i].ventas_mes[j]);
        }
    }
    return ventasanio;
}


void mostrar_mas_vendido(struct producto ventas[], int size){
    int i,j,posmax,cont1,contMax;
    contMax=0;
    posmax=0;
    struct producto aux;
    for(i=0;i<size;i++){
        cont1=0;
        for(j=0;j<12;j++){
        cont1= cont1 + ventas[i].ventas_mes[j];
        }
        if(cont1>contMax){
            posmax=i;
            contMax=cont1;
        }
    }
    printf("\n\n%s %d unidades \n",ventas[posmax].nombre,contMax);
}

