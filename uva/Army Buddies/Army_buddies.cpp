#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int s, b;
    while(cin >> s >> b){
        if(s == 0){
            break;
        }

        vector<pair<int, int> > v(s+2);
        for(int i = 0; i != s+2; i++){
            if(i != 0){
                v[i].first = i-1;
            }

            if(i != s+1){
                v[i].second = i+1;
            }
        }

        for(int i = 0; i != b; i++ ){
            int x, y;
            cin >> x >> y;

            v[v[x].first].second = v[y].second;
            v[v[y].second].first = v[x].first;

            if(v[v[y].second].first == 0){
                cout << "* ";
            }else{
                cout << v[v[y].second].first << " ";
            }

            if(v[v[x].first].second == s+1){
                cout << "*" << endl;
            }else{
                cout << v[v[x].first].second << endl;
            }
        }
        cout << "-" << endl;
    }
}