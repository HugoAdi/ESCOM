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
PROFESOR: Luna Benoso Benjamín
FECHA: 25/Febrero/2022
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
    free(*array);
    *array = malloc(n * sizeof(int));
    srand((unsigned)time(&t));
    for(i=0;i<n;i++){
        (*array)[i] = rand() % ((3*n)+1);
    }
}

void generarArreglo_peorCaso(int **array,int n){
    int i,j;
    free(*array);
    *array = malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        (*array)[i]=i;
        /*
        if(i<((n/2)-1)){
            (*array)[i] = i+1;
        }
        else if(i==((n/2)-1)){
            (*array)[i] = 0;
        }
        else if(i>=(n/2) && i<=(n-1)){
            (*array)[i] = i; 
        }
        else if(i==n){
            (*array)[i] = 0;
        }*/
    }
}

void generarArreglo_mejorCaso(int **array,int n){
    int i,j;
    free(*array);
    *array = malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        if(i==0)
            (*array)[i] = -1;
        else if(i==(n/2))
            (*array)[i] = -1;
        else
            (*array)[i] = i;
    }
}

void imprimirArreglo(int *array,int n){
    int j, aux;
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
    int num_ordendas = 800;
    array = NULL;
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("posteriori.csv","w+");
    for(k=0;k<num_ordendas;k++){
        int ct = 0;
        generarArreglo_Random(&array,k);
        imprimirArreglo(array,k);
        printf("Se encontro %d\n",encontrarNumeros(array,k,&ct));
        fprintf(fpt,"%d,%d \n",k,ct);
    }
    fclose(fpt);   
    return 0;
}