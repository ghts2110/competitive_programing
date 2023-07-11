#include <iostream>

using namespace std;

int main(){
    int v, n, i, value;
    cin >> v >> n;
    
    for(i = 1; i != 10; i++){
        value = v*n*i;

        if(value % 10 != 0){
            cout << value/10 + 1;
        }else{
            cout << value/10;
        }

        if(i != 9){
            cout << " ";
        }
    }
    cout << endl;
}
