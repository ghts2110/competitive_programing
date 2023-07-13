#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int cont = 0;
    for(int i = 1; i != n; i++){
        if(v[i] == v[i-1]){
            cont++;
            if(v[i] == 0){
                cout << "cslnb" << endl;
                return 0;
            }
        }
        
    }

    if(cont >= 2){
        cout << "cslnb" << endl;
        return 0;
    }else if(cont == 1){
        for(int i = 1; i != n; i++){
            if(v[i] == v[i-1]){
                v[i-1]--;
                break;
            }
        }

        for(int i = 1; i != n; i++){
            if(v[i] == v[i-1]){
                cout << "cslnb" << endl;
                return 0;
            }
        }
    }

    int mn = 0;
    for(int i = 0; i != n; i++){
        cont += v[i] - mn;
        v[i] = mn;
        mn++;
    }

    if(cont % 2 == 0){
        cout << "cslnb" << endl;
    }else{
        cout << "sjfnb" << endl;
    }
}
