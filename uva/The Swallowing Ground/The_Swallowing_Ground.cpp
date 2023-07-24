#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t; 

    while(t--){
        int a, b, n;
        cin >> n;
        cin >> a >> b;

        n--;
        int dif = abs(a - b);    

        bool validate = true;
        while(n--){
            cin >> a >> b;
            if(dif != abs(a-b)){
                validate = false;
            }
        }

        if(validate){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        if(t != 0){
            cout << endl;
        }
    }
}
