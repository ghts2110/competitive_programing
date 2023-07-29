#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;

    while(cin >> n >> s){
        vector<int> v;
        int cont = 0; 
        
        if(s == "out" && n % 2 == 0){
            n -= 2;
        }else if(n % 2 == 1){
            n--;
        }
       
        if(n <= 1){
            cout << 1 << endl;
            continue;
        }

        for(int i = 0; i != n; i++){
            v.push_back(i+1);
        }
    
        vector<int> nw(n);
        while(1){
            cont++;
            int index = 0;
            for(int i = 1; i <= n-1; i+=2){
                nw[i] = v[index];
                index++;
            }

            for(int i = 0; i <= n-2; i+=2){
                nw[i] = v[index];
                index++;
            }

            v = nw;

            if(v[0] == 1){
                break;
            }
        }

        cout << cont << endl;
    }
}
