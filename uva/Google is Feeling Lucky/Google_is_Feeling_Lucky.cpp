#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        string s;
        int n, mx = 0;
        vector<string> v;

        for(int i = 0; i != 10; i++){
            cin >> s >> n;
            
            if(mx < n){
                mx = n;
                v.clear();
                v.pb(s);
            }else if(mx == n){
                v.pb(s);
            }
        }
    
        cout << "Case #"<<cont<<":" << endl;
        cont++;
        for(int i = 0; i != v.size(); i++){
            cout << v[i] << endl;
        }
    }
}
