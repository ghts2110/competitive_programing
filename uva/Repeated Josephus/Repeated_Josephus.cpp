#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        cout << "Case "<<test <<": ";
        int n;
        cin >> n;

        int cont = -1;
        while(1){
            cont++;
            vector<int> v;
            for(int i = 0; i < n-1; i++){
                v.push_back(i+1);
            }
            v.push_back(0);

            int index = 0;
            while(1){
                if(v[index] == v[v[index]]){
                    break;
                }
                v[index] = v[v[index]];
                index = v[index];
            }

            if(v[index]+1 == n){
                cout << cont << " " << v[index]+1 << endl;
                break;
            }else{
                n = v[index] + 1;
            }
        }

    }
}