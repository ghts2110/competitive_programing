#include<iostream>
using namespace std;

int binario(int n){
    int cont=0;
    while(n>1){
        cont+=n%2;
        n/=2;
    }
    if(n==1){
        cont++;
    }

    return cont;
}

int hexadecimal(int n){
    int h[4]={1, 16, 256, 4096};

    int aux1,aux2,aux3,r,d1,d2,d3,d4;
    if(n>999){
        aux1=n/10;
        aux1*=10;
        d1=n-aux1;

        aux1/=10;
        aux2=aux1/10;
        aux2*=10;
        d2=aux1-aux2;

        aux2/=10;
        aux3=aux2/10;
        d4=aux3;
        aux3*=10;
        d3=aux2-aux3;

        r=(d4*h[3]) +(d3*h[2])+(d2*h[1])+d1;
        return r;
    }

    if(n>99){
        aux1=n/10;
        aux1*=10;
        d1=n-aux1;

        aux1/=10;
        aux2=aux1/10;
        d3=aux2;
        aux2*=10;
        d2=aux1-aux2;

        r=(d3*h[3])+(d2*h[2])+d1;
        return r;
    }

    if(n>9){
        aux1=n/10;
        d2=aux1;
        aux1*=10;
        d1=n-aux1;

        r=(d2*h[2])+d1;
        return r;
    }

    return n;
}

int main(){

    int n,num,b1,b2,h;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        b1=binario(num); //numero de 1s
        h=hexadecimal(num); //transforma hexa em decimal
        b2=binario(h);

        printf("%d %d\n",b1,b2);
    }

    return 0;
}
