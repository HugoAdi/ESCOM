#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
Análisis de Algoritmos
GRUPO: 3CV12
ALUMNOS:
    Jimenez Martinez Hugo Adi
    Castillo Gonzalez Bruno
PROFESOR: Luna Benoso Benjamín
FECHA: 28/Febrero/2022
*/

int MCD(int a, int b, int *ct){
    int aux;
    while(b != 0){
        (*ct)++; //Comparacion con resultado verdadero del while
        aux = b; (*ct)++; //Asignacion a nuestra variable auxiliar
        b= a % b; (*ct)++; //Operacion modulo
        a = aux; (*ct)++; //Asignacion a nuestro valor a
    }
    (*ct)++; //Comparacion con resultado negativo del while
    (*ct)++; //Return de la funcion
    return a;
}

int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    int num_ordenadas, i, ct, mcd;
    num_ordenadas = 40;
    ct = 0;
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("posteriori_MCD.csv","w+"); //Invocamos el archivo csv y lo asignamos a nuestro ftp
    for(i=0;i<num_ordenadas;i++){
        mcd = MCD(fib(i),fib(i+1),&ct); //Buscamos el MCD con el peor caso, el cual son los numeros consecutivos de fibonacci
        //mcd = MCD(i,i,&ct); //Buscamos el MCD para el mejor caso, que es donde a = b
        //printf("El MCD de %d y %d es: %d  \n",fib(i),fib(i+1),mcd); //Imprimimos en consola el resultado
        fprintf(fpt,"%d,%d \n",i,ct); //Imprimimos los resultados en el archivo csv
    }
    fclose(fpt); //Cerramos el archivo
    return 0;
}
