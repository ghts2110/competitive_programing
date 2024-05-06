#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, c;
    vector<int> p(1001, -1);

    while(cin >> n >> c){
        vector<int> v(1, 1);
        for(int i = 2; i <= n; i++){
            if(p[i] != -1){
                if(p[i] == 1){
                    v.push_back(i);
                }
                continue;
            }

            bool isP = true;
            for(int j = 2; j*j <= i; j++){
                if(i % j == 0){
                    isP = false;
                    break;
                }
            }

            p[i] = isP;
            if(isP){
                v.push_back(i);
            }
        }

        int cont = 2*c;
        cout << n << " " << c << ":";
        if(v.size() % 2 == 1){
            for(int i = max((int)v.size()/2-(c-1), 0); i != v.size()/2-(c-1)+cont-1 && i < v.size(); i++){
                cout << " " << v[i]; 
            }     
        }else{
            for(int i = max((int)v.size()/2-(c-1)-1, 0); i != v.size()/2-(c-1)+cont-1 && i < v.size(); i++){
                cout << " " << v[i]; 
            }
        }
        cout << endl;
        cout << endl;
    }
}
