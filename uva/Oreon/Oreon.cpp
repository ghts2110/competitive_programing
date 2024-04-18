#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool my(pair<pair<char, char>, int> p1, pair<pair<char, char>, int> p2){
    if(p1.second < p2.second){
        return true;
    }else if(p1.second > p2.second){
        return false;
    }

    if(p1.first.first < p2.first.first){
        return true;
    }else if(p1.first.first > p2.first.first){
        return false;
    }

    if(p1.first.second < p2.first.second){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        cout << "Case "<<test<<":" << endl;
        test++;

        int n;
        cin >> n;

        set<pair<int, pair<int, int>>> st;
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                int num;
                char c;

                if(j){
                    cin >> c;
                }

                cin >> num;
                if(!num){
                    continue;
                }

                if(!i){
                    st.insert({num, {i, j}});
                }else{
                    adj[i].push_back({j, num});
                }
            }
        }

        vector<bool> visit(n);
        vector<pair<pair<char, char>, int>> asw;
        while(!st.empty()){
            int no1 = (*st.begin()).second.first;
            int no2 = (*st.begin()).second.second;
            int val = (*st.begin()).first;
        
            st.erase(st.begin());
            if(visit[no1] && visit[no2]){
                continue;
            }
            visit[no1] = visit[no2] = true;
            for(auto it : adj[no2]){
                st.insert({it.second, {no2, it.first}});
            }
            if(no1 > no2){
                swap(no1, no2);
            }
            asw.push_back({{char(no1+'A'), char(no2+'A')}, val});
        }

        sort(asw.begin(), asw.end(), my);

        for(auto it : asw){
            cout << it.first.first << "-" << it.first.second << " " << it.second << endl;
        }   
    }
}
