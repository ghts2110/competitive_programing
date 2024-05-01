#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void swp(vector<int> &v, int ind){
    stack<int> save;
    for(int i = 0; i != ind; i++){
        save.push(v[i]);
    }   

    int cont = 0;
    while(!save.empty()){
        v[cont] = save.top();
        cont++;
        save.pop();
    }
}

int main(){
    string s;
    while(getline(cin, s)){
        if(s == ""){
            break;
        }
        vector<int> v, st;
        
        string save = "";
        for(int i = 0; i != s.size(); i++){
            if(s[i] != ' '){
                save += s[i];
            }

            if(s[i] == ' ' || i == s.size()-1){
                v.push_back(stoi(save));
                st.push_back(stoi(save));
                save = "";
            }
        }
        cout << s << endl;
        
        sort(st.begin(), st.end());

        for(int i = st.size()-1; i != -1; i--){
            if(st[i] == v[i]){
                continue;
            }

            int ind = 0;
            for(int j = 0; j != v.size(); j++){
                if(v[j] == st[i]){
                    ind = j;
                    break;
                }
            }
    
            if(ind != 0){
                cout << v.size()-ind << " ";
                swp(v, ind+1);
            }
            cout << st.size()-i << " ";
            swp(v, i+1);
        }

        cout << 0 << endl;
    }
}
