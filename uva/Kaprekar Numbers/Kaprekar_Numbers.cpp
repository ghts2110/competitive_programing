#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> v(40001, false);

void solution(){
    for(int i = 2; i <= 40000; i++){
        long long l = i*i;
        int l1 = 1, l2 = 1;
        int limit = to_string(l).size();

        for(; l1 != limit; l1++, l2++){
            int pw1 = 1, pw2 = 1;
            for(int j = 0; j != l1; j++){
                pw1*=10;
            }
            for(int j = 0; j != l2; j++){
                pw2*=10;
            }

            int n1 = l/pw1;
            int n2 = l%pw2;

            if(n1 + n2 == i && n1 && n2){
                v[i] = true;
                break;
            }
        }
    }
}

int main(){
    solution();
    int n;
    cin >> n;

    for(int test = 1; test <= n; test++){
        int i, s;
        cin >> i >> s;
        vector<int> asw;
        for(int j = i; j <= s; j++){
            if(v[j]){
                asw.push_back(j);
            }
        }

        if(test != 1){
            cout << endl;
        }
        cout << "case #"<<test << endl;
        if(asw.empty()){
            cout << "no kaprekar numbers" << endl;
            continue;
        }

        for(auto it : asw){
            cout << it << endl;
        }
    }
}