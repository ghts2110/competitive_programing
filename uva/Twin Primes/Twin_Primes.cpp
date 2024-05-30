#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<bool> v(20000001, true);
    for(int i = 2; i*i <= 20000000; i++){
        if(v[i]){
            for(int j = i*i; j <= 20000000; j+=i){
                v[j]=false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i != v.size(); i++){
        if(v[i]){
            prime.push_back(i);
        }
    }
    
    vector<pair<int, int>>asw;
    for(int i = 0; i != prime.size()-1; i++){
        if(prime[i+1]-prime[i] == 2){
            asw.push_back({prime[i], prime[i+1]});
        }
    }

    while(cin >> n){
        n--;
        cout << "("<<asw[n].first<<", "<<asw[n].second<<")" << endl;
    }
}
