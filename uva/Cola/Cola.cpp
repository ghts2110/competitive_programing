#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int asw = n;
        
        int v = n;
        n = 0;
    
        while(true){
            n = v/3;
            v %= 3;
            asw += n;
            v += n;
            n = 0;
            
            if(v/3 == 0){
                break;
            }
        }
        if(v == 2){
            asw++;
        }
        cout << asw << endl;
    }
}
