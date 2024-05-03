#include <iostream>
#include <vector>

using namespace std;

bool ll(int m, vector<int> v, int n){
    int ind = 0;
    while(true){
        if(*(v.begin()+ind) == 13){
            break;
        }
        v.erase(v.begin()+ind);
        ind = (ind+m-1)%v.size();
    }

    return v.size() == 1;
}

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }
        vector<int> v(n);
        for(int i = 0; i != v.size(); i++){
            v[i] = i+1;
        }

        for(int i = 1; i != 1000; i++){
            if(ll(i, v, n)){
                cout << i << endl;
                break;
            }
        }
    }
}
