#include <iostream>

using namespace std;

bool Perfecto(int n){
    int sumaDividendos = 0;
    int dividendo;
    for(int i=1;i<n;i++){
        if((n%i)==0) {
            dividendo = i;
            sumaDividendos += dividendo;
        }
    }
   return sumaDividendos == n;
}

void MostrarPerfectos(int n){
    int contador=0;
    int i = 1;
    while(true){
        if(contador==n) break;
        if(Perfecto(i)){
            cout<<i<<endl;
            contador++;
        }
        i++;
    }
}

int main(){
    int n;
    cin>>n;
    MostrarPerfectos(n);
}