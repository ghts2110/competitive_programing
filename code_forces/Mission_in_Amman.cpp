#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    map<int, int> mp;
    vector<int> v(m+1);
    int cont = 0;

    for(int i = 0; i != n; i++){
        int num;
        cin >> num;
        
        mp[i+1] = num;
    
        if(v[num] == 0){
            cont++;
        }

        v[num]++;
    }

    for(int i = 0; i != q; i++){
        int a, b;
        cin >> a >> b;

        v[mp[a]]--;
        
        if(v[mp[a]] == 0){
            cont--;
        }

        mp[a] = b;
        
        if(v[mp[a]] == 0){
            cont++;
        }

        v[mp[a]]++;

        cout << m - cont << endl;
    }
}
