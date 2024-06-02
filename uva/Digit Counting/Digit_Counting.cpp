#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
    
        string s = "";
        for(int i = 1; i <= n; i++){
            s += to_string(i);
        }
    
        vector<int> v(10);
        for(auto it:s){
            v[it-'0']++;  
        }

        for(int i = 0; i != 10; i++){
            if(i != 0){
                cout << " ";
            }
            cout << v[i];
        }

        cout << endl;
    }
}
