#include <iostream>

using namespace std;

int main(){
    int t;
    int cont = 1;
    while(1){
        cin >> t;
        if(t == 0){
            break;
        }

        cout << "Case "<<cont<<": ";
        cont++;

        int a = 0, b = 0;
        for(int i = 0; i != t; i++){
            int num;
            cin >> num;

            if(num == 0){
                a++;
            }else{
                b++;
            }
        }

        cout << b - a << endl;
    }
}
