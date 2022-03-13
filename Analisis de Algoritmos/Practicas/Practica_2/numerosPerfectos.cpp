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

bool Perfecto(int n, int *ct){
    int sumaDividendos = 0; (*ct)++; //Declaracion de sumaDividendos
    int dividendo; (*ct)++; //Declaracion de variable dividendo
    (*ct)++; //Asignacion de i = 1
    for(int i=1;i<n;i++){
        (*ct)++; //Comparacion verdadera del for
        if((n%i)==0) {
            (*ct)++; //Comparacion verdadera del if
            dividendo = i; (*ct)++; //Asignacion de valor
            sumaDividendos += dividendo; (*ct)++; //Sumatoria de dividendo
        }
        (*ct)++; //Incremento de i
    }
    (*ct)++; //Comparacion falsa del for
    (*ct)++; //Return de la funcion
    return sumaDividendos == n;
}

void MostrarPerfectos(int n, int *ct){
    int contador=0; (*ct)++; //Declaracion de contador = 0
    int i = 1; (*ct)++; //Declaracion de contador i
    while(true){
        (*ct)++; //Condicion verdadera de while
        if(contador==n) {
            (*ct)++; //Condicion verdadera del if
            (*ct)++; //Break
            break; 
        }
        if(Perfecto(i,ct)){
            (*ct)++; //Condicion verdadera del if
            (*ct)++; //Incremento del contador
            cout<<i<<endl;
            contador++;
        }
        (*ct)++; //Incremento de contador
        i++;
    }
    (*ct)++; //Conficion falsa del while
}

int main(){
    short int n;
    short int num_ordenadas;
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("Perfectos.csv","w+"); //Invocamos el archivo csv y lo asignamos a nuestro ftp
    cin>>num_ordenadas;
    for(n=1;n<=num_ordenadas;n++){
        int ct = 0;
        MostrarPerfectos(n,&ct);
        fprintf(fpt,"%d,%d \n",n,ct); //Imprimimos los resultados en el archivo csv
    }
    fclose(fpt); //Cerramos el archivo css
    return 0;
}