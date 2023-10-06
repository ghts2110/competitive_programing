#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    while(true){
        int n, m;
        cin >> n >> m;

        if(!n && !m){
            break;
        }

        vector<int> dd, dc;
        for(int i = 0;i != n; i++){
            int num;
            cin >> num;

            dd.push_back(num);
        }

        for(int i = 0; i != m; i++){
            int num;
            cin >> num;

            dc.push_back(num);
        }

        sort(dd.begin(), dd.end());
        sort(dc.begin(), dc.end());

        int asw = 0;
        for(auto it : dd){
            if(asw == -1){
                break;
            }
            bool val = true;
            for(int i = 0; i != dc.size(); i++){
                if(dc[i] >= it){
                    asw += dc[i];
                    val = false;
                    dc.erase(dc.begin());
                    break;
                }else{
                    dc.erase(dc.begin());
                    i--;
                }
            }

            if(val) {
                asw = -1;
            }
        }

        if(asw == -1){
            cout << "Loowater is doomed!" << endl;
        }else{
            cout << asw << endl;
        }
    }
}