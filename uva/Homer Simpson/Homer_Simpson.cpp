#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my(pair<int, int> i, pair<int, int> j){
    if(i.second < j.second){
        return true;
    }else if(i.second == j.second){
        return i.first > j.first;
    }

    return false;
}

int main(){
    int n, m, t;
    while(cin >> m >> n >> t){
        int i = t/m;

        int mx =0, time=0, cont= 0;
        vector<pair<int, int> > v;
        while(i != -1){
            if((t-(i*m))%n == 0){
                mx = max(mx, i+(t-(i*m))/n);
            }
            v.push_back(make_pair(i+(t-(i*m))/n, (t-(i*m))%n));

            i--;
        }

        if(mx != 0){
            cout << mx << endl;
        }else{
            sort(v.begin(), v.end(), my);
            cout << v[0].first << " " << v[0].second << endl;
        }


    }
}
