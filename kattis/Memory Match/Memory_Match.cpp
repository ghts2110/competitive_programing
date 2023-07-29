#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> v(n+1);
        int k;
        cin >> k;

        for(int i = 0; i != k; i++){
            int a, b; 
            string s1, s2;
            
            cin >> a >> b >> s1 >> s2;
            if(s1 == s2){
                v[a] = v[b] = "-";
                continue;
            }
            v[a] = s1;
            v[b] = s2;
        }

        int cont = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == "" || v[i] == "-"){
                continue;
            }
            for(int j = i+1; j <= n; j++){
                if(v[i] == v[j]){
                    cont++;
                    v[i] = v[j] = "-";
                    break;
                }
            }
        }

        int conts = 0, contn = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] != "" && v[i] != "-"){
                conts++;
            }else if(v[i] == ""){
                contn++;
            }
        }
        if(conts == contn || contn == 2){
            if(contn == 2 && conts == 0){
                contn/=2;
            }
            cont += contn;
        }

        cout << cont << endl;

    }
}
