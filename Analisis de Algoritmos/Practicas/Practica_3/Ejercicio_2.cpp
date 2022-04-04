#include <iostream>
#include <math.h>
using namespace std;
int busqueda_Recursiva(int inicio,int final,int n, int array[]){
    int i = inicio + ((final-inicio)/3);
    int j = inicio + (2 * ((final - inicio)/3));
    if(inicio > final){
        return -1;
    }
    else if(array[inicio] < n  && n < array[i]){
        return busqueda_Recursiva(inicio,i,n,array);
    }
    else if(array[i] < n && n < array[j]){
        return busqueda_Recursiva(i,j,n,array);
    }
    else if(array[j] < n && n < array[final]){
        return busqueda_Recursiva(j,final,n,array);
    }
    else if(array[inicio] == n){
        return inicio;
    }
    else if(array[final] == n){
        return final;
    }
    else if(array[i]==n){
        return i;
    }
    else if(array[j]==n){
        return j;
    }
    return -2;
}
int busqueda_Iterativa(int array[],int tam,int n){
    int inicio = 0;
    int final = tam;
    int i;
    int j;
    while(true){
        i = inicio + ((final-inicio)/3);
        j = inicio + (2 * ((final - inicio)/3));
        if(inicio > final){
            return -1;
        }
        else if(array[i] < n && n < array[j]){
            final = i;
        }
        else if(array[i] < n && n < array[j]){
            inicio = i;
            final = j;
        }
        else if(array[j] < n && n < array[final]){
            inicio = j;
        }
         else if(array[inicio] == n){
            return inicio;
        }
        else if(array[final] == n){
            return final;
        }
        else if(array[i]==n){
            return i;
        }
        else if(array[j]==n){
            return j;
        }
        else
            break;
    }
    return -2;
}
int main(){
    int array[12];
    int elemento;
    for(int i = 0;i<12;i++)
        array[i] = i+1;
    cout<<"Ingresa el elemento a buscar:";
    cin>>elemento;
    cout<<"El elemento esta en "<<endl<<busqueda_Iterativa(array,11,elemento)<<endl;
}