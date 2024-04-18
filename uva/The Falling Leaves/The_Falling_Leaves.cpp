#include <iostream>
#include <map>

using namespace std;
map<int, int> mp;

void dfs(int n, int d){
    mp[d] += n;
    int l, r;
    cin >> l;
    if(l != -1){
        dfs(l, d-1);
    }
    cin >> r;
    if(r != -1){
        dfs(r, d+1);
    }
}
int main(){
    int n;
    int test = 1;
    while(cin >> n){
        if(n==-1){
            break;
        }

        cout << "Case "<<test<<":" << endl;
        test++;

        mp.clear();
        
        dfs(n, 0);

        bool f= true;
        for(auto it: mp){
            if(!f){
                cout << " ";
            }
            f = false;
            cout << it.second;
        }
        cout << endl << endl;
    }
}
