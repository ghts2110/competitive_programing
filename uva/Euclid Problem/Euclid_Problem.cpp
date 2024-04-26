#include<iostream>
using namespace std;


int euc(int a,int b, int *x, int *y){
    if(a == 0){
        *x = 0; 
        *y = 1;
        return b;
    }

    int x1,y1;
    int g = euc(b%a,a, &x1,&y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
    
    return g;
}

int main(){


    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        if(a == 0){
            cout << "0 1 " << b << endl;
            continue;
        }

        if(b == 0){
            cout << "1 0 " << a << endl;
            continue;
        }
        
        if(a == b){
            cout << "0 1 " << b << endl;
            continue;
        }
        int x,y;
        int g = euc(a,b,&x,&y);
        cout << x << " " << y << " " << g << endl;
    } 

    return 0;
}
