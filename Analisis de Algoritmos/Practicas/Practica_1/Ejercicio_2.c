#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int MCD(int a, int b){
    int aux;
    while(b != 0){
        aux = b;
        b=a % b;
        a= aux;
    }
    return a;
}

int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    int num_ordenadas, i;
    num_ordenadas = 10;
    for(i=0;i<num_ordenadas;i++){
        MCD(fib(i),fib(i+1));
    }
    return 0;
}