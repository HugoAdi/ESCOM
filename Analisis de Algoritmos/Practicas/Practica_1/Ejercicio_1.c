#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
Análisis de Algoritmos
GRUPO: 3CV12
ALUMNOS:
    Jimenez Martinez Hugo Adi
    Castillo González Bruno
PROFESOR: Luna Benoso Benjamín
FECHA: 28/Febrero/2022
*/

int encontrarNumeros(int *array,int n,int *ct){
    int i,j;
    (*ct)++; //Declaracion i
    (*ct)++; //Declaracion j
    (*ct)++; //Asignacion i = 0
    for(i=0;i<(n/2);i++){
        (*ct)++; //Comparacion dentro del if
        (*ct)++; //Asignacion j = n/2
        for(j=(n/2);j<n;j++){
            (*ct)++; //Comparacion deltro del if
            if(array[i] == array[j]) {
                (*ct)++; //Operacion de if
                (*ct)++; //Return array
                return array[i];
            }
            (*ct)++; //Operacion del if
            (*ct)++; //incremento de j
        }
        (*ct)++; //Condicion donde no entra el for
        (*ct)++; //Incremento de i
    }
    (*ct)++; //Condicion donde no entra el for
    (*ct)++; //Return 0
    return 0;
}

void generarArreglo_Random(int **array,int n){
    time_t t;
    int i;
    free(*array); //Liberamos memoria
    *array = malloc(n * sizeof(int)); //asignamos
    srand((unsigned)time(&t)); //inicializamos random
    for(i=0;i<n;i++){
        (*array)[i] = rand() % ((3*n)+1); //asignamos valores aleatorios
    }
}

void generarArreglo_peorCaso(int **array,int n){
    int i,j;//Inicializamos variables
    free(*array); //Liberamos memoria
    *array = malloc(n * sizeof(int)); //asignamos
    for(i=0;i<n;i++){
        (*array)[i]=i; //Asignamos el contador del for a cada elemento del arreglo
    }
}

void generarArreglo_mejorCaso(int **array,int n){
    int i,j; //Inicializamos variables
    free(*array); //Liberamos memoria
    *array = malloc(n * sizeof(int)); //asignamos
    for(i=0;i<n;i++){
        if(i==0) //Asignamos el valor -1 al primer elemento de la primera mitad del arreglo
            (*array)[i] = -1;
        else if(i==(n/2)) //Asignamos el valor -1 al primer elemento de la segunda mitad del arreglo
            (*array)[i] = -1;
        else //Para los demas elementos, asignamos el contador a cada elemento
            (*array)[i] = i;
    }
}

void imprimirArreglo(int *array,int n){
    int j, aux; //Inicializamos variables
    printf("Arr = {");
    for(j=0;j<n;j++) {
        aux = array[j];
        printf("%d,",aux);
    }
    printf("}\n");
}
int main(){
    int *array;
    int k;
    int num_ordendas = 800; //Inicializamos variables
    array = NULL; //Apuntamos a Nulo
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("posteriori.csv","w+"); //Invocamos el archivo csv y lo asignamos a nuestro ftp
    for(k=0;k<num_ordendas;k++){
        int ct = 0;
        //generarArreglo_Random(&array,k); //Generamos nuestro arreglo con elementos aleatorios
        //generarArreglo_mejorCaso(&array,k); //Generamos nuestro arreglo basandonos en el mejor caso del algoritmo
        generarArreglo_peorCaso(&array,k); //Generamos nuestro arreglo basandonos en el peor caso del algoritmo
        imprimirArreglo(array,k); //Imprimimos el arreglo
        printf("Se encontro %d\n",encontrarNumeros(array,k,&ct)); //Ejectuamos el algoritmo de busqueda
        fprintf(fpt,"%d,%d \n",k,ct); //Imprimimos los resultados en el archivo csv
    }
    fclose(fpt);   //Cerramos el archivo css
    return 0;
}
