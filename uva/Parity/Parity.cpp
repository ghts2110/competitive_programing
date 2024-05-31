#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        int asw = 0;
        for(int i = 0; i != 32; i ++){
            if(n & (1<<i)){
                asw++;
            }
        }
        
        string s = "";
        while(n != 0){
            s = to_string(n%2) + s;
            n/=2;
        }
        
        cout << "The parity of "<<s<<" is "<<asw<<" (mod 2)." << endl;
    }
}
