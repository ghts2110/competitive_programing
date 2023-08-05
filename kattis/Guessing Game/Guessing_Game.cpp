#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int num;
    int mn = 0, mx = 11;
    string s;
    
    while(cin >> num >> s >> s){
        if(num == 0){
            break;
        }

        if(s == "high"){
            if(num <= mn){
                mx = 0;
            }

            mx = min(num, mx);
        }else if(s == "low"){
            if(num >= mx){
                mn = 11;
            }
            mn = max(num, mn);
        }else{
            if(num > mn && num < mx){
                cout << "Stan may be honest" << endl;
            }else{
                cout << "Stan is dishonest" << endl;
            }
            mn = 0, mx = 11;
        }
    }
}
