#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    int q;
    cin >> q;
    for(int i = 0; i != q; i++){
        int num;
        cin >> num;

        int ind = upper_bound(v.begin(), v.end(), num) - v.begin();
        pair<string, string> asw;
        if(ind != v.size()){
            asw.second = to_string(v[ind]);
        }else{
            asw.second = "X";
        }

        ind--;
        while(ind != -1 && v[ind] == num){
            ind--;
        }
    
        if(ind != -1){
            asw.first = to_string(v[ind]);
        }else{
            asw.first = "X";
        }

        cout << asw.first << " " << asw.second << endl;
    }
}
