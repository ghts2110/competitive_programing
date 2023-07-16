#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;

    vector<int>v(100);
    while(true){
        cin >> s;
        if(s == "0"){
            break;
        }

        int start = 100 - s.size();
        int index = 0;
        for(int i = start; i < 100; i++){
            v[i] += s[index] - '0';
            index++;
        }
    }

    for(int i = 99; i > 0; i--){
        if(v[i] > 9){
            v[i - 1] += v[i] / 10;
            v[i] %= 10;
        }
    }

    int cont = 0;
    for(int i = 0; i < 100; i++){
        if(v[i] != 0 || cont == 1){
            if(i == 99){
                cout << v[i] << endl;
                break;
                
            }
            cout << v[i];
            cont = 1;
        }
    }
}
