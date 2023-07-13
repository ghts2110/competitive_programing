#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long w, n;
        cin >> n >> w;
        
        vector<long long> v;
        long long cont = 0, value = 0;        
        
        for(int i = 0; i != n; i++){
            long long j;
            cin >> j;

            if(cont + j <= w){
                cont += j;
                v.push_back(i);
                value++;
            }else if(2*j >= w && j <= w){
                cont = j;
                v.clear();
                v.push_back(i);
                value = 1;
            }
        }

        if(2*cont >= w && cont <= w){
            cout << value << endl;
            for(int i = 0; i != v.size(); i++){
                if(i == v.size() - 1){
                    cout << v[i]+1 << endl;
                    break;
                }
                cout << v[i]+1 << " ";
            }
        }else{
            cout << -1 << endl;
        }
    }
}
