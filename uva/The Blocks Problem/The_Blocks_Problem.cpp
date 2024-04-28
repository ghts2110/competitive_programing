#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int n, b1, b2;
    cin >> n;
    string s1, s2;
    vector<stack<int>> v(n);
    map<int, pair<int, int>> mp;

    for(int i = 0; i != n; i++){
        v[i].push(i);
        mp[i] = {i, 0};
    }

    while(cin >> s1){
        if(s1 == "quit"){
            break;
        }

        cin >> b1 >> s2 >> b2;

        int ind1 = mp[b1].first;
        int ind2 = mp[b2].first;
        
        if(ind1 == ind2){
            continue;
        }
        if(s1 == "move" && s2 == "onto"){
            for(int i = v[ind1].size()-1; i > mp[b1].second; i--){
                int num = v[ind1].top();
                v[ind1].pop();
                mp[num].first = num;
                mp[num].second = v[num].size();
                v[num].push(num);
            }
            v[ind1].pop();

            for(int i = v[ind2].size()-1; i > mp[b2].second; i--){
                int num = v[ind2].top(); 
                v[ind2].pop();
                mp[num].first = num;
                mp[num].second = v[num].size();
                v[num].push(num);
            }

            mp[b1].first = ind2;
            mp[b1].second = v[ind2].size();
            v[ind2].push(b1);
        }else if(s1 == "move"){
            for(int i = v[ind1].size()-1; i > mp[b1].second; i--){
                int num = v[ind1].top();
                v[ind1].pop();
                mp[num].first = num;
                mp[num].second = v[num].size();
                v[num].push(num);
            }
            v[ind1].pop();
        
            mp[b1].first = ind2;
            mp[b1].second = v[ind2].size();
            v[ind2].push(b1);
        }else if(s1 == "pile" && s2 == "onto"){
            for(int i = v[ind2].size()-1; i > mp[b2].second; i--){
                int num = v[ind2].top(); 
                v[ind2].pop();
                mp[num].first = num;
                mp[num].second = v[num].size();
                v[num].push(num);
            }
    
            stack<int> save;
            for(int i = v[ind1].size()-1; i >= mp[b1].second; i--){
                int num = v[ind1].top();
                v[ind1].pop();
                save.push(num);
            }
            for(int i = save.size()-1; i != -1; i--){
                int num = save.top();
                save.pop();
                mp[num].first = ind2;
                mp[num].second = v[ind2].size();
                v[ind2].push(num);
            }
        }else{
            stack<int> save;
            for(int i = v[ind1].size()-1; i >= mp[b1].second; i--){
                int num = v[ind1].top();
                v[ind1].pop();
                save.push(num);
            }
            for(int i = save.size()-1; i != -1; i--){
                int num = save.top();
                save.pop();
                mp[num].first = ind2;
                mp[num].second = v[ind2].size();
                v[ind2].push(num);
            }
        }
    }

    for(int i = 0; i != v.size(); i++){
        cout << i << ":";
        stack<int> save;
        while(!v[i].empty()){
            save.push(v[i].top());
            v[i].pop();
        }
        while(!save.empty()){
            cout << " " << save.top();
            save.pop();
        }
        cout << endl;
    }
}
