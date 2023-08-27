#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    int t;
    cin >> t;
    bitset<32> a(0), b(0), c(0), d(0), z(0), bt(2147483648);

    int test = 1;
    while(t--){
        if(test != 1){
            cout << endl;
        }
        test++;

        cin >> a >> b;
        while(b.to_ulong() < bt.to_ulong()){
            for(int i = 0; i != 2; i ++){
                for(int j = 30; j >= 0; j--){
                    if(i == 0){
                        cout << a[j]; 
                    }else{
                        if(j == 30){
                            cout << " ";
                        }
                        cout << b[j];
                    }
                }
            }
            cout << endl;

            if(b == z){
                break;
            }

            c = a ^ b;
            d = a & b;

            a = c;
            b = d<<1;
        }

        if(b.to_ulong() >= bt.to_ulong()){
            for(int j = 30; j >= 0; j--){
                cout << a[j]; 
            }
            
            cout << " overflow" << endl;
        }


    }
}
