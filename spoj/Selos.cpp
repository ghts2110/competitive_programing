#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long t;
    cin >> t;
    
    if(t < 4){
        cout << "N" << endl;
        return 0;
    }else if(t % 2 == 0){
        cout << "S" << endl;
        return 0;
    }

    for(int i = 3; i < sqrt(t); i+=2){
        if(t % i == 0){
            cout << "S" << endl;
            return 0;
        }
    }
    
    cout << "N" << endl;

}
