#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s1, s2;
    cin >> s1 >> s2;

    int contA = 0, contB = 0;
    for(int i = 0; i != t; i++){
        if(s1[i] == 'a'){
            contA++;
        }else{
            contB++;
        }
        if(s2[i] == 'a'){
            contA++;
        }else{
            contB++;
        }
    }

    if(contA % 2 == 1 || contB % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    deque<int> dq;
    vector<vector<int> > v(t);

    int cont = 0, index = 0;
    for(int i = 0; i != t; i++){
        if(s1[i] != s2[i]){
            dq.push_back(i);
            for(int j = i+1; j != t && dq.size() != 2; j++){
                if(s1[i] == s1[j] && s2[i] == s2[j]){
                    dq.push_back(j);
                }
            }
        }

        if(dq.size() == 2){
            if(s1[dq.front()] == s1[dq.back()]){
                cont++;
                v[index].push_back(dq.back());
                v[index].push_back(dq.front());
                
                s1[dq.front()] = s2[dq.front()];
                s1[dq.back()] = s2[dq.back()];
                
                index++;
                dq.clear();
            }else{
                cont += 2;
                v[index].push_back(dq.back());
                v[index].push_back(dq.back());
            
                index++;
                v[index].push_back(dq.back());
                v[index].push_back(dq.front());
                
                s1[dq.front()] = s2[dq.front()];
                s1[dq.back()] = s2[dq.back()];

                index++;
                dq.clear();
            }
        }
    }

    cout << cont << endl;
    for(int i = 0; i != index; i++){
        cout << v[i][0]+1 << " " << v[i][1]+1 << endl;
    }
}
