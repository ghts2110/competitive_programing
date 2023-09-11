#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        int n;
        vector<vector<int> > v(3);
        map<int, int> mp;

        for(int i = 0; i != 3; i++){
            cin >> n;
            set<int> st;

            for(int j = 0; j != n; j++){
                int num;
                cin >> num;

                st.insert(num);
                v[i].push_back(num);
            }

            for(auto it :st){
                mp[it]++;
            }
        }

        vector<set<int> > asw(3);
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != v[i].size(); j++){
                if(mp[v[i][j]] == 1){
                    asw[i].insert(v[i][j]);
                }
            }
        }

        vector<int> index;
        int mx = 0;
        for(int i = 0; i != 3; i++){
            if(mx < asw[i].size()){
                index.clear();

                mx = asw[i].size();
                index.push_back(i+1);
            }else if(mx == asw[i].size()){
                index.push_back(i+1);
            }
        }

        cout << "Case #"<<test<<":" << endl;
        for(int ndx : index){

            if(mx == 0){
                cout << ndx << " " << mx << endl;
                continue;
            }
            cout << ndx << " " << mx << " ";


            vector<int> prt;
            for(auto it : asw[ndx-1]){
                prt.push_back(it);
            }

            for(int i = 0 ; i != prt.size(); i++){
                if(i == prt.size()-1){
                    cout << prt[i] << endl;
                    break;
                }
                cout << prt[i] << " ";
            }
        }



    }
}
