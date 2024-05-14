#include <iostream>
#include <string>

using namespace std;

bool ispali(long long n){
    string s = to_string(n);
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]){
            return false;
        }
    }

    return true;
}

long long swp(long long n){
    string s = to_string(n);
    string save = "";

    for(auto it : s){
        save = it + save;
    }

    return stoll(save);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n; 
        cin >> n;

        int cont = 0;
        while(!ispali(n) || !cont){
            cont++;
            n += swp(n);
        }

        cout << cont << " " << n << endl;
    }
}
