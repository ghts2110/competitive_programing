#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m, cont0 = 0, cont1 = 0;
        cin >> n >> m;
        string s;

        for(int i = 0; i != n; i++){
            cin >> s;  
            for(int j = 0; j != m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && s[j] == '0'){
                    cont0++;
                }else if(i != 0 && i != n-1 && j != 0 && j != m-1 && s[j] == '1'){
                    cont1++;
                }
            }
        }

        if(cont0 > cont1){
            cout << -1 << endl;
        }else{
            cout << cont0 << endl;
        }
    }
}
