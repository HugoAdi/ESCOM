#include <iostream>

using namespace std;

int Division1(int n, int div, int res, int *ct){
    int q = 0; (*ct)++;
    while (n >= div){
        (*ct)++; //Comparativa verdadera del while
        n=n-div; (*ct)++;
        q=q+1; (*ct)++;
    }
    (*ct)++; //Comparativa falsa del while
    res = n; (*ct)++; 
    (*ct)++;
    return q;
}

int Division2(int n,int div,int res, int *ct){
    int dd = div; (*ct)++;
    int q = 0; (*ct)++;
    int r = n; (*ct)++;
    while (dd <= n){
        (*ct)++; //Comparativa verdadera del while
        dd = dd/2; (*ct)++;
        q = 2*q; (*ct)++;
        (*ct)++;
        if(dd <=r ){
            r = r-dd; (*ct)++;
            q = q+1; (*ct)++;
        }
        (*ct)++;
    }
    (*ct)++; //Comparativa falsa del while
    (*ct)++;
    return q;
}

int Division3(int n, int div,int *ct){
    if(div > n){
        (*ct)++; //Comparativa verdadera del if
        (*ct)++; //Return 0
        return 0;
    }
    else{
        (*ct)++; //Comparativa falsa del if
        (*ct)++; //Recursividad
        return 1+Division3(n-div,div,ct);
    }
}

int main(){
    int num_Ordenadas;
    cin>>num_Ordenadas;
    FILE *fpt; //Puntero del archivo csv
    fpt = fopen("Fibonacci.csv","w+"); //Invocamos el archivo csv y lo asignamos a nuestro ftp
    for(int i=1;i<num_Ordenadas;i++){
        int ct=0;
        Division3(i,&ct);
        fprintf(fpt,"%d,%d \n",i,ct); //Imprimimos los resultados en el archivo csv
    }
    fclose(fpt); //Cerramos el archivo css
    return 0;
}