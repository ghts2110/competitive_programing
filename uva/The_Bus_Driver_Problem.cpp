#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define pb push_back

using namespace std;

int main(){
    int n, d, r;

    while(1){
        cin >> n >> d >> r;

        if(n == 0){
            break;
        }

        vector<int> dia;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
        
            dia.pb(num);
        }

        vector<int> noite;
        for(int i = 0; i != n; i++){
            int num; 
            cin >> num;

            noite.pb(num);
        }
    
        sort(dia.begin(), dia.end());
        sort(noite.begin(), noite.end());
        
        int cont = 0;
        for(int i = 0; i != n; i++){
            if(dia[i] + noite[n-1 - i] - d > 0){
                cont += (dia[i] + noite[n-1 - i] - d) * r;
            }
        }

        cout << cont << endl;
    }
}
