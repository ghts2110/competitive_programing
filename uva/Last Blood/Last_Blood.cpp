#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    int n, t, m;
    cin >> n >> t >> m;

    vector<vector<bool> > val(t+1, vector<bool> (n, false));
    vector<pair<int, int> > v(n, make_pair(-1, -1));

    for(int i = 0; i != m; i++){
        int time, id;
        char q;
        string asw;
        cin >> time >> id >> q >> asw;

        if(asw == "Yes"){
            if(!val[id][q-'A']){
                val[id][q-'A'] = true;
                v[q-'A'] = make_pair(time, id);
            }
        }
    }

    for(int i = 0; i != n; i++){
        cout << char('A'+i) << " ";

        if(v[i].first == -1){
            cout << "- -" << endl;
        }else{
            cout << v[i].first << " " << v[i].second << endl;
        }

    }
}
