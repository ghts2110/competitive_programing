#include <iostream>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
    
        int sum;
        if(n % 2 == 1){
            sum = ((n/2) * (n+1)) + (n/2 + 1);
        }else{
            sum = (n/2) * (n+1);
        }

        int cont = 0;
        
        for(int i = 0; i != n; i++){
            cont += sum - i;
            sum -= i;
        }

        cout << cont << endl;
    }
}
