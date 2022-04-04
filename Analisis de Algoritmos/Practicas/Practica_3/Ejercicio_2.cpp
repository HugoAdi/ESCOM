#include <iostream>
#include <math.h>
using namespace std;
int busqueda(int inicio,int final,int n, int array[]){
    int i = inicio + ((final-inicio)/3);
    int j = inicio + (2 * ((final - inicio)/3));
    if(inicio > final){
        return -1;
    }
    else if(array[inicio] < n  && n < array[i]){
        return busqueda(inicio,i,n,array);
    }
    else if(array[i] < n && n < array[j]){
        return busqueda(i,j,n,array);
    }
    else if(array[j] < n && n < array[final]){
        return busqueda(j,final,n,array);
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
    return 0;
}
int main(){
    int array[12];
    int elemento;
    for(int i = 0;i<12;i++)
        array[i] = i+1;
    cout<<"Ingresa el elemento a buscar:";
    cin>>elemento;
    cout<<"El elemento esta en "<<endl<<busqueda(0,11,elemento,array)<<endl;
}