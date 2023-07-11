#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, c;

    cin >> t >> c;

    vector <int> v(t);

    for(int i = 0; i != t; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int f = v.size() - c;

    while(1){
        if(v[f] == v[f-1]){
            f--;
            c++;
        }else{
            break;
        }
    }
    
    cout << c << endl;
}
