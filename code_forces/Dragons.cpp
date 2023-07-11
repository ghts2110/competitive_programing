#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;

    vector<vector<int> > v(n);

    int validate = 1;
    for(int i = 0; i != n; i++){
        int x, y;
        cin >> x >> y;
        v[i].push_back(x);
        v[i].push_back(y);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i != n; i++){
        if(s > v[i][0]){
            s += v[i][1];
        }else{
            validate = 0;
        }
    }

    if(validate == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
