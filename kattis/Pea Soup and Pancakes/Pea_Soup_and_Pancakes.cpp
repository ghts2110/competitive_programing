#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> v;
    for(int j = 0; j != n; j++){
        int k;
        string name, s;
        cin >> k;
        getline(cin, name);
        getline(cin, name);
            
        int cont = 0, ps = 0, p = 0;
        for(int i = 0; i != k; i++){
            getline(cin, s);
            if((s == "pea soup" && ps == 0) || (s == "pancakes" && p == 0)){
                if(s == "pea soup"){
                    ps = 1;
                }else{
                    p = 1;
                }
                cont++;
            }
        }
        
        if(cont == 2){
            v.push_back(name);
        }
    }

    if(v.size() == 0){
        cout << "Anywhere is fine I guess" << endl;
    }else{
        cout << v[0] << endl;
    }
}
