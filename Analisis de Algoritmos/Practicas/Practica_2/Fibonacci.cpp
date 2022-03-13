#include <iostream>

/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
Análisis de Algoritmos
GRUPO: 3CV12
ALUMNOS:
    Jimenez Martinez Hugo Adi
    Castillo González Bruno
PROFESOR: Luna Benoso Benjamín
FECHA: 14/Marzo/2022
*/

using namespace std;

int fibonacci_Recursivo(int n,int *ct){
    if(n<=1){
        (*ct)++; //Sentencia if es verdadera
        (*ct)++; //Sentencia return
        return n; 
    }
    else{
        (*ct)++; //Sentencia if es falsa
        (*ct)++; //Sentencia return
        (*ct)++; //Operacion de suma
        return fibonacci_Recursivo((n-1),ct) + fibonacci_Recursivo((n-2),ct);
    }
}

void fibonacci_Iterativo(int n, int *ct){
    int siguiente = 1; (*ct)++; //Declaracion y asignacion de variable
    int actual = 0; (*ct)++; //Declaracion y asignacion de variable
    int aux = 0; (*ct)++; //Declaracion y asignacion de variable
    (*ct)++; //Declaracion y asignacion de variable i = 0
    for(int i=1;i<=n;i++){
        (*ct)++; //Comparacion del for
        aux = actual; (*ct)++; //Asignacion de valor
        actual = siguiente; (*ct)++; //Asignacion de valor
        siguiente = siguiente + aux; (*ct)++; //Asignacion de valor
        (*ct)++; //Incremento de i
    }
    (*ct)++; //Comparacion falsa del for
}

int main(){
    int num_Ordenadas;
    cin>>num_Ordenadas;
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("Fibonacci.csv","w+"); //Invocamos el archivo csv y lo asignamos a nuestro ftp
    for(int i=1;i<num_Ordenadas;i++){
        int ct=0;
        fibonacci_Iterativo(i,&ct);
        fprintf(fpt,"%d,%d \n",i,ct); //Imprimimos los resultados en el archivo csv
    }
    fclose(fpt); //Cerramos el archivo css
    return 0;
}