#include <iostream>

using namespace std;

int main(){
    int n;
    int test = 1;
    while(cin >> n){
        if(n <= 0){
            break;
        }

        int cont = 0;
        int p = 1;
        while(p < n){
            p *= 2;
            cont++;
        }

        cout << "Case "<<test<<": "<<cont<<endl;
        test++;
    }
}
